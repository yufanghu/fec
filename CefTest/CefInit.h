#pragma once
#include <string>
#include "include/internal/cef_types_wrappers.h"

class CefInit
{
public:
	static CefInit* GetInstance(){
		static CefInit * instance = new CefInit();
		return instance;
	}

	CefInit();
	~CefInit();
	void WebInit();
private:
	CefSettings m_cefSetting;
};

