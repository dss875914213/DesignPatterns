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

	c1->Declare("��׼���ƺ�����������Ҫ����ս��!");
	c2->Declare("����û�к�������Ҳ�������ԡ�");

}
