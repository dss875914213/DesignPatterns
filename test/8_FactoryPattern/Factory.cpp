#include "Factory.h"

LeiFeng* SimpleFactory::CreateLeiFeng(string type)
{
	LeiFeng* result = nullptr;
	if (type == "学雷锋的大学生")
	{
		result = new Undergraduate();
	}
	else if (type == "社区志愿者")
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
