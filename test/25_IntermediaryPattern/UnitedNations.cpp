#include "UnitedNations.h"

void UnitedNationsSecurityCouncil::Declare(string message, Country* colleague)
{
	if (colleague == (Country*)colleague1)
	{
		colleague2->GetMessage(message);
	}
	else
	{
		colleague1->GetMessage(message);
	}
}

void UnitedNationsSecurityCouncil::SetColleague1(USA* colleague)
{
	colleague1 = colleague;
}

void UnitedNationsSecurityCouncil::SetColleague2(Irap* colleague)
{
	colleague2 = colleague;
}
