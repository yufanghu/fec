#include "stdafx.h"
#include "CefContext.h"

#define MAIN_URL "http://www.baidu.com"

CefContext::CefContext() : main_url(MAIN_URL), 
user_agent_("Mozilla/5.0 (Windows NT 6.1;WOW64)AppleWebKit/537.22(KHTML,like Gecko) Chrome/25.0.1364.152 Safari/537.22")
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

void CefContext::SetProxyInfo(const std::string & host, short port, eProxyType proxy_type /*= eHttp*/)
{
	//std::string 
	proxy_url = "";
	if (eHttp == proxy_type){
		proxy_url += "http://";
	}
	else if (eSock5 == proxy_type){
		proxy_url += "socks5://";
	}
	else if (eSock4 == proxy_type){
		proxy_url += "socks4://";
	}

	proxy_url += host;
	char buf[10] = { 0 };
	_itoa_s(port, buf, 10);
	proxy_url += ":";
	proxy_url += buf;
}

bool CefContext::GetProxyInfo(std::string & proxyUrl)
{
	if (!proxy_url.empty()){
		proxyUrl = proxy_url;
		return true;
	}
	return false;
}

const std::string & CefContext::GetUserAgent() const
{
	return user_agent_;
}
