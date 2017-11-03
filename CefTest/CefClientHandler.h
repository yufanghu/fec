#pragma once
#include "include/base/cef_lock.h"
#include "include/cef_client.h"

class CefClientHandler : 
	public CefClient,
	public CefDisplayHandler,
	public CefLifeSpanHandler,
	public CefLoadHandler,
	public CefKeyboardHandler{
public:
	// Implement this interface to receive notification of ClientHandler
	// events. The methods of this class will be called on the main thread.
	class Delegate
	{
	public:
		// Called when the browser is created.
		virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser) = 0;

		// Called when the browser is closing.
		virtual void OnBrowserClosing(CefRefPtr<CefBrowser> browser) = 0;

		// Called when the browser has been closed.
		virtual void OnBrowserClosed(CefRefPtr<CefBrowser> browser) = 0;

		// Set the window URL address.
		virtual void OnSetAddress(std::string const & url) = 0;

		// Set the window title.
		virtual void OnSetTitle(std::string const & title) = 0;

		// Set fullscreen mode.
		virtual void OnSetFullscreen(bool const fullscreen) = 0;

		// Set the loading state.
		virtual void OnSetLoadingState(bool const isLoading,
			bool const canGoBack,
			bool const canGoForward) = 0;

	protected:
		virtual ~Delegate() {}
	};

public:
	CefClientHandler(Delegate* delegate);
	~CefClientHandler();

	void CreateBrowser(CefWindowInfo const & info, CefBrowserSettings const & settings, CefString const & url);
	// Delegate to detach itself before destruction.
	void DetachDelegate();
	// CefClient methods
	CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() OVERRIDE{ return this; }
private:
	// CefClient methods:
	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override { return this; }
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override { return this; }
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override { return this; }

	// CefKeyboardHandler methods
	bool OnPreKeyEvent(CefRefPtr<CefBrowser> browser,
		const CefKeyEvent& event,
		CefEventHandle os_event,
		bool* is_keyboard_shortcut) OVERRIDE;

	// CefDisplayHandler methods:
	virtual void OnAddressChange(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& url) override;
	virtual void OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title) override;
	virtual void OnFullscreenModeChange(CefRefPtr<CefBrowser> browser, bool fullscreen) override;

	// CefLifeSpanHandler methods:
	// CefLifeSpanHandler methods
	bool OnBeforePopup(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		const CefString& target_url,
		const CefString& target_frame_name,
		CefLifeSpanHandler::WindowOpenDisposition target_disposition,
		bool user_gesture,
		const CefPopupFeatures& popupFeatures,
		CefWindowInfo& windowInfo,
		CefRefPtr<CefClient>& client,
		CefBrowserSettings& settings,
		bool* no_javascript_access) OVERRIDE;
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
	virtual bool DoClose(CefRefPtr<CefBrowser> browser) override;
	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

	// CefLoadHandler methods:
	virtual void OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
		bool isLoading,
		bool canGoBack,
		bool canGoForward) override;

	virtual void OnLoadError(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		ErrorCode errorCode,
		const CefString& errorText,
		const CefString& failedUrl) override;

	// This object may outlive the Delegate object so it's necessary for the
	
	// Create a new popup window using the specified information. |is_devtools|
	// will be true if the window will be used for DevTools. Return true to
	// proceed with popup browser creation or false to cancel the popup browser.
	// May be called on any thead.
	bool CreatePopupWindow(CefRefPtr<CefBrowser> browser,
		bool is_devtools,
		const CefPopupFeatures& popupFeatures,
		CefWindowInfo& windowInfo,
		CefRefPtr<CefClient>& client,
		CefBrowserSettings& settings);
	// Show a new DevTools popup window.
	void ShowDevTools(CefRefPtr<CefBrowser> browser,
		const CefPoint& inspect_element_at);

private:

	// Include the default reference counting implementation.
	IMPLEMENT_REFCOUNTING(CefClientHandler);
	// Include the default locking implementation.
	IMPLEMENT_LOCKING(CefClientHandler);

private:
	Delegate* m_delegate;
};
