#include<iostream>
#include"CashFactory.h"
#include"CashContext.h"


int main()
{
	//CashSuper* cs = CashFactory::createCashAccept("��8��");
	//double result = cs->acceptCash(100);
	//cout << result << endl;
	CashContext* cc = new  CashContext("��8��");
	double result = cc->GetResult(100);
	cout << result << endl;
}





