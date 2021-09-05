#include "Work.h"
#include <iostream>
#include <string>
using namespace std;

Work::Work()
{
	m_current = new ForenoonState();
}

void Work::WriteProgram()
{
	m_current->WriteProgram(this);
}

void Work::SetHour(int hour)
{
	m_hour = hour;
}

void Work::SetWorkFinished(bool workFinished)
{
	m_workFinished = workFinished;
}

int Work::GetHour()
{
	return m_hour;
}

bool Work::GetWorkFinished()
{
	return m_workFinished;
}

void Work::SetState(State* s)
{
	m_current = s;
}
