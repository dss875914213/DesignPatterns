#include "Company.h"

void ConcreateCompany::Add(Company* c)
{
	m_children.push_back(c);
}

void ConcreateCompany::Remove(Company* c)
{
	//auto index = std::move(m_children.begin(), m_children.end(), c);
}

void ConcreateCompany::Display(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}
	cout << m_name << endl;
	for (auto& component : m_children)
	{
		component->Display(depth + 2);
	}
}

void ConcreateCompany::LineOfDuty()
{
	for (auto& component : m_children)
	{
		component->LineOfDuty();
	}
}

void HRDepartment::Add(Company* c)
{

}

void HRDepartment::Remove(Company* c)
{

}

void HRDepartment::Display(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}
	cout << m_name << endl;
}

void HRDepartment::LineOfDuty()
{
	cout << m_name << " 员工招聘培训管理" << endl;
}

void FinanceDepartment::Add(Company* c)
{

}

void FinanceDepartment::Remove(Company* c)
{

}

void FinanceDepartment::Display(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}
	cout << m_name << endl;
}

void FinanceDepartment::LineOfDuty()
{
	cout << m_name << " 公司财务收支管理" << endl;
}

Company::Company(string name)
{
	m_name = name;
}
