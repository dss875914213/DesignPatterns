#include "User.h"

void User::SetID(int id)
{
	m_id = id;
}

int User::GetID()
{
	return m_id;
}

void User::SetNmae(string name)
{
	m_name = name;
}

string User::GetName()
{
	return m_name;
}



IUser* SqlServerFactory::CreateUser()
{
	return new SqlserverUser();
}

IDepartment* SqlServerFactory::CreateDepartment()
{
	return new SqlserverDepartment();
}

IUser* AccessFactory::CreateUser()
{
	return new AccessUser();
}

IDepartment* AccessFactory::CreateDepartment()
{
	return new AccessDepartment();
}
