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
	cout << "����õ����������˹���xxx" << endl;
	cout << "��: " << Answer1() << endl;
}

void TestPaper::TestQuestion2()
{
	cout << "�������Ӣxxx" << endl;
	cout << "��: " << Answer2() << endl;
}

std::string TestPaper::Answer1()
{
	return "";
}

std::string TestPaper::Answer2()
{
	return "";
}

