#include "JccefBrowser.h"

JCCefBrowser::JCCefBrowser(const HWND hWnd, const std::string & url) : m_handler(NULL){
	m_hWnd = hWnd;
	m_strUrl = url;
	m_handler = new SimpleHandler();
}

void JCCefBrowser::Run(){
	CefWindowInfo window_info;
	RECT rect;
	::GetWindowRect(m_hWnd, &rect);
	window_info.SetAsChild(m_hWnd, rect);
	//window_info.SetAsPopup(m_hWnd, "aaa");
	//window_info.SetAsWindowless(m_hWnd, false);
	CefBrowserSettings browser_settings;
	CefBrowserHost::CreateBrowser(window_info, m_handler, m_strUrl, browser_settings, NULL);
}

JCCefBrowser::~JCCefBrowser()
{
	delete m_handler;
	m_handler = NULL;
}
