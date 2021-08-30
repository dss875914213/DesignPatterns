#pragma once
#include"Cash.h"
#include<string>
using namespace std;
class CashFactory
{
public:
	static CashSuper* createCashAccept(string type);
};

