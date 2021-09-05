#pragma once
#include <string>
#include <iostream>
#include "Request.h"
using namespace std;
class Manager
{
public:
	Manager(string name);
	void SetSuperior(Manager* superior);
	virtual void RequestApplications(Request* request) = 0;

protected:
	string m_name;
	Manager* m_superior;

};

class CommonManager :public Manager
{
public:
	CommonManager(string name);
	void RequestApplications(Request* request) override;
};


class Majordomo :public Manager
{
public:
	Majordomo(string name);
	void RequestApplications(Request* request) override;
};

class GeneralManager :public Manager
{
public:
	GeneralManager(string name);
	void RequestApplications(Request* request) override;
};


