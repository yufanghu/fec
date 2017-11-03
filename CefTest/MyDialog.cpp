// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CefTest.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog 对话框

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
{
	m_pBrowser = new CefClientBrowser();
}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_WM_NCLBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_NCCALCSIZE()
	ON_WM_SIZE()
	ON_WM_NCMOUSEMOVE()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CMyDialog 消息处理程序


LRESULT CMyDialog::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO:  在此添加专用代码和/或调用基类

	LRESULT lrst = CDialog::DefWindowProc(message, wParam, lParam);
	if (!::IsWindow(m_hWnd))
		return lrst;

	if (message == WM_MOVE
		|| message == WM_PAINT
		|| message == WM_NCPAINT
		|| message == WM_NCACTIVATE
		|| message == WM_NOTIFY)
	{
		CDC* pWinDC = GetWindowDC();
		if (pWinDC)
			DrawTitleBar(pWinDC);
		ReleaseDC(pWinDC);
	}
	return lrst;
}

void CMyDialog::DrawTitleBar(CDC *pDC)
{
	if (m_hWnd)
	{
		CBrush Brush(RGB(0, 0, 0));
		CBrush* pOldBrush = pDC->SelectObject(&Brush);

		CRect rtWnd, rtTitle, rtButtons;
		GetWindowRect(&rtWnd);
		//取得标题栏的位置
		rtTitle.left = GetSystemMetrics(SM_CXFRAME);
		rtTitle.top = GetSystemMetrics(SM_CYFRAME);
		rtTitle.right = rtWnd.right - GetSystemMetrics(SM_CXFRAME);
		rtTitle.bottom = rtTitle.top + GetSystemMetrics(SM_CYSIZE);

		// 避免与原有标题栏重叠
		int nTitleTopDown = 0;
		CPoint point;
		//填充顶部框架
		point.x = rtWnd.Width();
		point.y = GetSystemMetrics(SM_CYSIZE) + GetSystemMetrics(SM_CYFRAME);
		pDC->PatBlt(0, nTitleTopDown, point.x, point.y, PATCOPY);
		//填充左侧框架
		point.x = GetSystemMetrics(SM_CXFRAME) + 1;
		point.y = rtWnd.Height();
		pDC->PatBlt(0, nTitleTopDown, point.x, point.y, PATCOPY);
		//填充底部框架
		point.x = rtWnd.Width();
		point.y = GetSystemMetrics(SM_CYFRAME) + 1;
		pDC->PatBlt(0, rtWnd.Height() - point.y, point.x, point.y, PATCOPY);
		//填充右侧框架
		point.x = GetSystemMetrics(SM_CXFRAME) + 1;
		point.y = rtWnd.Height();
		pDC->PatBlt(rtWnd.Width() - point.x, 0, point.x, point.y, PATCOPY);

		//绘制美化线条
		CBrush BrushLine(RGB(255, 255, 255));
		pDC->SelectObject(&BrushLine);
		point.x = rtWnd.Width() - 150;
		point.y = GetSystemMetrics(SM_CYFRAME) + nTitleTopDown + 2;
		pDC->PatBlt(GetSystemMetrics(SM_CXFRAME), point.y, point.x, 1, PATCOPY);
		point.y += 5;
		pDC->PatBlt(GetSystemMetrics(SM_CXFRAME), point.y, point.x, 1, PATCOPY);
		point.y += 5;
		pDC->PatBlt(GetSystemMetrics(SM_CXFRAME), point.y, point.x, 1, PATCOPY);
		point.x += 60;
		point.y += 12;
		pDC->PatBlt(point.x, point.y, 85, 1, PATCOPY);
		point.y += 5;
		pDC->PatBlt(point.x, point.y, 85, 1, PATCOPY);
		point.x -= 60 - GetSystemMetrics(SM_CXFRAME);
		point.y += 5;
		pDC->PatBlt(point.x, point.y, 145 - GetSystemMetrics(SM_CXFRAME), 1, PATCOPY);
		point.y -= 32;
		pDC->PatBlt(point.x, point.y, 1, 32, PATCOPY);

		pDC->SelectObject(pOldBrush);

		//重画图标
		m_rtIcon.left = rtWnd.Width() - 130;
		m_rtIcon.top = GetSystemMetrics(SM_CYFRAME) + nTitleTopDown;
		m_rtIcon.right = m_rtIcon.left + 32;
		m_rtIcon.bottom = m_rtIcon.top + 32;
		/*::DrawIconEx(pDC->m_hDC, m_rtIcon.left, m_rtIcon.top, m_hIcon,
			m_rtIcon.Width(), m_rtIcon.Height(), 0, NULL, DI_NORMAL);*/
		m_rtIcon.OffsetRect(rtWnd.TopLeft());


		//准备画XP风格按钮
		CBitmap* pBitmap = new CBitmap;
		CBitmap* pOldBitmap;
		CDC* pDisplayMemDC = new CDC;
		pDisplayMemDC->CreateCompatibleDC(pDC);

		//重画关闭button
		rtButtons.left = rtTitle.right - 19;
		rtButtons.top = rtTitle.top + nTitleTopDown;
		rtButtons.right = rtButtons.left + 19;
		rtButtons.bottom = rtButtons.top + 19;
		/*pBitmap->LoadBitmap(IDB_EXIT_NORMAL);
		pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		pDC->BitBlt(rtButtons.left, rtButtons.top, rtButtons.Width(), rtButtons.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		pDisplayMemDC->SelectObject(pOldBitmap);
		m_rtButtExit = rtButtons;
		m_rtButtExit.OffsetRect(rtWnd.TopLeft());
		pBitmap->DeleteObject();*/

		//重画最大化/恢复button
		rtButtons.right = rtButtons.left - 3;
		rtButtons.left = rtButtons.right - 19;
		/*if (IsZoomed())
			pBitmap->LoadBitmap(IDB_RESTORE_NORMAL);
		else
			pBitmap->LoadBitmap(IDB_MAX_NORMAL);
		pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		pDC->BitBlt(rtButtons.left, rtButtons.top, rtButtons.Width(), rtButtons.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		pDisplayMemDC->SelectObject(pOldBitmap);
		m_rtButtMax = rtButtons;
		m_rtButtMax.OffsetRect(rtWnd.TopLeft());
		pBitmap->DeleteObject();*/

		//重画最小化button
		rtButtons.right = rtButtons.left - 3;
		rtButtons.left = rtButtons.right - 19;
		/*pBitmap->LoadBitmap(IDB_MIN_NORMAL);
		pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		pDC->BitBlt(rtButtons.left, rtButtons.top, rtButtons.Width(), rtButtons.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		pDisplayMemDC->SelectObject(pOldBitmap);
		m_rtButtMin = rtButtons;
		m_rtButtMin.OffsetRect(rtWnd.TopLeft());
		pBitmap->DeleteObject();*/

		//重画帮助button
		rtButtons.right = rtButtons.left - 3;
		rtButtons.left = rtButtons.right - 19;
		/*pBitmap->LoadBitmap(IDB_HELP_NORMAL);
		pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		pDC->BitBlt(rtButtons.left, rtButtons.top, rtButtons.Width(), rtButtons.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		pDisplayMemDC->SelectObject(pOldBitmap);
		m_rtButtHel = rtButtons;
		m_rtButtHel.OffsetRect(rtWnd.TopLeft());
		pBitmap->DeleteObject();*/

		//重画caption
		int nOldMode = pDC->SetBkMode(TRANSPARENT);
		COLORREF clOldText = pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SelectStockObject(SYSTEM_FIXED_FONT);
		rtTitle.left += 2;
		rtTitle.top += GetSystemMetrics(SM_CYSIZE) + nTitleTopDown;
		rtTitle.bottom = rtTitle.top + 30;
		CString m_strTitle;
		GetWindowText(m_strTitle);
		pDC->DrawText(m_strTitle, &rtTitle, DT_LEFT);
		pDC->SetBkMode(nOldMode);
		pDC->SetTextColor(clOldText);

		ReleaseDC(pDisplayMemDC);
		delete pDisplayMemDC;
		delete pBitmap;
	}
}


void CMyDialog::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CDialog::OnNcLButtonDown(nHitTest, point);
	// 4. 非客户区鼠标左键按下事件
	//检测各按钮是否按到
	if (m_rtIcon.PtInRect(point))
	{
		::MessageBox(this->m_hWnd, L"ICON", L"", MB_OK);
	}
	else if (m_rtButtExit.PtInRect(point))
	{
		SendMessage(WM_CLOSE);
	}
	else if (m_rtButtMin.PtInRect(point))
	{
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, MAKELPARAM(point.x, point.y));
	}
	else if (m_rtButtHel.PtInRect(point))
	{
		::MessageBox(this->m_hWnd, L"HELP", L"", MB_OK);
	}
	else if (m_rtButtMax.PtInRect(point))
	{
		if (IsZoomed())
			SendMessage(WM_SYSCOMMAND, SC_RESTORE, MAKELPARAM(point.x, point.y));
		else
		{
			SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, MAKELPARAM(point.x, point.y));
			Invalidate();
		}
	}
	else if (!IsZoomed())
	{
		CDialog::OnNcLButtonDown(nHitTest, point);
	}
}


void CMyDialog::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialog::OnMouseMove(nFlags, point);
}


void CMyDialog::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	// 2. 调整标题栏高度
	lpncsp->rgrc[0].top += 22 ;
	//CDialog::OnNcCalcSize(bCalcValidRects, lpncsp);
	CDialog::OnNcCalcSize(bCalcValidRects, lpncsp);
}


void CMyDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	// TODO: 在此处添加消息处理程序代码// Create a rgn without 3 pixels border
	//取消原来对话框标题边框
	CRect wrc;
	GetWindowRect(&wrc);
	wrc.OffsetRect(-wrc.left, -wrc.top);
	wrc.DeflateRect(3, 3);
	//
	CRgn rgn;
	BOOL bl = rgn.CreateRectRgnIndirect(&wrc);
	if (bl) SetWindowRgn(rgn, TRUE);
	rgn.Detach();

	CRect rect;
	GetClientRect(rect);

	rect.DeflateRect(1, 1);
	m_pBrowser->MoveWindow(rect);
	// TODO:  在此处添加消息处理程序代码
}


void CMyDialog::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CDialog::OnNcMouseMove(nHitTest, point);
	// 3. 非客户区鼠标移动事件
	CDC* pDC = GetWindowDC();
	CDC* pDisplayMemDC = new CDC;
	pDisplayMemDC->CreateCompatibleDC(pDC);
	CBitmap* pBitmap = new CBitmap;
	CBitmap* pOldBitmap;
	CRect rtWnd, rtButton;

	if (pDC)
	{
		GetWindowRect(&rtWnd);

		//关闭button
		/*if (m_rtButtExit.PtInRect(point))
			pBitmap->LoadBitmap(IDB_EXIT_FOCUS);
		else
			pBitmap->LoadBitmap(IDB_EXIT_NORMAL);
		rtButton = m_rtButtExit;
		rtButton.OffsetRect(-rtWnd.left, -rtWnd.top);
		pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		pDC->BitBlt(rtButton.left, rtButton.top, rtButton.Width(), rtButton.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		pDisplayMemDC->SelectObject(pOldBitmap);
		pBitmap->DeleteObject();*/

		//最大化/恢复button
		//if (m_rtButtMax.PtInRect(point))
		//{
		//	if (IsZoomed())
		//		pBitmap->LoadBitmap(IDB_RESTORE_FOCUS);
		//	else
		//		pBitmap->LoadBitmap(IDB_MAX_FOCUS);
		//}
		//else
		//{
		//	if (IsZoomed())
		//		pBitmap->LoadBitmap(IDB_RESTORE_NORMAL);
		//	else
		//		pBitmap->LoadBitmap(IDB_MAX_NORMAL);
		//}
		//rtButton = m_rtButtMax;
		//rtButton.OffsetRect(-rtWnd.left, -rtWnd.top);
		//pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		//pDC->BitBlt(rtButton.left, rtButton.top, rtButton.Width(), rtButton.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		//pDisplayMemDC->SelectObject(pOldBitmap);
		//pBitmap->DeleteObject();

		////最小化button
		//if (m_rtButtMin.PtInRect(point))
		//	pBitmap->LoadBitmap(IDB_MIN_FOCUS);
		//else
		//	pBitmap->LoadBitmap(IDB_MIN_NORMAL);
		//rtButton = m_rtButtMin;
		//rtButton.OffsetRect(-rtWnd.left, -rtWnd.top);
		//pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		//pDC->BitBlt(rtButton.left, rtButton.top, rtButton.Width(), rtButton.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		//pDisplayMemDC->SelectObject(pOldBitmap);
		//pBitmap->DeleteObject();

		////帮助button
		//if (m_rtButtHel.PtInRect(point))
		//	pBitmap->LoadBitmap(IDB_HELP_FOCUS);
		//else
		//	pBitmap->LoadBitmap(IDB_HELP_NORMAL);
		//rtButton = m_rtButtHel;
		//rtButton.OffsetRect(-rtWnd.left, -rtWnd.top);
		//pOldBitmap = (CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		//pDC->BitBlt(rtButton.left, rtButton.top, rtButton.Width(), rtButton.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		//pDisplayMemDC->SelectObject(pOldBitmap);
		//pBitmap->DeleteObject();
	}

	ReleaseDC(pDisplayMemDC);
	ReleaseDC(pDC);
	delete pDisplayMemDC;
	delete pBitmap;
	CDialog::OnNcMouseMove(nHitTest, point);
}


int CMyDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	
	m_pBrowser->CreateEx(WS_EX_CLIENTEDGE, NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 1230);
	m_pBrowser->ShowWindow(SW_HIDE);
	m_pBrowser->Go("www.baidu.com");
	return 0;
}
