#include "TestPaper.h"
#include <iostream>
using namespace std;

string TestPaperA::Answer1()
{
	return "b";
}

string TestPaperA::Answer2()
{
	return "a";
}


string TestPaperB::Answer1()
{
	return "d";
}

string TestPaperB::Answer2()
{
	return "b";
}


void TestPaper::TestQuestion1()
{
	cout << "杨过得到，后来给了郭荣xxx" << endl;
	cout << "答案: " << Answer1() << endl;
}

void TestPaper::TestQuestion2()
{
	cout << "杨过、程英xxx" << endl;
	cout << "答案: " << Answer2() << endl;
}

std::string TestPaper::Answer1()
{
	return "";
}

std::string TestPaper::Answer2()
{
	return "";
}

