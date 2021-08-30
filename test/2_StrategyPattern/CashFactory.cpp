#include "CashFactory.h"

CashSuper* CashFactory::createCashAccept(string type)
{
	CashSuper* cs = nullptr;
	if (type == "正常收费")
	{
		cs = new CashNormal();
	}
	else if (type == "满300返100")
	{
		cs = new CashReturn(300, 100);
	}
	else if (type == "打8折")
	{
		cs = new CashRebate(0.8);
	}
	return cs;
}
