#include "stdafx.h"
#include "CefBaseWnd.h"

IMPLEMENT_DYNAMIC(CefBaseWnd, CDialog)

//CefBaseWnd::CefBaseWnd() : m_pBrowser(NULL)
//{
//	m_pBrowser = new CefClientBrowser();
//}

CefBaseWnd::CefBaseWnd(UINT nID, CWnd* pParent /*= NULL*/) : CDialog(nID, pParent)
{
	m_pBrowser = new CefClientBrowser();
}


CefBaseWnd::~CefBaseWnd()
{
}
BEGIN_MESSAGE_MAP(CefBaseWnd, CDialog)
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()


void CefBaseWnd::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CWnd::OnClose();
}


int CefBaseWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//CefBaseWnd* p = new CefBaseWnd();
	//RECT rect;  GetClientRect(&rect);
	//m_pBrowser->CreateEx(WS_EX_CLIENTEDGE, NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 1230);
	//m_pBrowser->ShowWindow(SW_HIDE);
	//m_pBrowser->Go("www.baidu.com");
	//m_pBrowser->SetUserAgent("Mozilla/5.0 (Linux; U; Android 2.2; en-us; Nexus One Build/FRF91) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1");
	//m_pBrowser->WebInit();
	m_pBrowser->SetMainHwnd(GetSafeHwnd());
	m_pBrowser->CreateBrowser("http://www.baidu.com");
	return 0;
}


void CefBaseWnd::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
}


void CefBaseWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
}


void CefBaseWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	CRect rect;
	GetClientRect(rect);

	rect.DeflateRect(1, 1);
	//m_pBrowser->MoveWindow(rect);

	m_pBrowser->AdjustBrowserSize();
	// TODO:  在此处添加消息处理程序代码
}
