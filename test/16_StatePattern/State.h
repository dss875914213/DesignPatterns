#pragma once
#include "Work.h"
#include <iostream>
#include <string>
using namespace std;

class Work;
class State
{
public:
	virtual void WriteProgram(Work* w)=0;
};

class ForenoonState :public State
{
public:
	void WriteProgram(Work* w) override;
};

class NoonState :public State
{
public:
	void WriteProgram(Work* w) override;
};

class AfternoonState :public State
{
public:
	void WriteProgram(Work* w) override;
};

class EveningState :public State
{
public:
	void WriteProgram(Work* w) override;
};

class SleepingState :public State
{
public:
	void WriteProgram(Work* w) override;
};

class RestState :public State
{
public:
	void WriteProgram(Work* w) override;
};

