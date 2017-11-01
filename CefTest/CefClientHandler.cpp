#include "stdafx.h"
#include "CefClientHandler.h"
#include "include/wrapper/cef_helpers.h"

CefClientHandler::CefClientHandler(Delegate* delegate)
	: m_delegate(delegate)
{

}

void CefClientHandler::DetachDelegate()
{
	m_delegate = nullptr;
}

void CefClientHandler::OnAddressChange(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& url)
{
	CEF_REQUIRE_UI_THREAD();

	// Only update the address for the main (top-level) frame.
	if (frame->IsMain())
	{
		if (m_delegate != nullptr)
			m_delegate->OnSetAddress(url);
	}
}

void CefClientHandler::OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title)
{
	CEF_REQUIRE_UI_THREAD();

	if (m_delegate != nullptr)
		m_delegate->OnSetTitle(title);
}

void CefClientHandler::OnFullscreenModeChange(CefRefPtr<CefBrowser> browser, bool fullscreen)
{
	CEF_REQUIRE_UI_THREAD();

	if (m_delegate != nullptr)
		m_delegate->OnSetFullscreen(fullscreen);
}

void CefClientHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();

	if (m_delegate != nullptr)
		m_delegate->OnBrowserCreated(browser);
}

bool CefClientHandler::DoClose(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();

	if (m_delegate != nullptr)
		m_delegate->OnBrowserClosing(browser);

	return false;
}

void CefClientHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();

	if (m_delegate != nullptr)
		m_delegate->OnBrowserClosed(browser);
}

void CefClientHandler::OnLoadError(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	ErrorCode errorCode,
	const CefString& errorText,
	const CefString& failedUrl)
{
	CEF_REQUIRE_UI_THREAD();

	// Don't display an error for downloaded files.
	if (errorCode == ERR_ABORTED)
		return;

	// Display a load error message.
	std::stringstream ss;
	ss << "<html><body bgcolor=\"white\">"
		"<h2>Failed to load URL " << std::string(failedUrl) <<
		" with error " << std::string(errorText) << " (" << errorCode <<
		").</h2></body></html>";
	frame->LoadString(ss.str(), failedUrl);
}

void CefClientHandler::OnLoadingStateChange(CefRefPtr<CefBrowser> browser, bool isLoading, bool canGoBack, bool canGoForward)
{
	CEF_REQUIRE_UI_THREAD();

	if (m_delegate != nullptr)
		m_delegate->OnSetLoadingState(isLoading, canGoBack, canGoForward);
}

void CefClientHandler::CreateBrowser(CefWindowInfo const & info, CefBrowserSettings const & settings, CefString const & url)
{
	CefBrowserHost::CreateBrowser(info, this, url, settings, nullptr);
}

CefClientHandler::~CefClientHandler()
{

}
