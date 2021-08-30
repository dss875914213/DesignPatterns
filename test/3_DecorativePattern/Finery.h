#pragma once
#include "Person.h"
class Finery:public Person
{
public:
	Finery() { ; }
	void Decorate(Person* component);
	void Show() override;
protected:
	Person* m_component = nullptr;
};

class TShirts :public Finery
{
public:
	void Show() override;
};

class BigTrouser :public Finery
{
public:
	void Show() override;
};

class Sneakers :public Finery
{
public:
	void Show() override;
};

class Suit :public Finery
{
public:
	void Show() override;
};

class Tie :public Finery
{
public:
	void Show() override;
};

class LeatherShoes :public Finery
{
public:
	void Show() override;
};

