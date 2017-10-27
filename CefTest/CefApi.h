#pragma once
#include <AccCtrl.h>
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"
//#include "include/cef_sandbox_win.h"
#include "include/cef_app.h"
#include "shared/common/client_app.h"
#include "shared/browser/client_app_browser.h"
#include "shared/renderer/client_app_renderer.h"
#include "shared/common/client_app_other.h"

//#pragma comment(lib, "libcef")
#pragma comment(lib, "Dbghelp")
#pragma comment(lib, "Psapi")	
#pragma comment(lib, "Winmm")	


using namespace client;
class CCefApi
{
public:
	CCefApi();
	~CCefApi();
	void WebInit(HWND hWnd){

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
		m_cefSetting.command_line_args_disabled = true;

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
};

