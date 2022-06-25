#pragma once
#include "Fight.h"

class Fighter;
class ItemStrategy
{
public:
	virtual ~ItemStrategy() {}
	virtual void UseItem(Fighter* mainobj) = 0;
};

class ItemStrategy_BXD :public ItemStrategy
{
public:
	void UseItem(Fighter* mainobj) override
	{
		mainobj->SetLife(mainobj->GetLife() + 200);
	}
};

class ItemStrategy_DHD :public ItemStrategy
{
public:
	void UseItem(Fighter* mainobj) override
	{
		mainobj->SetLife(mainobj->GetLife() + 300);
	}
};

class ItemStrategy_SHD :public ItemStrategy
{
public:
	// 为什么不能使用 override
	void UseItem(Fighter* mainobj) override
	{
		mainobj->SetLife(mainobj->GetLife() + 500);
	}
};
