#pragma once
#include "UnitedNations.h"
#include <string>
#include <iostream>
#include "Country.h"
using namespace std;

class UnitedNations;
class Country
{
public:
	Country(UnitedNations* mediator);
protected:
	UnitedNations* m_mediator;
};

class USA : public Country
{
public:
	USA(UnitedNations* mediator);
	void Declare(string message);
	void GetMessage(string message);
};

class Irap : public Country
{
public:
	Irap(UnitedNations* mediator);
	void Declare(string message);
	void GetMessage(string message);
};

