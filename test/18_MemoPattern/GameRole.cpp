#include "GameRole.h"
#include <string>
#include <iostream>
using namespace std;

void GameRole::StateDisplay()
{
	cout << "��ɫ��ǰ״̬" << endl;
	cout << "����: " << m_vit << endl;
	cout << "������: " << m_vit << endl;
	cout << "������: " << m_vit << endl;

}

void GameRole::GetInitState()
{
	m_vit = 100;
	m_atk = 100;
	m_def = 100;
}

void GameRole::Fight()
{
	m_vit = 0;
	m_atk = 0;
	m_def = 0;
}

RoleStateMemento* GameRole::SaveState()
{
	return new RoleStateMemento(m_vit, m_atk, m_def);
}

void GameRole::RecoveryState(RoleStateMemento* memonto)
{
	m_vit = memonto->GetVitality();
	m_atk = memonto->GetAttck();
	m_def = memonto->GetDefense();
}
