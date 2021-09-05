#include <iostream>
#include <string>
#include "Aggregate.h"
#include "Iterator.h"

using namespace std;
int main()
{
	ConcreteAggregate<string>* a = new ConcreteAggregate<string>();
	a->SetItems("����");
	a->SetItems("С��");

	Iterator<string>* i = new ConcreteIterator<string>(a);
	string item = i->First();
	while(!i->IsDone())
	{
		cout << i->CurrentItem() << " ����Ʊ��" << endl;
		i->Next();
	}
}
