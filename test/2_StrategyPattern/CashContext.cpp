#include "CashContext.h"

CashContext::CashContext(string type)
{
	if (type == "正常收费")
	{
		m_cs = new CashNormal();
	}
	else if (type == "满300返100")
	{
		m_cs = new CashReturn(300, 100);
	}
	else if (type == "打8折")
	{
		m_cs = new CashRebate(0.8);
	}
}

double CashContext::GetResult(double money)
{
	return m_cs->acceptCash(money);
}


