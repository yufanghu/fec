#include "stdafx.h"
#include "CefContext.h"

#define MAIN_URL "http://www.baidu.com"

CefContext::CefContext() : main_url(MAIN_URL)
{
	GetModulePath();
}


CefContext::~CefContext()
{

}

void CefContext::GetModulePath()
{
	char path[MAX_PATH];
	GetModuleFileNameA(NULL, path, sizeof(path));

	std::string file_path(path);
	std::string::size_type pos = file_path.rfind('\\');
	if (-1 != pos && (pos != file_path.length() - 1)){
		file_path = file_path.substr(0, pos + 1);
	}
	file_path.append("CefAgent.exe");
	agent_path = file_path;
}

const std::string & CefContext::GetAgentPath() const
{
	return agent_path;
}

const std::string & CefContext::GetMainUrl() const
{
	return main_url;
}
