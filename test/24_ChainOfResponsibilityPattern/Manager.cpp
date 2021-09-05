#include "Manager.h"

Manager::Manager(string name)
{
	m_name = name;
}

void Manager::SetSuperior(Manager* superior)
{
	m_superior = superior;
}

CommonManager::CommonManager(string name):
	Manager(name)
{

}

void CommonManager::RequestApplications(Request* request)
{
	if (request->GetRequestType() == "请假" && request->GetNumber() <= 2)
	{
		cout << m_name << " " << request->GetRequestContent() << " 数量" << request->GetNumber() << "被批准" << endl;
	}
	else
	{
		if (m_superior != nullptr)
		{
			m_superior->RequestApplications(request);
		}
	}
}

Majordomo::Majordomo(string name) :
	Manager(name)
{

}

void Majordomo::RequestApplications(Request* request)
{
	if (request->GetRequestType() == "请假" && request->GetNumber() <= 5)
	{
		cout << m_name << " " << request->GetRequestContent() << " 数量" << request->GetNumber() << "被批准" << endl;
	}
	else
	{
		if (m_superior != nullptr)
		{
			m_superior->RequestApplications(request);
		}
	}
}

GeneralManager::GeneralManager(string name) :
	Manager(name)
{

}

void GeneralManager::RequestApplications(Request* request)
{
	if (request->GetRequestType() == "请假")
	{
		cout << m_name << " " << request->GetRequestContent() << " 数量" << request->GetNumber() << "被批准" << endl;
	}
	else if (request->GetRequestType() == "加薪" && request->GetNumber() <= 500)
	{
		cout << m_name << " " << request->GetRequestContent() << " 数量" << request->GetNumber() << "被批准" << endl;
	}
	else if (request->GetRequestType() == "加薪" && request->GetNumber() > 500)
	{
		cout << m_name << " " << request->GetRequestContent() << " 数量" << request->GetNumber() << "再说吧" << endl;
	}
}