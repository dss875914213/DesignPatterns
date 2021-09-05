#pragma once
#include "State.h"

class State;
class Work
{
public:
	Work();
	void WriteProgram();
	void SetHour(int hour);
	void SetWorkFinished(bool workFinished);
	int GetHour();
	bool GetWorkFinished();
	void SetState(State* s);

private:
	int m_hour = 0;
	bool m_workFinished = false;
	State* m_current;
};

