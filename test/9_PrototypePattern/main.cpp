#include <iostream>
#include "Prototype.h"

using namespace std;

int main()
{
	Resume* resum1 = new Resume("����");
	resum1->SetPersonalInfo("��", 29);
	resum1->SetWorkExperience("1998-2000", "XX��˾");
	Resume* resum2 = resum1->clone();
	resum2->SetWorkExperience("1998-2006", "YY��ҵ");

	resum1->Display();
	resum2->Display();
	delete resum1;
	delete resum2;
}
