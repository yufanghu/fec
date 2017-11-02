#pragma once


// CCefTitleBar

class CCefTitleBar : public CWnd
{
	DECLARE_DYNAMIC(CCefTitleBar)

public:
	CCefTitleBar();
	virtual ~CCefTitleBar();

protected:
	DECLARE_MESSAGE_MAP()

private:
	int m_height;
	int m_width;
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


