#include<string>
#include<iostream>
#include"Person.h"
#include "Finery.h"
using namespace std;

int main()
{
	Person* xc = new Person("小菜");
	cout << "第一种装扮" << endl;
	Sneakers* pqx = new Sneakers();
	BigTrouser* kk = new BigTrouser();
	TShirts* dtx = new TShirts();
	pqx->Decorate(xc);
	kk->Decorate(pqx);
	dtx->Decorate(kk);
	dtx->Show();

}


