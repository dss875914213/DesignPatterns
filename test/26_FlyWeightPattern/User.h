#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
public:
	User(string name);
	string GetName();

private:
	string m_name;
};

