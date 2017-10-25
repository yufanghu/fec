#ifndef JC_CEF_BROWSER_H
#define JC_CEF_BROWSER_H

#include "Jccefhandle.h"
#pragma comment(lib, "libcef")

class JCCefBrowser{
public:
	JCCefBrowser(const HWND hWnd, const std::string & url);
	~JCCefBrowser();

	void Run();
private:
	SimpleHandler* m_handler;
	HWND m_hWnd;
	std::string m_strUrl;
	CefWindowInfo m_cefWndInfo;
};

#endif 