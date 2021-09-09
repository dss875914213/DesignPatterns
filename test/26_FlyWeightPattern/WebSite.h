#pragma once
#include <string>
#include <iostream>
#include "User.h"
using namespace std;

class WebSite
{
public:
	virtual void Use(User* user) = 0;
};

class ConcreteWebSite :public WebSite
{
public:
	ConcreteWebSite(string name);
	void Use(User* user) override;

private:
	string m_name = "";
};

