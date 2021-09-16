#pragma once
#include <string>
#include <iostream>
using namespace std;

class Department
{
public:
	void SetID(int id);
	int GetID();
	void SetName(string name);
	string GetName();

private:
	int m_id;
	string m_deptName;

};

class IDepartment
{
public:
	virtual void Insert(Department* department) = 0;
	virtual Department* GetDepartment(int id) = 0;
};

class SqlserverDepartment : public IDepartment
{
public:
	void Insert(Department* department) override;
	Department* GetDepartment(int id) override;
};

class AccessDepartment : public IDepartment
{
public:
	void Insert(Department* department) override;
	Department* GetDepartment(int id) override;
};

