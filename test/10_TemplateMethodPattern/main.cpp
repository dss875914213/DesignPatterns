#include <iostream>
#include "TestPaper.h"

using namespace std;
int main()
{
	cout << "ѧ���׳����Ծ�" << endl;
	TestPaper* studentA = new TestPaperA();
	studentA->TestQuestion1();
	studentA->TestQuestion2();

	cout << "ѧ���ҳ����Ծ�" << endl;
	TestPaper* studentB = new TestPaperB();
	studentB->TestQuestion1();
	studentB->TestQuestion2();
}






