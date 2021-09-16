#include "Department.h"

#include <string>
#include <iostream>
using namespace std;

void Department::SetID(int id)
{
	m_id = id;
}

int Department::GetID()
{
	return m_id;
}

void Department::SetName(string name)
{
	m_deptName = name;
}

std::string Department::GetName()
{
	return m_deptName;
}

void SqlserverDepartment::Insert(Department* department)
{
	cout << "�� SQL Server �и� Department ������һ����¼" << endl;
}

Department* SqlserverDepartment::GetDepartment(int id)
{
	cout << "�� SQL Server �и��� ID �õ� Department ��һ����¼" << endl;
	return nullptr;
}

void AccessDepartment::Insert(Department* department)
{
	cout << "�� Access �и� Department ������һ����¼" << endl;
}

Department* AccessDepartment::GetDepartment(int id)
{
	cout << "�� Access �и��� ID �õ� Department ��һ����¼" << endl;
	return nullptr;
}
