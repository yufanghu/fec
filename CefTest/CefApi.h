#pragma once
#include <AccCtrl.h>
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
//#pragma comment(lib, "libcef")
#pragma comment(lib, "Dbghelp")
#pragma comment(lib, "Psapi")	
#pragma comment(lib, "Winmm")
#pragma comment(lib, "opengl32")
#pragma comment(lib, "Imm32")

using namespace client;
class CCefApi : public BrowserWindow::Delegate
{
public:
	CCefApi();
	~CCefApi();
	void WebInit(){

		//m_hWnd = hWnd;
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
		m_cefSetting.single_process = true;					//使用多进程模式
		m_cefSetting.ignore_certificate_errors = true;		//忽略掉ssl证书验证错误
		//m_cefSetting.command_line_args_disabled = true;
		m_cefSetting.no_sandbox = true;
		CefString(&m_cefSetting.locale).FromASCII("zh-CN");

		wchar_t * path = new wchar_t[MAX_PATH];
		memset(path, 0, MAX_PATH * sizeof(wchar_t));
		GetCefChildPath(&path);
		//cef_string_from_wide(path, MAX_PATH, &m_cefSetting.browser_subprocess_path);

		//::MessageBoxA(NULL, ("aaa"), NULL, MB_OK);
		CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
		command_line->InitFromString(::GetCommandLineW());

		// Create a ClientApp of the correct type.
		CefRefPtr<CefApp> app;
		client::ClientApp::ProcessType process_type = client::ClientApp::GetProcessType(command_line);
		if (process_type == client::ClientApp::BrowserProcess)
			app = new ClientAppBrowser();
		else if (process_type == ClientApp::RendererProcess)
			app = new ClientAppRenderer();
		else if (process_type == ClientApp::OtherProcess)
			app = new ClientAppOther();

		CefMainArgs main_args(hInstance);
		CefInitialize(main_args, m_cefSetting, app, sandbox_info);

		delete[] path;
		path = NULL;
	}
	void SetHwnd(HWND hWnd){ m_hWnd = hWnd; }
	void Run(){
		CefWindowInfo window_info;
		RECT rect;
		::GetWindowRect(m_hWnd, &rect);
		window_info.SetAsChild(m_hWnd, rect);
		//window_info.SetAsPopup(m_hWnd, "aaa");
		//window_info.SetAsWindowless(m_hWnd, false);
		CefBrowserSettings browser_settings;
		//OsrRenderer::Settings settings = {};
		////MainContext::Get()->PopulateOsrSettings(&settings);
		//BrowserWindowOsrWin * bw = new BrowserWindowOsrWin(this, "www.baiddu.com", settings);
		////BrowserWindowOsrWin * bw = new client::BrowserWindowOsrWin()
		//bw->CreateBrowser(m_hWnd, CefRect(), browser_settings,
		//	NULL);
		
		//CefRefPtr<CefClient> client(new client::ClientHandler(NULL, false, "https://www.baidu.com"));
		CefClient * pClient = new client::ClientHandler(NULL, false, "https://www.baidu.com");
		CefBrowserHost::CreateBrowser(window_info, pClient, "https://www.baidu.com", browser_settings, NULL);

		//MainMessageLoop * pmsg = new MainMessageLoopMultithreadedWin();
		//if (settings.multi_threaded_message_loop)
		//pmsg->reset(new MainMessageLoopMultithreadedWin);
		//message_loop->Run();
	}
private:
	void GetCefChildPath(wchar_t ** path){
		wchar_t* p = *path;

		//WCHAR subProcessPath[MAX_PATH] = { 0 };
		GetModuleFileNameW(NULL, p, MAX_PATH);
		*(wcsrchr(p, L'\\') + 1) = L'\0';
		LPCWSTR SUB_PROCESS_NAME = L"CefAgent.exe";
		wcsncat_s(p, MAX_PATH, SUB_PROCESS_NAME, wcslen(SUB_PROCESS_NAME));
		
	}
	bool m_bEnableSandBox;
	HWND m_hWnd;

	// BrowserWindow::Delegate methods.
	void OnBrowserCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
	void OnBrowserWindowDestroyed() OVERRIDE;
	void OnSetAddress(const std::string& url) OVERRIDE;
	void OnSetTitle(const std::string& title) OVERRIDE;
	void OnSetFullscreen(bool fullscreen) OVERRIDE;
	void OnSetLoadingState(bool isLoading,
		bool canGoBack,
		bool canGoForward) OVERRIDE;
	void OnSetDraggableRegions(
		const std::vector<CefDraggableRegion>& regions) OVERRIDE;
};

