#include "WorkExperience.h"

WorkExperience::WorkExperience(WorkExperience& rhs)
{
	m_timeArea = rhs.m_timeArea;
	m_company = rhs.m_company;
}

WorkExperience::WorkExperience()
{

}

void WorkExperience::SetTimeArea(string timeArea)
{
	m_timeArea = timeArea;
}

void WorkExperience::SetCompany(string company)
{
	m_company = company;
}

std::string WorkExperience::GetCompany()
{
	return m_company;
}

std::string WorkExperience::GetTimeArea()
{
	return m_timeArea;
}
