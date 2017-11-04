#include "stdafx.h"
#include "CefClientBrowser.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"
//#include "include/cef_sandbox_win.h"
#include "include/cef_app.h"
#include "browser\client_handler.h"
#include "shared/common/client_app.h"
#include "shared/browser/client_app_browser.h"
#include "shared/renderer/client_app_renderer.h"
#include "shared/common/client_app_other.h"
#include "browser\browser_window_osr_win.h"
#include "browser\client_handler_std.h"
#include "CefContext.h"

#pragma comment(lib, "Dbghelp")
#pragma comment(lib, "Psapi")	
#pragma comment(lib, "Winmm")
#pragma comment(lib, "opengl32")
#pragma comment(lib, "Imm32")

CefClientBrowser::CefClientBrowser() : m_hWnd(NULL), m_clientHandler(NULL), m_browser(NULL),
m_strUserAgent("Mozilla/5.0 (Windows NT 6.1;WOW64)AppleWebKit/537.22(KHTML,like Gecko) Chrome/25.0.1364.152 Safari/537.22")
{
	CefSettingsTraits::init(&m_cefSetting);
}


CefClientBrowser::~CefClientBrowser()
{
}
void CefClientBrowser::SetCookies(const std::string & name, const std::string & domain,
	const std::string & value, const std::string & path/* = "/"*/){
	CefCookie cookie;
	CefString(&cookie.name) = name;
	CefString(&cookie.value) = value;
	CefString(&cookie.domain) = domain;
	CefString(&cookie.path) = path;
	CefRefPtr<CefCookieManager> manager = CefCookieManager::GetGlobalManager(NULL);
	if (manager)
		manager->SetCookie(m_url, cookie, NULL);

}
void CefClientBrowser::WebInit()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	//初始化cefsetting
	
	void* sandbox_info = NULL;

	/*if (m_bEnableSandBox){
	CefScopedSandboxInfo scoped_sandbox;
	sandbox_info = scoped_sandbox.sandbox_info();
	m_cefSetting.no_sandbox = false;
	}
	else{
	m_cefSetting.no_sandbox = true;
	}*/
	
	CefString(&m_cefSetting.user_agent) = m_strUserAgent;
	m_cefSetting.multi_threaded_message_loop = true;		//使用主程序消息循环
	m_cefSetting.single_process = false;					//使用多进程模式
	m_cefSetting.ignore_certificate_errors = true;		//忽略掉ssl证书验证错误
	//m_cefSetting.command_line_args_disabled = true;
	m_cefSetting.no_sandbox = true;
	CefString(&m_cefSetting.locale).FromASCII("zh-CN");

	
	//子进程
	const std::string & agent_path = CefContext::GetInstance()->GetAgentPath();
	cef_string_from_ascii(agent_path.c_str(), agent_path.length(), &m_cefSetting.browser_subprocess_path);


	CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
	command_line->InitFromString(::GetCommandLineW());

	// Create a ClientApp of the correct type.
	CefRefPtr<CefApp> app;
	client::ClientApp::ProcessType process_type = client::ClientApp::GetProcessType(command_line);
	if (process_type == client::ClientApp::BrowserProcess)
		app = new client::ClientAppBrowser();
	else if (process_type == client::ClientApp::RendererProcess)
		app = new client::ClientAppRenderer();
	else if (process_type == client::ClientApp::OtherProcess)
		app = new client::ClientAppOther();

	CefMainArgs main_args(hInstance);
	CefInitialize(main_args, m_cefSetting, app, sandbox_info);

}

void CefClientBrowser::CreateBrowser(const std::string & url /*= ""*/)
{
	m_url = url;
	CefWindowInfo window_info;
	RECT rect;
	::GetClientRect(m_hWnd, &rect);
	window_info.SetAsChild(m_hWnd, rect);
	//window_info.SetAsPopup(m_hWnd, "aaa");
	//window_info.SetAsWindowless(m_hWnd, false);
	CefBrowserSettings browser_settings;
	m_clientHandler = new CefClientHandler(this);
	if (url.empty())
		CefBrowserHost::CreateBrowser(window_info, m_clientHandler, CefContext::GetInstance()->GetMainUrl(), browser_settings, NULL);
	else
		CefBrowserHost::CreateBrowser(window_info, m_clientHandler, url, browser_settings, NULL);
}

void CefClientBrowser::AdjustBrowserSize()
{
	if (m_clientHandler != nullptr && m_browser != nullptr)
	{
		auto hwnd = m_browser->GetHost()->GetWindowHandle();
		auto rect = RECT{ 0 };
		::GetClientRect(m_hWnd, &rect);
		::SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
	}
}

void CefClientBrowser::OnBrowserCreated(CefRefPtr<CefBrowser> browser)
{
	m_browser = browser;
}

void CefClientBrowser::OnBrowserClosing(CefRefPtr<CefBrowser> browser)
{
	if (m_browser != nullptr && m_browser->GetIdentifier() == browser->GetIdentifier())
	{
		m_browser = nullptr;
		m_clientHandler->DetachDelegate();
	}
}

void CefClientBrowser::OnBrowserClosed(CefRefPtr<CefBrowser> browser)
{

}

void CefClientBrowser::OnSetAddress(std::string const & url)
{

}

void CefClientBrowser::OnSetTitle(std::string const & title)
{

}

void CefClientBrowser::OnSetFullscreen(bool const fullscreen)
{

}

void CefClientBrowser::OnSetLoadingState(bool const isLoading, bool const canGoBack, bool const canGoForward)
{

}
