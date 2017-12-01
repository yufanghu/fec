#pragma once
#include "CefClientBrowser.h"

// CBrowserWnd

class CBrowserWnd : public CWnd
{
	DECLARE_DYNAMIC(CBrowserWnd)

public:
	CBrowserWnd();
	virtual ~CBrowserWnd();

protected:
	DECLARE_MESSAGE_MAP()
private:
	CefClientBrowser * m_pBrowser;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


