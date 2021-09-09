#include "WebSiteFactory.h"

WebSite* WebSiteFactory::GetWebSiteCategory(string key)
{
	if (m_flyWeights.find(key) == m_flyWeights.end())
	{
		m_flyWeights[key] = new ConcreteWebSite(key);
	}
	return static_cast<WebSite*>(m_flyWeights[key]);
}

int WebSiteFactory::GetWebSiteCount()
{
	return m_flyWeights.size();
}
