#include "Waiter.h"
#include <iostream>
#include <ctime>
using namespace std;

void Waiter::SetOrder(Command* command)
{
	if (command->GetType()=="ChickenWing")
	{
		cout << "����Ա: ����û����" << endl;
	}
	else
	{
		m_orders.push_back(command);
		cout << "���Ӷ���:" << typeid(command).name() << " ʱ��: " << time(0) << endl;
	}
}

void Waiter::Notify()
{
	for (auto& order : m_orders)
	{
		order->ExceuteCommand();
	}
}
