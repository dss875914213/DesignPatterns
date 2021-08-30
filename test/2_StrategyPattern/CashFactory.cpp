#include "CashFactory.h"

CashSuper* CashFactory::createCashAccept(string type)
{
	CashSuper* cs = nullptr;
	if (type == "�����շ�")
	{
		cs = new CashNormal();
	}
	else if (type == "��300��100")
	{
		cs = new CashReturn(300, 100);
	}
	else if (type == "��8��")
	{
		cs = new CashRebate(0.8);
	}
	return cs;
}
