
// CefDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#pragma comment(lib, "libcef.lib")
#pragma comment(lib, "cef_sandbox.lib")
#pragma comment(lib, "libcef_dll_wrapper.lib")

#include "cef_sandbox_win.h"
#include "JccefBrowser.h"
#include "JccefApp.h"
// CCefDemoApp: 
// �йش����ʵ�֣������ CefDemo.cpp
//

class CCefDemoApp : public CWinApp
{
public:
	CCefDemoApp();

// ��д
public:
	virtual BOOL InitInstance();
	
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCefDemoApp theApp;