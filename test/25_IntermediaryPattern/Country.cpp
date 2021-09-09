#include "Country.h"

Country::Country(UnitedNations* mediator)
{
	m_mediator = mediator;
}

USA::USA(UnitedNations* mediator):
	Country(mediator)
{

}

void USA::Declare(string message)
{
	m_mediator->Declare(message, this);
}

void USA::GetMessage(string message)
{
	cout << "美国获得对方信息" << message << endl;
}

Irap::Irap(UnitedNations* mediator):
	Country(mediator)
{

}

void Irap::Declare(string message)
{
	m_mediator->Declare(message, this);
}

void Irap::GetMessage(string message)
{
	cout << "伊拉克获得对方信息" << message << endl;
}
