#pragma once
#include <string>
using namespace std;
class TestPaper
{
public:
	void TestQuestion1();
	void TestQuestion2();
protected:
	virtual string Answer1();
	virtual string Answer2();
};

class TestPaperA:public TestPaper
{
protected:
	string Answer1() override;
	string Answer2() override;
};

class TestPaperB:public TestPaper
{
protected:
	string Answer1() override;
	string Answer2() override;
};



