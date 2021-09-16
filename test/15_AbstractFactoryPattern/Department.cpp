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
	cout << "在 SQL Server 中给 Department 表增加一条记录" << endl;
}

Department* SqlserverDepartment::GetDepartment(int id)
{
	cout << "在 SQL Server 中根据 ID 得到 Department 表一条记录" << endl;
	return nullptr;
}

void AccessDepartment::Insert(Department* department)
{
	cout << "在 Access 中给 Department 表增加一条记录" << endl;
}

Department* AccessDepartment::GetDepartment(int id)
{
	cout << "在 Access 中根据 ID 得到 Department 表一条记录" << endl;
	return nullptr;
}
