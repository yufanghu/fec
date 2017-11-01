#include "stdafx.h"
#include "CefClientBrowser.h"


CefClientBrowser::CefClientBrowser() : m_hWnd(NULL), m_clientHandler(NULL)
{

}

CefClientBrowser::~CefClientBrowser()
{
}

void CefClientBrowser::OnBrowserCreated(CefRefPtr<CefBrowser> browser)
{
	m_browser = browser;
}

void CefClientBrowser::OnBrowserClosing(CefRefPtr<CefBrowser> browser)
{
	if (m_browser != nullptr && m_browser->GetIdentifier() == browser->GetIdentifier())
	{
		m_browser = nullptr;
		m_clientHandler->DetachDelegate();
	}
}

void CefClientBrowser::OnBrowserClosed(CefRefPtr<CefBrowser> browser)
{

}

void CefClientBrowser::OnSetAddress(std::string const & url)
{

}

void CefClientBrowser::OnSetTitle(std::string const & title)
{

}

void CefClientBrowser::OnSetFullscreen(bool const fullscreen)
{

}

void CefClientBrowser::OnSetLoadingState(bool const isLoading, bool const canGoBack, bool const canGoForward)
{

}


