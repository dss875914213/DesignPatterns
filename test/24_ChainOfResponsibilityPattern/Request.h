#pragma once
#include <string>
#include <iostream>
using namespace std;
class Request
{
public:
	void SetRequestType(string requestType);
	string GetRequestType();
	void SetRequestContent(string requestContent);
	string GetRequestContent();
	void SetNumber(int number);
	int GetNumber();

private:
	string m_requestType;
	string m_requestContent;
	int m_number;
};

