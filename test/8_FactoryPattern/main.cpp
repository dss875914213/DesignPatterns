#include <iostream>
#include "Factory.h"
#include "LeiFeng.h"
using namespace std;

int main()
{
	//LeiFeng* studentA = SimpleFactory::CreateLeiFeng("学雷锋的大学生");
	//studentA->BuyRice();
	//LeiFeng* studentB = SimpleFactory::CreateLeiFeng("学雷锋的大学生");
	//studentB->Sweep();
	//LeiFeng* studentC = SimpleFactory::CreateLeiFeng("学雷锋的大学生");
	//studentC->Wash();
	
	IFactory* factory = new UndergraduateFactory();
	LeiFeng* student = factory->CreateLeiFeng();

	student->BuyRice();
	student->Sweep();
	student->Wash();
}

