#include <iostream>
#include "SchoolGirl.h"
#include "Pursuit.h"
using namespace std;

int main()
{
	SchoolGirl* jiaojiao = new SchoolGirl();
	jiaojiao->SetName("���");
	Proxy* daoli = new Proxy(jiaojiao);

	daoli->GiveDolls();
	daoli->GiveFlowers();
	daoli->GiveChocolate();

}


