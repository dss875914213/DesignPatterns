#pragma once
#include<string>
#include<iostream>
using namespace std;

class Person
{
public:
	Person() {}
	Person(string name);
	virtual void Show();

private:
	string m_name;
};



