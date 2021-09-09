#include <iostream>
#include <vector>
#include "Action.h"
#include "Person.h"
#include "ObjectStructure.h"
using namespace std;
int main()
{
	ObjectStructure* o = new ObjectStructure();
	o->Attach(new Man());
	o->Attach(new Woman());

	// 成功时的反应
	Success* v1 = new Success();
	o->Display(v1);

	Failing* v2 = new Failing();
	o->Display(v2);

	Amativeness* v3 = new Amativeness();
	o->Display(v3);
}
