// 实现一个计算器控制台程序，要求输入两个数和运算符号，得到结果

#include<iostream>
#include"MyOperation.h"
using namespace std;

class OperationFactory
{
public:
	static BaseOperation* createOperate(string tempOperate)
	{
		BaseOperation* oper = nullptr;
		if (tempOperate == "+")
		{
			oper = new OperationAdd();
		}
		else if (tempOperate == "-")
		{
			oper = new OperationSub();
		}
		else if (tempOperate == "*")
		{
			oper = new OperationMul();
		}
		else if (tempOperate == "/")
		{
			oper = new OperationDiv();
		}
		return oper;
	}
};

int main()
{
	try
	{
		int num1, num2;
		string myOperator;
		cout << "请输入数字A: " << endl;
		cin >> num1;
		cout << "请输入运算符(+、-、*、/): ";
		cin >> myOperator;
		cout << "请输入数字B: " << endl;
		cin >> num2;
		
		BaseOperation* oper = OperationFactory::createOperate(myOperator);
		oper->SetNum1(num1);
		oper->SetNum2(num2);
		double result = oper->GetResult();
		cout << result << endl;
		
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
	return 0;
}



