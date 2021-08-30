#include "Pursuit.h"
#include <iostream>
using namespace std;

Pursuit::Pursuit(SchoolGirl* mm)
{
	m_mm = mm;
}

void Pursuit::GiveDolls()
{
	cout << m_mm->GetName() << " ����������" << endl;
}

void Pursuit::GiveFlowers()
{
	cout << m_mm->GetName() << " ���㻨" << endl;
}

void Pursuit::GiveChocolate()
{
	cout << m_mm->GetName() << " �����ɿ���" << endl;
}

Proxy::Proxy(SchoolGirl* mm)
{
	m_gg = new Pursuit(mm);
}

void Proxy::GiveDolls()
{
	m_gg->GiveDolls();
}

void Proxy::GiveFlowers()
{
	m_gg->GiveFlowers();
}

void Proxy::GiveChocolate()
{
	m_gg->GiveChocolate();
}








