#pragma once
#include <string>
using namespace std;

class WorkExperience
{
public:
	WorkExperience();
	WorkExperience(WorkExperience& rhs);
	void SetTimeArea(string timeArea);
	void SetCompany(string company);
	string GetCompany();
	string GetTimeArea();
private:
	string m_timeArea;
	string m_company;
};

