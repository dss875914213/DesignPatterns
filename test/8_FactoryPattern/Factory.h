#pragma once
#include "LeiFeng.h"
#include <string>
using namespace std;

class SimpleFactory
{
public:
	static LeiFeng* CreateLeiFeng(string type);
};

class IFactory
{
public:
	virtual LeiFeng* CreateLeiFeng() = 0;
};

class UndergraduateFactory : public IFactory
{
public:
	LeiFeng* CreateLeiFeng() override;
};

class VolunteerFactory : public IFactory
{
public:
	LeiFeng* CreateLeiFeng() override;
};


