#pragma once
#include <unordered_map>
#include <string>
#include "WebSite.h"
using namespace std;

class WebSiteFactory
{
public:
	WebSite* GetWebSiteCategory(string key);
	int GetWebSiteCount();

private:
	unordered_map<string, WebSite*> m_flyWeights;
};

