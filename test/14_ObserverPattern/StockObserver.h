#pragma once
#include <string>
#include "Secretary.h"

using namespace std;

class Observer
{
public:
	Observer(string name);
protected:
	string m_name;
};

class StockObserver :public Observer
{
public:
	StockObserver(string name) : Observer(name) {}
	void StopStock(string msg);
};

class NBAObserver :public Observer
{
public:
	NBAObserver(string name) : Observer(name) {}
	void StopNBA(string msg);
};

