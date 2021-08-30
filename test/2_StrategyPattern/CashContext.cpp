#include "CashContext.h"

CashContext::CashContext(string type)
{
	if (type == "�����շ�")
	{
		m_cs = new CashNormal();
	}
	else if (type == "��300��100")
	{
		m_cs = new CashReturn(300, 100);
	}
	else if (type == "��8��")
	{
		m_cs = new CashRebate(0.8);
	}
}

double CashContext::GetResult(double money)
{
	return m_cs->acceptCash(money);
}


