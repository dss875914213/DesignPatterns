#include <iostream>
#include "Player.h"

using namespace std;
int main()
{
	Player* b = new Forwards("�͵ٶ�");
	b->Attack();
	Player* ym = new Translator("Ҧ��");
	ym->Attack();
	ym->Defense();
}
