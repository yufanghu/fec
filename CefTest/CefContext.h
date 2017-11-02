#pragma once
#include <string>


class CefContext
{
public:
	void SetCachePath(const std::string & path){ cache_path = path; }
	void SetAgentPath(const std::string & url){ cache_path = url; }
	void SetMainUrl(const std::string & url){ main_url = url; }
	
	std::string main_url;
	std::string agent_path;
	std::string cache_path;
private:
	CefContext();
	~CefContext();
	void GetModulePath();
};

