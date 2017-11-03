#pragma once
#include "CefClientBrowser.h"
#include "CefBrowserEx.h"

class CefBaseWnd : public CDialog
{
	DECLARE_DYNAMIC(CefBaseWnd)
public:
	CefBaseWnd(UINT nID, CWnd* pParent = NULL);
	CefBaseWnd();
	virtual ~CefBaseWnd();
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
private:
	CefBrowserEx * m_pBrowser;
};

