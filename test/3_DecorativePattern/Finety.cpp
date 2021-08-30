#include "Finery.h"
#include <string>
#include <iostream>
using namespace std;

void Finery::Decorate(Person* component)
{
	m_component = component;
}

void Finery::Show()
{
	if (m_component != nullptr)
	{
		m_component->Show();
	}
}

void TShirts::Show()
{
	cout << "´óTÐô" << endl;
	m_component->Show();
}

void BigTrouser::Show()
{
	cout << "¿å¿ã" << endl;
	m_component->Show();
}

void Sneakers::Show()
{
	cout << "ÆÆÇòÐ¬" << endl;
	m_component->Show();
}

void Suit::Show()
{
	cout << "Î÷×°" << endl;
	m_component->Show();
}

void Tie::Show()
{
	cout << "Áì´ø" << endl;
	m_component->Show();
}


void LeatherShoes::Show()
{
	cout << "Æ¤Ð¬" << endl;
	m_component->Show();
}

