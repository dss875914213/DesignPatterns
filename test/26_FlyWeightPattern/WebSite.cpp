#include "WebSite.h"

ConcreteWebSite::ConcreteWebSite(string name)
{
	m_name = name;
}

void ConcreteWebSite::Use(User* user)
{
	cout << "��վ���ࣺ " << m_name<<"�û�: "<<user->GetName() << endl;
}
