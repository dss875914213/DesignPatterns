#include "Cash.h"


double CashNormal::acceptCash(double money)
{
	return money;
}

CashRebate::CashRebate(double moneyRedate)
{
	m_moneyDebate = moneyRedate;
}

double CashRebate::acceptCash(double money)
{
	return money * m_moneyDebate;
}


CashReturn::CashReturn(double moneyCondition, double moneyReturn)
{
	m_moneyCondition = moneyCondition;
	m_moneyReturn = moneyReturn;
}

double CashReturn::acceptCash(double money)
{
	double result = money;
	if (money >= m_moneyCondition)
	{
		result -= money/m_moneyCondition*m_moneyReturn;
	}
	return result;
}

