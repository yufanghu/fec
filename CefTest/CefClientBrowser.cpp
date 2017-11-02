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
#include "browser\main_message_loop_multithreaded_win.h"

CefClientBrowser::CefClientBrowser() : m_hWnd(NULL), m_clientHandler(NULL)
{

}

CefClientBrowser::~CefClientBrowser()
{
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
	if (m_browser != nullptr)
	{
		if (fullscreen)
		{
			//CefWindowsHelpers::Maximize(m_browser);
		}
		else
		{
			//CefWindowsHelpers::Restore(m_browser);
		}
	}
}

void CefClientBrowser::OnSetLoadingState(bool const isLoading, bool const canGoBack, bool const canGoForward)
{

}


BEGIN_MESSAGE_MAP(CefClientBrowser, CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int CefClientBrowser::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	WebInit();
	return 0;
}


void CefClientBrowser::OnDestroy()
{
	__super::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
}


void CefClientBrowser::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	
	__super::OnClose();
}

void CefClientBrowser::WebInit()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	CefSettings m_cefSetting;

	//初始化cefsetting
	CefSettingsTraits::init(&m_cefSetting);
	void* sandbox_info = NULL;

	/*if (m_bEnableSandBox){
	CefScopedSandboxInfo scoped_sandbox;
	sandbox_info = scoped_sandbox.sandbox_info();
	m_cefSetting.no_sandbox = false;
	}
	else{
	m_cefSetting.no_sandbox = true;
	}*/

	m_cefSetting.multi_threaded_message_loop = true;		//使用主程序消息循环
	m_cefSetting.single_process = false;					//使用多进程模式
	m_cefSetting.ignore_certificate_errors = true;		//忽略掉ssl证书验证错误
	//m_cefSetting.command_line_args_disabled = true;
	m_cefSetting.no_sandbox = true;
	CefString(&m_cefSetting.locale).FromASCII("zh-CN");

	wchar_t * path = new wchar_t[MAX_PATH];
	memset(path, 0, MAX_PATH * sizeof(wchar_t));
	//GetCefChildPath(&path);
	//cef_string_from_wide(path, MAX_PATH, &m_cefSetting.browser_subprocess_path);

	//::MessageBoxA(NULL, ("aaa"), NULL, MB_OK);
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

	delete[] path;
	path = NULL;
}

void CefClientBrowser::Go(const std::string & url)
{
	CefWindowInfo window_info;
	RECT rect;
	::GetClientRect(GetParent()->GetSafeHwnd(), &rect);
	window_info.SetAsChild(GetParent()->GetSafeHwnd(), rect);
	//window_info.SetAsPopup(m_hWnd, "aaa");
	//window_info.SetAsWindowless(m_hWnd, false);
	CefBrowserSettings browser_settings;
	m_clientHandler = new CefClientHandler(this);
	CefBrowserHost::CreateBrowser(window_info, m_clientHandler, "http://www.baidu.com/", browser_settings, NULL);
}


void CefClientBrowser::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);
	if (m_clientHandler != nullptr)
	{
		if (m_browser != nullptr)
		{
			auto hwnd = m_browser->GetHost()->GetWindowHandle();
			auto rect = RECT{ 0 };
			GetClientRect(&rect);

			::SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
		}
	}
	// TODO:  在此处添加消息处理程序代码
}
