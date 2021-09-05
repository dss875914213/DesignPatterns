#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Company
{

public:
	Company(string name);
	virtual void Add(Company* c) = 0;
	virtual void Remove(Company* c) = 0;
	virtual void Display(int depth) = 0;
	virtual void LineOfDuty() = 0;

protected:
	string m_name;
};

class ConcreateCompany :public Company
{
public:
	ConcreateCompany(string name) : Company(name) {}
	void Add(Company* c) override;
	void Remove(Company* c) override;
	void Display(int depth) override;
	void LineOfDuty() override;

private:
	vector<Company*> m_children;
};

class HRDepartment :public Company
{
public:
	HRDepartment(string name) : Company(name) {}
	void Add(Company* c) override;
	void Remove(Company* c) override;
	void Display(int depth) override;
	void LineOfDuty() override;

private:
};

class FinanceDepartment :public Company
{
public:
	FinanceDepartment(string name) : Company(name) {}
	void Add(Company* c) override;
	void Remove(Company* c) override;
	void Display(int depth) override;
	void LineOfDuty() override;

private:
};

