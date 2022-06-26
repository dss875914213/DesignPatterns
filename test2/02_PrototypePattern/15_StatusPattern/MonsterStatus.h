#pragma once
#include <iostream>
using namespace std;
class Monster;

class MonsterStatus
{
public:
	virtual ~MonsterStatus() {}
	virtual void Attacked(int power, Monster* mainobj) = 0;
};

class MonsterStatus_Feroc :public MonsterStatus
{
public:
	void Attacked(int power, Monster* mainobj) override;
public:
	static MonsterStatus_Feroc* GetInstance()
	{
		static MonsterStatus_Feroc instance;
		return &instance;
	}
};

class MonsterStatus_Worr :public MonsterStatus
{
public:
	void Attacked(int power, Monster* mainobj) override;
public:
	static MonsterStatus_Worr* GetInstance()
	{
		static MonsterStatus_Worr instance;
		return &instance;
	}
};

class MonsterStatus_Fear :public MonsterStatus
{
public:
	void Attacked(int power, Monster* mainobj) override;
public:
	static MonsterStatus_Fear* GetInstance()
	{
		static MonsterStatus_Fear instance;
		return &instance;
	}
};

class MonsterStatus_Dead :public MonsterStatus
{
public:
	void Attacked(int power, Monster* mainobj) override;
public:
	static MonsterStatus_Dead* GetInstance()
	{
		static MonsterStatus_Dead instance;
		return &instance;
	}
};
