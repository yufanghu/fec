// CefTitleBar.cpp : ʵ���ļ�
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



// CCefTitleBar ��Ϣ�������




void CCefTitleBar::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
	
}


BOOL CCefTitleBar::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CWnd::OnEraseBkgnd(pDC);
}


void CCefTitleBar::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
}
