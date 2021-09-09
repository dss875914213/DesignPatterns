#include <iostream>
#include "Country.h"
#include "UnitedNations.h"
using namespace std;
int main()
{
	UnitedNationsSecurityCouncil* UNSC = new UnitedNationsSecurityCouncil();

	USA* c1 = new USA(UNSC);
	Irap* c2 = new Irap(UNSC);

	UNSC->SetColleague1(c1);
	UNSC->SetColleague2(c2);

	c1->Declare("不准研制核武器，否则要发动战争!");
	c2->Declare("我们没有核武器，也不怕侵略。");

}
