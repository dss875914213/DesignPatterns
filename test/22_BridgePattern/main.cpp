#include <iostream>
#include "HandsetBrand.h"
#include "HandsetSoft.h"

using namespace std;
int main()
{
	HandsetBrand* ab;
	ab = new HandsetBrandN();
	ab->SethandsetSoft(new HandsetGame());
	ab->Run();

	ab->SethandsetSoft(new HandsetAddressList());
	ab->Run();

	delete ab;
	ab = new HandsetBrandM();
	ab->SethandsetSoft(new HandsetGame());
	ab->Run();

	ab->SethandsetSoft(new HandsetAddressList());
	ab->Run();	
}
