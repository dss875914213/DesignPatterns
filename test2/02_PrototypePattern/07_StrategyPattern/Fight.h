#pragma once
class ItemStrategy;
class Fighter
{
public:
	Fighter(int life, int magic, int attack);
	virtual ~Fighter();
	void SetItemStrategy(ItemStrategy* stategy);
	void UseItem();
	void SetLife(int life);
	int GetLife();
private:
	int m_life;
	int m_magic;
	int m_attack;

	ItemStrategy* m_itemStategy;
};

class FWarrior :public Fighter
{
public:
	FWarrior(int life, int magic, int attack);
};

class FMage :public Fighter
{
public:
	FMage(int life, int magic, int attack);
};

