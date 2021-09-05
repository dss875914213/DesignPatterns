#include <iostream>
#include <functional>
#include "Secretary.h"
#include "StockObserver.h"

using namespace std;
int main()
{
	Subject* boss = new Boss();
	StockObserver* tongshi1 = new StockObserver("κ���");
	NBAObserver* tongshi2 = new NBAObserver("�׹ܲ�");
	using std::placeholders::_1;

	boss->Attach(std::bind(&StockObserver::StopStock, tongshi1, _1));
	boss->Attach(std::bind(&NBAObserver::StopNBA, tongshi2, _1));

	//boss->Detach(tongshi2);

	boss->SetAction("�Һ�����������!");

	boss->Notify();

}
