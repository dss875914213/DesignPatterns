#pragma once
class MonsterStatus;

class Monster
{
public:
	Monster(int life);
	~Monster();
	void SetLife(int life);
	int GetLife();
	MonsterStatus* GetCurrentStatus();
	void SetCurrentStatus(MonsterStatus* status);
public:
	void Attacked(int power);
private:
	int m_life;
	MonsterStatus* m_status;
};

