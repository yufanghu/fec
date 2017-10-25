
#include <string>
#include "JccefApp.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"
#include "include/cef_sandbox_win.h"
#include "JccefBrowser.h"

CJcCefApp::CJcCefApp() : m_bEnableSandBox(false){

}


void CJcCefApp::OnContextInitialized() {
	CEF_REQUIRE_UI_THREAD();
	//SetWndInfo();
}


int CJcCefApp::Init(HINSTANCE hInstance)
{
	CefSettings m_cefSetting;

	CefSettingsTraits::init(&m_cefSetting);

	// Manage the life span of the sandbox information object. This is necessary
	// for sandbox support on Windows. See cef_sandbox_win.h for complete details.
	void* sandbox_info = NULL;
	
	if (m_bEnableSandBox){
		CefScopedSandboxInfo scoped_sandbox;
		sandbox_info = scoped_sandbox.sandbox_info();
		m_cefSetting.no_sandbox = false;
	}
	else{
		m_cefSetting.no_sandbox = true;
	}
	
	CefMainArgs main_args(hInstance);
	 
	int exit_code = CefExecuteProcess(main_args, this, sandbox_info);
	if (exit_code >= 0)
		return exit_code;

	m_cefSetting.multi_threaded_message_loop = true;	//使用主程序消息循环
	m_cefSetting.single_process = false;					//使用多进程模式
	m_cefSetting.ignore_certificate_errors = true;		//忽略掉ssl证书验证错误
	m_cefSetting.command_line_args_disabled = true;

	CefString(&m_cefSetting.locale).FromASCII("zh-CN");

	WCHAR subProcessPath[MAX_PATH] = { 0 };
	GetModuleFileNameW(hInstance, subProcessPath, MAX_PATH);
	*(wcsrchr(subProcessPath, L'\\') + 1) = L'\0';
	LPCWSTR SUB_PROCESS_NAME = L"CefAgent.exe";
	wcsncat_s(subProcessPath, MAX_PATH, SUB_PROCESS_NAME, wcslen(SUB_PROCESS_NAME));
	cef_string_from_wide(subProcessPath, MAX_PATH, &m_cefSetting.browser_subprocess_path);

	//::MessageBoxA(NULL, ("aaa"), NULL, MB_OK);
	return CefInitialize(main_args, m_cefSetting, this, sandbox_info);
}



CJcCefApp::~CJcCefApp()
{
	//Close();
}

void CJcCefApp::Close()
{
	CefShutdown();
}

void CJcCefApp::Run()
{
	CefRunMessageLoop();
}





