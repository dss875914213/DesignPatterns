#include <iostream>
#include "Player.h"

using namespace std;
int main()
{
	Player* b = new Forwards("°ÍµÙ¶û");
	b->Attack();
	Player* ym = new Translator("Ò¦Ã÷");
	ym->Attack();
	ym->Defense();
}
