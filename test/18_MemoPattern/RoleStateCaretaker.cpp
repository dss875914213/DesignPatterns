#include "RoleStateCaretaker.h"

void RoleStateCaretaker::SetMemonto(RoleStateMemento* memento)
{
	m_memento = memento;
}

RoleStateMemento* RoleStateCaretaker::GetMemonto()
{
	return m_memento;
}
