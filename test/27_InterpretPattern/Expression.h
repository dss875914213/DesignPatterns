#pragma once
#include <string>
#include <iostream>
#include "PlayContext.h"
using namespace std;
static int FindBlankPosition(string str);
class Expression
{
public:
	void Interpret(PlayContext* context);
	virtual void Excute(string key, double value) = 0;
};

class Note : public Expression
{
public:
	void Excute(string key, double value) override;
};

class Scale : public Expression
{
public:
	void Excute(string key, double value) override;
};

