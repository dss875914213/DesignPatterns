#include "StockObserver.h"
#include <iostream>

Observer::Observer(string name)
{
	m_name = name;
}

void StockObserver::StopStock(string msg)
{
	cout << msg << " " << m_name << "�رչ�Ʊ����,��������!" << endl;
}

void NBAObserver::StopNBA(string msg)
{
	cout << msg << " " << m_name << "�ر�NBAֱ������������!" << endl;
}
