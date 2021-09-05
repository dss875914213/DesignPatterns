#pragma once
#include <string>
using namespace std;
#include "Barbecuer.h"
class Command
{
public:
	Command(Barbecuer* receiver);
	virtual void ExceuteCommand() = 0;
	virtual string GetType() = 0;
protected:
	Barbecuer* m_receiver;
};

class BakeMuttonCommand :public Command
{
public:
	BakeMuttonCommand(Barbecuer* receiver);
	void ExceuteCommand() override;
	string GetType() override;
};

class BakeChickenWingCommand :public Command
{
public:
	BakeChickenWingCommand(Barbecuer* receiver);
	void ExceuteCommand() override;
	string GetType() override;

};

