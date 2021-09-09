#pragma once
#include "Person.h"
class Man;
class Woman;
class Action
{
public:
	virtual void GetManConclusion(Man* concreateElementA)=0;
	virtual void GetWomanConclusion(Woman* concreateElementB)=0;
};

class Success : public Action
{
public:
	void GetManConclusion(Man* concreteElementA) override;
	void GetWomanConclusion(Woman* concreateElementB) override;
};

class Failing : public Action
{
public:
	void GetManConclusion(Man* concreteElementA) override;
	void GetWomanConclusion(Woman* concreateElementB) override;
};

class Amativeness : public Action
{
public:
	void GetManConclusion(Man* concreteElementA) override;
	void GetWomanConclusion(Woman* concreateElementB) override;
};

