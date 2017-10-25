// CefAgent.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "CefAgent.h"
#include <windows.h>

//sys lib
#pragma comment(lib, "Advapi32.lib")
#pragma comment(lib, "User32.lib")	
#pragma comment(lib, "Ole32.lib")	
#pragma comment(lib, "Dbghelp.lib")	
#pragma comment(lib, "Shell32.lib")	
//cef lib
#pragma comment(lib, "libcef.lib")
#pragma comment(lib, "cef_sandbox.lib")
#pragma comment(lib, "libcef_dll_wrapper.lib")

//#include "cef_sandbox_win.h"
//#include "JccefBrowser.h"
//#include "JccefApp.h"
#include "internal/cef_win.h"
#include "cef_app.h"

int APIENTRY wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	
	CefMainArgs main_args(hInstance);
	return CefExecuteProcess(main_args, NULL, NULL);
}