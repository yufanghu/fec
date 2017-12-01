#include "CefInit.h"
#include "shared\browser\client_app_browser.h"
#include "shared\renderer\client_app_renderer.h"
#include "shared\common\client_app_other.h"
#include "CefContext.h"

CefInit::CefInit()
{
	CefSettingsTraits::init(&m_cefSetting);
}


CefInit::~CefInit()
{
}

void CefInit::WebInit()
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

	//设置UA
	CefString(&m_cefSetting.user_agent) = CefContext::GetInstance()->GetUserAgent();
	m_cefSetting.multi_threaded_message_loop = true;		//使用主程序消息循环
	m_cefSetting.single_process = false;					//使用多进程模式
	m_cefSetting.ignore_certificate_errors = true;			//忽略掉ssl证书验证错误
	//m_cefSetting.command_line_args_disabled = true;
	m_cefSetting.no_sandbox = true;
	CefString(&m_cefSetting.locale).FromASCII("zh-CN");


	//子进程
	const std::string & agent_path = CefContext::GetInstance()->GetAgentPath();
	cef_string_from_ascii(agent_path.c_str(), agent_path.length(), &m_cefSetting.browser_subprocess_path);


	CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
	command_line->InitFromString(::GetCommandLineW());
	//command_line->AppendSwitchWithValue("proxy-server", ("socksww5://192.168.1.1:9090"));
	//command_line->AppendSwitchWithValue("ppapi-flash-path", "pepflashplayer.dll");
	//command_line->AppendArgument()
	//command_line->AppendSwitch("no-referrers");
	//command_line->AppendSwitch("no-proxy-server");
	// Create a ClientApp of the correct type.
	CefRefPtr<CefApp> app;
	client::ClientApp::ProcessType process_type = client::ClientApp::GetProcessType(command_line);
	if (process_type == client::ClientApp::BrowserProcess)
		app = new client::ClientAppBrowser();
	else if (process_type == client::ClientApp::RendererProcess){
		MessageBox(NULL, NULL, NULL, MB_OK);
		app = new client::ClientAppRenderer();
	}
	else if (process_type == client::ClientApp::OtherProcess)
		app = new client::ClientAppOther();

	CefMainArgs main_args(hInstance);

	int exit_code = CefExecuteProcess(main_args, app, sandbox_info);
	if (exit_code >= 0)
		return;
	//CefRefPtr<CefCommandLine> command_line_global = CefCommandLine::GetGlobalCommandLine();
	//command_line->AppendSwitchWithValue("proxy-server", ("socksww5://192.168.1.1:9090"));

	CefInitialize(main_args, m_cefSetting, app, sandbox_info);
}
