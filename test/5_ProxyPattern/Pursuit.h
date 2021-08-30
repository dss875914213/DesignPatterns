#pragma once
#include "SchoolGirl.h"

class IGiveGift
{
	virtual void GiveDolls() = 0;
	virtual void GiveFlowers() = 0;
	virtual void GiveChocolate() = 0;
};

class Pursuit:IGiveGift
{
public:
	Pursuit(SchoolGirl* mm);
	void GiveDolls() override;
	void GiveFlowers() override;
	void GiveChocolate() override;
private:
	SchoolGirl* m_mm;
};

class Proxy :IGiveGift
{
public:
	Proxy(SchoolGirl* mm);
	void GiveDolls() override;
	void GiveFlowers() override;
	void GiveChocolate() override;
private:
	Pursuit* m_gg;
};

