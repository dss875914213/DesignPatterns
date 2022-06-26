#include "MonsterStatus.h"
#include "Monster.h"

void MonsterStatus_Feroc::Attacked(int power, Monster* mainobj)
{
	if (mainobj->GetLife() - power > 400)
	{
		mainobj->SetLife(mainobj->GetLife() - power);
		std::cout << "���ﴦ���׺�״̬�У������ǽ��з�񷴻�!" << std::endl;
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
		std::cout << "���ﴦ�ڲ���״̬�У������ǽ��з���������֧Ԯ!" << std::endl;
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
		std::cout << "���ﴦ�ڿ־�״̬�У���������֮��!" << std::endl;
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

	cout << "����������" << endl;
}
