#include "SqlServerUser.h"
#include <string>
#include <iostream>
using namespace std;

void SqlserverUser::Insert(User* user)
{
	cout << "�� SQL Server �и�User ������һ����¼" << endl;
}

User* SqlserverUser::GetUser(int id)
{
	cout << "�� SQL Server �и��� ID �õ� User ��һ����¼" << endl;
	return nullptr;
}

void AccessUser::Insert(User* user)
{
	cout << "�� Access �и�User ������һ����¼" << endl;
}

User* AccessUser::GetUser(int id)
{
	cout << "�� Access �и��� ID �õ� User ��һ����¼" << endl;
	return nullptr;
}
