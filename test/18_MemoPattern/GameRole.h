#pragma once
#include "RoleStateMemento.h"

class GameRole
{
public:
	void StateDisplay();
	void GetInitState();
	void Fight();
	RoleStateMemento* SaveState();
	void RecoveryState(RoleStateMemento* memonto);
private:
	int m_vit;
	int m_atk;
	int m_def;
};

