#pragma once
#include <vector>
using namespace std;
#include "Command.h"

class Waiter
{
public:
	void SetOrder(Command* command);
	void CancelOrder(Command* command);
	void Notify();

private:
	Command* m_command;
	vector<Command*> m_orders;
};

