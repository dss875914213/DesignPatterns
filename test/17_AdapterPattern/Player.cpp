#include "Player.h"
#include <iostream>

void Forwards::Attack()
{
	cout << "Ç°·æ " << m_name << " ½ø¹¥" << endl;
}

void Forwards::Defense()
{
	cout << "Ç°·æ " << m_name << " ·ÀÊØ" << endl;
}

void Center::Attack()
{
	cout << "ÖÐ·æ " << m_name << " ½ø¹¥" << endl;
}

void Center::Defense()
{
	cout << "ÖÐ·æ " << m_name << " ·ÀÊØ" << endl;
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
	cout << "Íâ¼®ÖÐ·æ " << m_name << " ½ø¹¥" << endl;
}

void ForeignCenter::ChineseDefense()
{
	cout << "Íâ¼®ÖÐ·æ " << m_name << " ·ÀÊØ" << endl;
}

void ForeignCenter::SetName(string name)
{
	m_name = name;
}

std::string ForeignCenter::GetName()
{
	return m_name;
}
