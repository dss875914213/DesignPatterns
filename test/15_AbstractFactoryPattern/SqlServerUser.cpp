#include "SqlServerUser.h"
#include <string>
#include <iostream>
using namespace std;

void SqlserverUser::Insert(User* user)
{
	cout << "在 SQL Server 中给User 表增加一条记录" << endl;
}

User* SqlserverUser::GetUser(int id)
{
	cout << "在 SQL Server 中根据 ID 得到 User 表一条记录" << endl;
	return nullptr;
}

void AccessUser::Insert(User* user)
{
	cout << "在 Access 中给User 表增加一条记录" << endl;
}

User* AccessUser::GetUser(int id)
{
	cout << "在 Access 中根据 ID 得到 User 表一条记录" << endl;
	return nullptr;
}
