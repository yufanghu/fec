
// CefDemo.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

#pragma comment(lib, "libcef.lib")
#pragma comment(lib, "cef_sandbox.lib")
#pragma comment(lib, "libcef_dll_wrapper.lib")

#include "cef_sandbox_win.h"
#include "JccefBrowser.h"
#include "JccefApp.h"
// CCefDemoApp: 
// 有关此类的实现，请参阅 CefDemo.cpp
//

class CCefDemoApp : public CWinApp
{
public:
	CCefDemoApp();

// 重写
public:
	virtual BOOL InitInstance();
	
// 实现

	DECLARE_MESSAGE_MAP()
};

extern CCefDemoApp theApp;