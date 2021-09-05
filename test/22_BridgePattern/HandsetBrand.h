#pragma once
#include "HandsetSoft.h"

class HandsetBrand
{
public:
	void SethandsetSoft(HandsetSoft* soft);
	virtual void Run() = 0;

protected:
	HandsetSoft* m_pSoft;
};

class HandsetBrandN :public HandsetBrand
{
public:
	void Run() override;
};

class HandsetBrandM :public HandsetBrand
{
public:
	void Run() override;
};

