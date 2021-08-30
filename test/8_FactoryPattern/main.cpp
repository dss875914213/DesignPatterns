#include <iostream>
#include "Factory.h"
#include "LeiFeng.h"
using namespace std;

int main()
{
	//LeiFeng* studentA = SimpleFactory::CreateLeiFeng("ѧ�׷�Ĵ�ѧ��");
	//studentA->BuyRice();
	//LeiFeng* studentB = SimpleFactory::CreateLeiFeng("ѧ�׷�Ĵ�ѧ��");
	//studentB->Sweep();
	//LeiFeng* studentC = SimpleFactory::CreateLeiFeng("ѧ�׷�Ĵ�ѧ��");
	//studentC->Wash();
	
	IFactory* factory = new UndergraduateFactory();
	LeiFeng* student = factory->CreateLeiFeng();

	student->BuyRice();
	student->Sweep();
	student->Wash();
}

