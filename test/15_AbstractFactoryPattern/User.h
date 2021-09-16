#pragma once
#include <string>
#include <iostream>
#include "SqlServerUser.h"
#include "Department.h"
using namespace std;
class IUser;

class IFactory
{
public:
	virtual IUser* CreateUser() = 0;
	virtual IDepartment* CreateDepartment() = 0;
};

class SqlServerFactory :public IFactory
{
public:
	IUser* CreateUser() override;
	IDepartment* CreateDepartment() override;
};

class AccessFactory :public IFactory
{
public:
	IUser* CreateUser() override;
	IDepartment* CreateDepartment() override;
};

class User
{
public:
	void SetID(int id);
	int GetID();
	void SetNmae(string name);
	string GetName();

private:
	int m_id;
	string m_name;
};

