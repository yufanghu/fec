#pragma once
#include "CefClientHandler.h"
#include <string>

class CefClientBrowser : public CefClientHandler::Delegate
{
public:
	CefClientBrowser();
	virtual ~CefClientBrowser();
	
	void WebInit();
	void SetMainHwnd(HWND hWnd){ m_hWnd = hWnd; }
	void CreateBrowser(const std::string & url = "");
	void AdjustBrowserSize();
	void SetUserAgent(const std::string & uaTag){ m_strUserAgent += uaTag; }
	void SetCookies(const std::string & name, const std::string & domain, 
		const std::string & value, const std::string & path = "/");
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
	CefSettings m_cefSetting;
	HWND m_hWnd;
	std::string m_strUserAgent;
	std::string m_url;
};

