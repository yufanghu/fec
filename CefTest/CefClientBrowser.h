#pragma once
#include "CefClientHandler.h"
#include <string>

class CefClientBrowser : public CWnd, public CefClientHandler::Delegate
{
public:
	CefClientBrowser();
	virtual ~CefClientBrowser();
	void SetMainHwnd(HWND hWnd);
	void WebInit();
	void Go(const std::string & url);
	
protected:
	void OnBrowserCreated(CefRefPtr<CefBrowser> browser);
	//
	void OnBrowserClosing(CefRefPtr<CefBrowser> browser);
	//
	void OnBrowserClosed(CefRefPtr<CefBrowser> browser);
	//
	void OnSetAddress(std::string const & url);
	//
	void OnSetTitle(std::string const & title);
	//
	void OnSetFullscreen(bool const fullscreen);
	//
	void OnSetLoadingState(bool const isLoading, bool const canGoBack, bool const canGoForward);

private:
	CefRefPtr<CefBrowser> m_browser;
	CefClientHandler* m_clientHandler;
	HWND m_hWnd;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};