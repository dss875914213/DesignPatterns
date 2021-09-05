#pragma once
#include "Iterator.h"
#include <vector>
using namespace std;

template<class object>
class Iterator;

template<class object>
class Aggregate
{
public:
	virtual Iterator<object>* CreateItertor() = 0;
};

template<class object>
class Iterator;
template<class object>
class ConcreteIterator;

template<class object>
class ConcreteAggregate :public Aggregate<object>
{
public:
	Iterator<object>* CreateItertor() override;
	int GetCount();
	void SetItems(object item);
	object GetItems(int count);

private:
	vector<object> items;
	int Count;

};



template<class object>
object ConcreteAggregate<object>::GetItems(int count)
{
	return items[count];
}

template<class object>
void ConcreteAggregate<object>::SetItems(object item)
{
	items.push_back(item);
	Count++;
}

template<class object>
int ConcreteAggregate<object>::GetCount()
{
	return Count;
}

template<class object>
Iterator<object>* ConcreteAggregate<object>::CreateItertor()
{
	return new ConcreteIterator<object>(this);
}