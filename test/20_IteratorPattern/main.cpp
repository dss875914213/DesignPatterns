#include <iostream>
#include <string>
#include "Aggregate.h"
#include "Iterator.h"

using namespace std;
int main()
{
	ConcreteAggregate<string>* a = new ConcreteAggregate<string>();
	a->SetItems("´óÄñ");
	a->SetItems("Ð¡²Ë");

	Iterator<string>* i = new ConcreteIterator<string>(a);
	string item = i->First();
	while(!i->IsDone())
	{
		cout << i->CurrentItem() << " ÇëÂòÆ±£¡" << endl;
		i->Next();
	}
}
