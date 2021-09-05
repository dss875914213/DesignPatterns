#include "StockObserver.h"
#include <iostream>

Observer::Observer(string name)
{
	m_name = name;
}

void StockObserver::StopStock(string msg)
{
	cout << msg << " " << m_name << "关闭股票行情,继续工作!" << endl;
}

void NBAObserver::StopNBA(string msg)
{
	cout << msg << " " << m_name << "关闭NBA直播，继续工作!" << endl;
}
