#include"MyOperation.h"

void BaseOperation::SetNum1(int num1)
{
	m_num1 = num1;
}

void BaseOperation::SetNum2(int num2)
{
	m_num2 = num2;
}

int BaseOperation::GetNum1() const
{
	return m_num1;
}

int BaseOperation::GetNum2() const
{
	return m_num2;
}

double BaseOperation::GetResult()
{
	double result = 0.0;
	return result;
}


double OperationAdd::GetResult()
{
	return GetNum1() + GetNum2();
}

double OperationSub::GetResult()
{
	return GetNum1() - GetNum2();
}

double OperationMul::GetResult()
{
	return GetNum1() * GetNum2();
}

double OperationDiv::GetResult()
{
	if (GetNum2() == 0)
	{
		cout << "除数不能为0" << endl;
	}
	return GetNum1() / GetNum2();
}