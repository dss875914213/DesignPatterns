#include<iostream>
#include"CashFactory.h"
#include"CashContext.h"


int main()
{
	//CashSuper* cs = CashFactory::createCashAccept("Дђ8ел");
	//double result = cs->acceptCash(100);
	//cout << result << endl;
	CashContext* cc = new  CashContext("Дђ8ел");
	double result = cc->GetResult(100);
	cout << result << endl;
}





