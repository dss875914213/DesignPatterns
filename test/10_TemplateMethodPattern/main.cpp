#include <iostream>
#include "TestPaper.h"

using namespace std;
int main()
{
	cout << "学生甲抄的试卷" << endl;
	TestPaper* studentA = new TestPaperA();
	studentA->TestQuestion1();
	studentA->TestQuestion2();

	cout << "学生乙抄的试卷" << endl;
	TestPaper* studentB = new TestPaperB();
	studentB->TestQuestion1();
	studentB->TestQuestion2();
}






