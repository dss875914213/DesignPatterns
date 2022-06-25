#include "Fight.h"
#include "ItemStrategy.h"

Fighter::Fighter(int life, int magic, int attack)
	:m_life(life),
	m_magic(magic),
	m_attack(attack),
	m_itemStategy(nullptr)
{

}

Fighter::~Fighter()
{

}

void Fighter::SetItemStrategy(ItemStrategy* stategy)
{
	m_itemStategy = stategy;
}

void Fighter::UseItem()
{
	m_itemStategy->UseItem(this);
}

void Fighter::SetLife(int life)
{
	m_life = life;
}

int Fighter::GetLife()
{
	return m_life;
}

FWarrior::FWarrior(int life, int magic, int attack)
	:Fighter(life, magic, attack)
{

}

FMage::FMage(int life, int magic, int attack)
	: Fighter(life, magic, attack)
{

}
