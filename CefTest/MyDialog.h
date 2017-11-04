#pragma once


// CMyDialog �Ի���

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDialog();

// �Ի�������
	enum { IDD = IDD_MYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
private:
	void DrawTitleBar(CDC *pDC);
private:
	CRect m_rtButtExit;    // �رհ�ťλ��
	CRect m_rtButtMax;    // ��󻯰�ťλ��
	CRect m_rtButtMin;    // ��С����ťλ��
	CRect m_rtButtHel;    // ������ť
	CRect m_rtIcon;        // ͼ��λ��
public:
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);



};
