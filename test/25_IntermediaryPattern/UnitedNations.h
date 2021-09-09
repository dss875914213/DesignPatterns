#pragma once
#include <string>
#include <iostream>
#include "Country.h"
using namespace std;

class Country;


class UnitedNations
{
public:
	virtual void Declare(string message, Country* colleague)=0;
};

class USA;
class Irap;
class UnitedNationsSecurityCouncil : public UnitedNations
{
public:
	void Declare(string message, Country* colleague) override;
	void SetColleague1(USA* colleague);
	void SetColleague2(Irap* colleague);

private:
	USA* colleague1;
	Irap* colleague2;
};

