#include "Waiter.h"
#include <iostream>
#include <ctime>
using namespace std;

void Waiter::SetOrder(Command* command)
{
	if (command->GetType()=="ChickenWing")
	{
		cout << "服务员: 鸡翅没有了" << endl;
	}
	else
	{
		m_orders.push_back(command);
		cout << "增加订单:" << typeid(command).name() << " 时间: " << time(0) << endl;
	}
}

void Waiter::Notify()
{
	for (auto& order : m_orders)
	{
		order->ExceuteCommand();
	}
}
