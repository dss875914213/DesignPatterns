#include "WebSite.h"

ConcreteWebSite::ConcreteWebSite(string name)
{
	m_name = name;
}

void ConcreteWebSite::Use(User* user)
{
	cout << "网站分类： " << m_name<<"用户: "<<user->GetName() << endl;
}
