#include "Factory.h"

LeiFeng* SimpleFactory::CreateLeiFeng(string type)
{
	LeiFeng* result = nullptr;
	if (type == "ѧ�׷�Ĵ�ѧ��")
	{
		result = new Undergraduate();
	}
	else if (type == "����־Ը��")
	{
		result = new Volunteer();
	}
	return result;
}

LeiFeng* UndergraduateFactory::CreateLeiFeng()
{
	return new Undergraduate();
}

LeiFeng* VolunteerFactory::CreateLeiFeng()
{
	return new Volunteer();
}
