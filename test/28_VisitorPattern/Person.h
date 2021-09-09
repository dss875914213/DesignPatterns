#pragma once

#include "Action.h"
class Action;
class Person
{
public:
	virtual void Accept(Action* visitor)=0;
};

class Man : public Person
{
public:
	void Accept(Action* visitor) override;
};

class Woman : public Person
{
public:
	void Accept(Action* visitor) override;
};

