#include <iostream>
#include "Barbecuer.h"
#include "Command.h"
#include "Waiter.h"
using namespace std;
int main()
{
	Barbecuer* boy = new Barbecuer();
	Command* bakeMuttonCommand1 = new BakeMuttonCommand(boy);
	Command* bakeMuttonCommand2 = new BakeMuttonCommand(boy);
	Command* bakeCHickenWingCommand1 = new BakeChickenWingCommand(boy);
	Waiter* girl = new Waiter();

	girl->SetOrder(bakeMuttonCommand1);
	girl->SetOrder(bakeMuttonCommand2);
	girl->SetOrder(bakeCHickenWingCommand1);
	girl->Notify();
}
