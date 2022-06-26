#include "MonsterStatus.h"
#include "Monster.h"

void MonsterStatus_Feroc::Attacked(int power, Monster* mainobj)
{
	if (mainobj->GetLife() - power > 400)
	{
		mainobj->SetLife(mainobj->GetLife() - power);
		std::cout << "怪物处于凶悍状态中，对主角进行疯狂反击!" << std::endl;
	}
	else
	{
		mainobj->SetCurrentStatus(MonsterStatus_Worr::GetInstance());
		mainobj->GetCurrentStatus()->Attacked(power, mainobj);
	}
}

void MonsterStatus_Worr::Attacked(int power, Monster* mainobj)
{
	if (mainobj->GetLife() - power > 100)
	{
		mainobj->SetLife(mainobj->GetLife() - power);
		std::cout << "怪物处于不安状态中，对主角进行反击并呼唤支援!" << std::endl;
	}
	else
	{
		mainobj->SetCurrentStatus(MonsterStatus_Fear::GetInstance());
		mainobj->GetCurrentStatus()->Attacked(power, mainobj);
	}
}

void MonsterStatus_Fear::Attacked(int power, Monster* mainobj)
{
	if (mainobj->GetLife() - power > 0)
	{
		mainobj->SetLife(mainobj->GetLife() - power); 
		std::cout << "怪物处于恐惧状态中，处于逃跑之中!" << std::endl;
	}
	else
	{
		mainobj->SetCurrentStatus(MonsterStatus_Dead::GetInstance());
		mainobj->GetCurrentStatus()->Attacked(power, mainobj);
	}
}

void MonsterStatus_Dead::Attacked(int power, Monster* mainobj)
{
	if (mainobj->GetLife() > 0)
	{
		mainobj->SetLife(0);
	}

	cout << "怪物死亡！" << endl;
}
