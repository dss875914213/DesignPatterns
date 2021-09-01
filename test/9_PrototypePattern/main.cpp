#include <iostream>
#include "Prototype.h"

using namespace std;

int main()
{
	Resume* resum1 = new Resume("大鸟");
	resum1->SetPersonalInfo("男", 29);
	resum1->SetWorkExperience("1998-2000", "XX公司");
	Resume* resum2 = resum1->clone();
	resum2->SetWorkExperience("1998-2006", "YY企业");

	resum1->Display();
	resum2->Display();
	delete resum1;
	delete resum2;
}
