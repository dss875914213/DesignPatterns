#pragma once
#include "RoleStateMemento.h"
class RoleStateCaretaker
{
public:
	void SetMemonto(RoleStateMemento* memento);
	RoleStateMemento* GetMemonto();
private:
	RoleStateMemento* m_memento;
};

