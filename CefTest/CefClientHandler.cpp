#include "stdafx.h"
#include "CefClientHandler.h"
#include "include/wrapper/cef_helpers.h"
#include "browser/main_context.h"
#include "browser/root_window_manager.h"

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

bool CefClientHandler::OnBeforePopup(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& target_url, const CefString& target_frame_name, CefLifeSpanHandler::WindowOpenDisposition target_disposition, bool user_gesture, const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo, CefRefPtr<CefClient>& client, CefBrowserSettings& settings, bool* no_javascript_access)
{
	CEF_REQUIRE_UI_THREAD();
	//ShowDevTools(browser, CefPoint(params->GetXCoord(), params->GetYCoord()));
	return TRUE;
}

bool CefClientHandler::OnPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent& event, CefEventHandle os_event, bool* is_keyboard_shortcut)
{
	CEF_REQUIRE_UI_THREAD();

	if (!event.focus_on_editable_field && event.windows_key_code == 0x20) {
		// Special handling for the space character when an input element does not
		// have focus. Handling the event in OnPreKeyEvent() keeps the event from
		// being processed in the renderer. If we instead handled the event in the
		// OnKeyEvent() method the space key would cause the window to scroll in
		// addition to showing the alert box.
		if (event.type == KEYEVENT_RAWKEYDOWN)
			//test_runner::Alert(browser, "You pressed the space bar!");
			return true;
	}

	if (!event.focus_on_editable_field)
	{
		switch (event.windows_key_code)
		{
		case VK_F5:
			//browser->Reload();
			ShowDevTools(browser, CefPoint());
			return true;
		default:
			return false;
		}
	}

	return false;
}


void CefClientHandler::ShowDevTools(CefRefPtr<CefBrowser> browser,
	const CefPoint& inspect_element_at) {
	if (!CefCurrentlyOn(TID_UI)) {
		// Execute this method on the UI thread.
		/*CefPostTask(TID_UI, base::Bind(&CefClientHandler::ShowDevTools, this, browser,
			inspect_element_at));*/
		return;
	}

	CefWindowInfo windowInfo;
	CefBrowserSettings settings;

#if defined(OS_WIN)
	windowInfo.SetAsPopup(browser->GetHost()->GetWindowHandle(), "DevTools");
#endif

	browser->GetHost()->ShowDevTools(windowInfo, this, settings,
		inspect_element_at);
}