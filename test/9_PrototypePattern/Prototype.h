#pragma once
#include <string>
#include "WorkExperience.h"
using namespace std;

class Prototype
{
public:
	Prototype() {}
	~Prototype() {}
	virtual Prototype* clone() = 0;
};

class Resume :public Prototype
{
public:
	Resume(string name);
	~Resume();

	void SetPersonalInfo(string sex, int age);
	void SetWorkExperience(string timeArea, string company);
	void Display();

	Resume(const Resume& rhs);

	virtual Resume* clone();

private:
	string m_name;
	string m_sex;
	int m_age;
	WorkExperience* m_work;
};

