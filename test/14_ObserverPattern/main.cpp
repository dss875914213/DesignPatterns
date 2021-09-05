#include <iostream>
#include <functional>
#include "Secretary.h"
#include "StockObserver.h"

using namespace std;
int main()
{
	Subject* boss = new Boss();
	StockObserver* tongshi1 = new StockObserver("魏关姹");
	NBAObserver* tongshi2 = new NBAObserver("易管查");
	using std::placeholders::_1;

	boss->Attach(std::bind(&StockObserver::StopStock, tongshi1, _1));
	boss->Attach(std::bind(&NBAObserver::StopNBA, tongshi2, _1));

	//boss->Detach(tongshi2);

	boss->SetAction("我胡汉三回来了!");

	boss->Notify();

}
