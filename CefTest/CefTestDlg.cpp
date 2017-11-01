
// CefTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CefTest.h"
#include "CefTestDlg.h"
#include "afxdialogex.h"
#include "CefApi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
//CCefApi * pCef = NULL;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}
extern CCefApi * pCef;
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCefTestDlg 对话框



CCefTestDlg::CCefTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCefTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCefTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCefTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCefTestDlg 消息处理程序

BOOL CCefTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	CCefApi * pCef = (new CCefApi());
	pCef->WebInit();
	pCef->SetHwnd(GetSafeHwnd());
	pCef->Run();
	return TRUE;
	auto rect = RECT{ 0 };

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
	//GetCefChildPath(&path);
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
	m_cefSetting.multi_threaded_message_loop = true;		//使用主程序消息循环
	m_cefSetting.single_process = false;					//使用多进程模式
	m_cefSetting.ignore_certificate_errors = true;		//忽略掉ssl证书验证错误
	//m_cefSetting.command_line_args_disabled = true;
	m_cefSetting.no_sandbox = true;
	CefMainArgs main_args(hInstance);
	CefInitialize(main_args, m_cefSetting, app, sandbox_info);


	GetClientRect(&rect);

	CefWindowInfo info;
	info.SetAsChild(GetSafeHwnd(), rect);

	CefBrowserSettings browserSettings;
	browserSettings.web_security = STATE_DISABLED;

	/*m_clientHandler = new guo::ClientHandler(this);
	m_clientHandler->CreateBrowser(info, browserSettings, CefString("www.baidu.com"));*/
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCefTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCefTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCefTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

