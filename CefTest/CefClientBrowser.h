#pragma once
#include "CefClientHandler.h"

class CefClientBrowser : public CefClientHandler::Delegate
{
public:
	CefClientBrowser();
	virtual ~CefClientBrowser();
	void SetMainHwnd(HWND hWnd);
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
};

//void OnBrowserCreated(CefRefPtr<CefBrowser> browser);
//
//void OnBrowserClosing(CefRefPtr<CefBrowser> browser);
//
//void OnBrowserClosed(CefRefPtr<CefBrowser> browser);
//
//void OnSetAddress(std::string const & url)
//{
//	/*auto main = static_cast<CMainFrame*>(m_wndMain);
//	if (main != nullptr)
//	{
//	auto newurl = CString{ url.c_str() };
//	if (newurl.Find(m_startUrl) >= 0)
//	newurl = "";
//
//	main->SetUrl(newurl);
//	}*/
//}
//
//void OnSetTitle(std::string const & title)
//{
//	::SetWindowText(m_hWnd, CefString(title).ToWString().c_str());
//}
//
//void OnSetFullscreen(bool const fullscreen)
//{
//	if (m_browser != nullptr)
//	{
//		if (fullscreen)
//		{
//			//CefWindowsHelpers::Maximize(m_browser);
//		}
//		else
//		{
//			//CefWindowsHelpers::Restore(m_browser);
//		}
//	}
//}
//
//void OnSetLoadingState(bool const isLoading,
//	bool const canGoBack,
//	bool const canGoForward)
//{
//}



//void CCefTestDlg::OnBrowserCreated(CefRefPtr<CefBrowser> browser)
//{
//	m_browser = browser;
//}
//
//void CCefTestDlg::OnBrowserClosing(CefRefPtr<CefBrowser> browser)
//{
//
//}
//
//void CCefTestDlg::OnBrowserClosed(CefRefPtr<CefBrowser> browser)
//{
//	if (m_browser != nullptr &&
//		m_browser->GetIdentifier() == browser->GetIdentifier())
//	{
//		m_browser = nullptr;
//
//		//m_clientHandler->DetachDelegate();
//	}
//}

