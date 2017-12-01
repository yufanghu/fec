// BrowserWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "CefTest.h"
#include "BrowserWnd.h"


// CBrowserWnd

IMPLEMENT_DYNAMIC(CBrowserWnd, CWnd)

CBrowserWnd::CBrowserWnd()
{
	m_pBrowser = new CefClientBrowser();
}

CBrowserWnd::~CBrowserWnd()
{
}


BEGIN_MESSAGE_MAP(CBrowserWnd, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CBrowserWnd 消息处理程序




int CBrowserWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_pBrowser->SetMainHwnd(GetSafeHwnd());
	m_pBrowser->CreateBrowser("http://www.baidu.com");
	return 0;
}


void CBrowserWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	CRect rect;
	GetClientRect(rect);

	rect.DeflateRect(1, 1);
	//m_pBrowser->MoveWindow(rect);

	m_pBrowser->AdjustBrowserSize();
}
