#pragma once
class HandsetSoft
{
public:
	virtual void Run() = 0;
};

class HandsetGame : public HandsetSoft
{
public:
	void Run() override;
};

class HandsetAddressList :public HandsetSoft
{
public:
	void Run() override;
};

