#include "RoleStateMemento.h"

RoleStateMemento::RoleStateMemento(int vit, int atk, int def)
{
	m_vit = vit;
	m_atk = atk;
	m_def = def;
}

void RoleStateMemento::SetVitality(int vit)
{
	m_vit = vit;
}

int RoleStateMemento::GetVitality()
{
	return m_vit;
}

void RoleStateMemento::SetAttck(int atk)
{
	m_atk = atk;
}

int RoleStateMemento::GetAttck()
{
	return m_atk;
}

void RoleStateMemento::SetDefense(int def)
{
	m_def = def;
}

int RoleStateMemento::GetDefense()
{
	return m_def;
}


