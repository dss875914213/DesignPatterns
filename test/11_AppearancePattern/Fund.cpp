#include "Fund.h"

Fund::Fund()
{
	gu1 = new Stock1();
	gu2 = new Stock2();
}

void Fund::BuyFund()
{
	gu1->Buy();
	gu2->Buy();
}

void Fund::SellFund()
{
	gu1->Sell();
	gu2->Sell();
}
