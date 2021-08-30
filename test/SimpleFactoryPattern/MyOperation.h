#pragma once
#include<iostream>
using namespace std;

class BaseOperation
{
public:
	void SetNum1(int num1);
	void SetNum2(int num2);
	int GetNum1() const;
	int GetNum2() const;
	virtual double GetResult();

private:
	int m_num1, m_num2;
};

class OperationAdd :public BaseOperation
{
	virtual double GetResult() override;
};

class OperationSub :public BaseOperation
{
	virtual double GetResult() override;
};

class OperationMul :public BaseOperation
{
	virtual double GetResult() override;
};

class OperationDiv :public BaseOperation
{
	virtual double GetResult() override;
};
