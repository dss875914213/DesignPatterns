#include "Prototype.h"
#include <iostream>
using namespace std;

Resume::Resume(string name)
{
	m_name = name;
	m_work = new WorkExperience();
}

Resume::Resume(const Resume& rhs)
{
	m_name = rhs.m_name;
	m_sex = rhs.m_sex;  
	m_age = rhs.m_age;
	m_work = new WorkExperience(*rhs.m_work);
}

Resume::~Resume()
{
	delete m_work;
}


void Resume::SetPersonalInfo(string sex, int age)
{
	m_sex = sex;
	m_age = age;
}

void Resume::SetWorkExperience(string timeArea, string company)
{
	m_work->SetTimeArea(timeArea);
	m_work->SetCompany(company);
}

void Resume::Display()
{
	cout << m_name << " " << m_sex << " " << m_age << endl;
	cout << "工作经历: " << m_work->GetTimeArea() << " " << m_work->GetCompany() << endl;
}

Resume* Resume::clone()
{
	cout << "copy of self" << endl;
	return new Resume(*this);
}


