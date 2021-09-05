#pragma once
#include <vector>
#include <string>
#include <functional>
#include "StockObserver.h"
using namespace std;

class Subject
{
public:
	void Attach(function<void(string)> observer);
	//void Detach(void* observer);
	void Notify();
	void SetAction(string action);
	string GetAction();
private:
	vector<function<void(string)>> m_observers;
	string m_action;
};

class Boss :public Subject
{

};


class Secretary:public Subject
{

};

