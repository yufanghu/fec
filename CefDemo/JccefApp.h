#ifndef JC_CEF_APP_H
#define JC_CEF_APP_H

#include "include/cef_app.h"
#include "Jccefhandle.h"

/*****~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**/
class CJcCefApp : public CefApp, public CefBrowserProcessHandler {
public:
	CJcCefApp();
	~CJcCefApp();
	int Init(HINSTANCE hInstance);

	// CefApp methods:
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler()
		OVERRIDE{ return this; }
	/**
	* @brief ����ɳ��ģʽ
	* @param bEnable  true -���� false-����
	* @return ����˵��
	**/
	void EnableSandBox(bool bEnable);
	void Close();
	void Run();
protected:
	// CefBrowserProcessHandler methods:
	virtual void OnContextInitialized() OVERRIDE;

private:
	// Include the default reference counting implementation.
	IMPLEMENT_REFCOUNTING(CJcCefApp);
	bool m_bEnableSandBox;
};

#endif 