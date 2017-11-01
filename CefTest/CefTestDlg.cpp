
// CefTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CefTest.h"
#include "CefTestDlg.h"
#include "afxdialogex.h"
#include "CefApi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
//CCefApi * pCef = NULL;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCefTestDlg �Ի���



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


// CCefTestDlg ��Ϣ�������

BOOL CCefTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CCefApi * pCef = (new CCefApi());
	pCef->WebInit();
	pCef->SetHwnd(GetSafeHwnd());
	pCef->Run();
	return TRUE;
	auto rect = RECT{ 0 };

	HINSTANCE hInstance = GetModuleHandle(NULL);
	CefSettings m_cefSetting;

	//��ʼ��cefsetting
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

	m_cefSetting.multi_threaded_message_loop = true;		//ʹ����������Ϣѭ��
	m_cefSetting.single_process = true;					//ʹ�ö����ģʽ
	m_cefSetting.ignore_certificate_errors = true;		//���Ե�ssl֤����֤����
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
	m_cefSetting.multi_threaded_message_loop = true;		//ʹ����������Ϣѭ��
	m_cefSetting.single_process = false;					//ʹ�ö����ģʽ
	m_cefSetting.ignore_certificate_errors = true;		//���Ե�ssl֤����֤����
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCefTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCefTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

