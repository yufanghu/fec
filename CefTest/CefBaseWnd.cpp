#include "stdafx.h"
#include "CefBaseWnd.h"

IMPLEMENT_DYNAMIC(CefBaseWnd, CDialog)

CefBaseWnd::CefBaseWnd() : m_pBrowser(NULL)
{
	m_pBrowser = new CefClientBrowser();
}

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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CWnd::OnClose();
}


int CefBaseWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//CefBaseWnd* p = new CefBaseWnd();
	//RECT rect;  GetClientRect(&rect);
	m_pBrowser->CreateEx(WS_EX_CLIENTEDGE, NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 1230);
	m_pBrowser->ShowWindow(SW_SHOW);
	m_pBrowser->Go("www.baidu.com");
	return 0;
}


void CefBaseWnd::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO:  �ڴ˴������Ϣ����������
}


void CefBaseWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
}


void CefBaseWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	CRect rect;
	GetClientRect(rect);

	rect.DeflateRect(1, 1);
	m_pBrowser->MoveWindow(rect);
	// TODO:  �ڴ˴������Ϣ����������
}
