// CefTitleBar.cpp : 实现文件
//

#include "stdafx.h"
#include "CefTest.h"
#include "CefTitleBar.h"


// CCefTitleBar

IMPLEMENT_DYNAMIC(CCefTitleBar, CWnd)

CCefTitleBar::CCefTitleBar()
{

}

CCefTitleBar::~CCefTitleBar()
{
}


BEGIN_MESSAGE_MAP(CCefTitleBar, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CCefTitleBar 消息处理程序




void CCefTitleBar::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	
}


BOOL CCefTitleBar::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	return CWnd::OnEraseBkgnd(pDC);
}


void CCefTitleBar::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
}
