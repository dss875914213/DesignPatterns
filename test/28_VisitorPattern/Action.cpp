#include "Action.h"
#include <string>
#include <iostream>
using namespace std;
void Success::GetManConclusion(Man* concreteElementA)
{
	cout << typeid(concreteElementA).name()<<" "<<typeid(this).name()<<"时，背后多半有一个伟大的女人。" << endl;
}

void Success::GetWomanConclusion(Woman* concreateElementB)
{
	cout << typeid(concreateElementB).name() << " " << typeid(this).name() << "时，背后多半有一个不成功的男人。" << endl;
}

void Failing::GetManConclusion(Man* concreteElementA)
{
	cout << typeid(concreteElementA).name() << " " << typeid(this).name() << "时，闷头喝酒，谁也不用劝。" << endl;
}

void Failing::GetWomanConclusion(Woman* concreateElementB)
{
	cout << typeid(concreateElementB).name() << " " << typeid(this).name() << "时，泪眼汪汪，谁也劝不了。" << endl;
}

void Amativeness::GetManConclusion(Man* concreteElementA)
{
	cout << typeid(concreteElementA).name() << " " << typeid(this).name() << "时，凡事不懂也要装懂。" << endl;
}

void Amativeness::GetWomanConclusion(Woman* concreateElementB)
{
	cout << typeid(concreateElementB).name() << " " << typeid(this).name() << "时，遇事懂也要装作不懂。" << endl;
}
