#pragma once
#include "User.h"

class User;
class IUser
{
public:
	virtual void Insert(User* user) = 0;
	virtual User* GetUser(int id) = 0;
};

class SqlserverUser :public IUser
{
public:
	void Insert(User* user) override;
	User* GetUser(int id) override;
};

class AccessUser :public IUser
{
public:
	void Insert(User* user) override;
	User* GetUser(int id) override;
};

