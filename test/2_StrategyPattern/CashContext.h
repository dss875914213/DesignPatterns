#pragma once
#include<string>
using namespace std;
#include"Cash.h"
class CashContext
{
public:
	CashContext(string type);
	double GetResult(double money);
	
private:
	CashSuper* m_cs;
};

