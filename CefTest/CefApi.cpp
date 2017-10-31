#include "stdafx.h"
#include "CefApi.h"


CCefApi::CCefApi()
{
}


CCefApi::~CCefApi()
{
}


void CCefApi::OnBrowserCreated(CefRefPtr<CefBrowser> browser)
{

}

void CCefApi::OnBrowserWindowDestroyed()
{}

void CCefApi::OnSetAddress(const std::string& url)
{}
void CCefApi::OnSetTitle(const std::string& title) 
{}

void CCefApi::OnSetFullscreen(bool fullscreen) 
{}

void CCefApi::OnSetLoadingState(bool isLoading, bool canGoBack, bool canGoForward) 
{}

void CCefApi::OnSetDraggableRegions(const std::vector<CefDraggableRegion>& regions) 
{}