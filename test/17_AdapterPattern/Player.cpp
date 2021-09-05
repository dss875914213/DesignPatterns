#include "Player.h"
#include <iostream>

void Forwards::Attack()
{
	cout << "ǰ�� " << m_name << " ����" << endl;
}

void Forwards::Defense()
{
	cout << "ǰ�� " << m_name << " ����" << endl;
}

void Center::Attack()
{
	cout << "�з� " << m_name << " ����" << endl;
}

void Center::Defense()
{
	cout << "�з� " << m_name << " ����" << endl;
}

void Translator::Attack()
{
	wjzf->ChineseAttack();
}

void Translator::Defense()
{
	wjzf->ChineseDefense();
}

void ForeignCenter::ChineseAttack()
{
	cout << "�⼮�з� " << m_name << " ����" << endl;
}

void ForeignCenter::ChineseDefense()
{
	cout << "�⼮�з� " << m_name << " ����" << endl;
}

void ForeignCenter::SetName(string name)
{
	m_name = name;
}

std::string ForeignCenter::GetName()
{
	return m_name;
}
