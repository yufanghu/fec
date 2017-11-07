#pragma once
#include <string>

#define CEFCONTEXT CefContext::GetInstance() 
namespace {
	enum eProxyType{
		eSock5, eSock4, eHttp
	};
}
class CefContext
{
public:
	static CefContext* GetInstance(){
		static CefContext * instance = new CefContext();
		return instance;
	}

	void SetCachePath(const std::string & path){ cache_path = path; }
	const  std::string & GetAgentPath() const ;
	const  std::string & GetMainUrl() const;
	void SetAgentPath(const std::string & url){ cache_path = url; }
	void SetMainUrl(const std::string & url){ main_url = url; }
	void SetProxyInfo(const std::string & host, short port, eProxyType proxy_type = eHttp);
	bool GetProxyInfo(std::string & proxyUrl);

private:
	CefContext();
	~CefContext();
	void GetModulePath();
private:
	std::string main_url;
	std::string agent_path;
	std::string cache_path;
	std::string proxy_url;
};

