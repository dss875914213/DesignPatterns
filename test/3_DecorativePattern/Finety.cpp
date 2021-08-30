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
	cout << "��T��" << endl;
	m_component->Show();
}

void BigTrouser::Show()
{
	cout << "���" << endl;
	m_component->Show();
}

void Sneakers::Show()
{
	cout << "����Ь" << endl;
	m_component->Show();
}

void Suit::Show()
{
	cout << "��װ" << endl;
	m_component->Show();
}

void Tie::Show()
{
	cout << "���" << endl;
	m_component->Show();
}


void LeatherShoes::Show()
{
	cout << "ƤЬ" << endl;
	m_component->Show();
}

