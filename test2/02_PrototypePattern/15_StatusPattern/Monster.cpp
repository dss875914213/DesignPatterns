#include "Monster.h"
#include "MonsterStatus.h"

Monster::Monster(int life)
	:m_life(life)
{
	m_status = MonsterStatus_Feroc::GetInstance();
}

Monster::~Monster()
{
}

void Monster::SetLife(int life)
{
	m_life = life;
}

int Monster::GetLife()
{
	return m_life;
}

MonsterStatus* Monster::GetCurrentStatus()
{
	return m_status;
}

void Monster::SetCurrentStatus(MonsterStatus* status)
{
	m_status = status;
}

void Monster::Attacked(int power)
{
	m_status->Attacked(power, this);
}
