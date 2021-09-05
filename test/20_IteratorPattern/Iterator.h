#pragma once
#include "Aggregate.h"

template<class object>
class Iterator
{
public:
	virtual object First() = 0 ;
	virtual object Next() = 0 ;
	virtual bool IsDone() = 0 ;
	virtual object CurrentItem() = 0;
};

template<class object>
class ConcreteAggregate;

template<class object>
class ConcreteIterator : public Iterator<object>
{
public:
	ConcreteIterator(ConcreteAggregate<object>* aggregate);
	object First() override;
	object Next() override;
	bool IsDone() override;
	object CurrentItem() override;

private:
	ConcreteAggregate<object>* m_aggregate;
	int current;
};

template<class object>
object ConcreteIterator<object>::CurrentItem()
{
	return m_aggregate->GetItems(current);
}

template<class object>
bool ConcreteIterator<object>::IsDone()
{
	return current >= m_aggregate->GetCount() ? true : false;
}

template<class object>
object ConcreteIterator<object>::Next()
{
	object ret;
	current++;
	if (current < m_aggregate->GetCount())
	{
		ret = m_aggregate->GetItems(current);
	}
	return ret;
}

template<class object>
object ConcreteIterator<object>::First()
{
	return m_aggregate->GetItems(0);
}

template<class object>
ConcreteIterator<object>::ConcreteIterator(ConcreteAggregate<object>* aggregate)
{
	m_aggregate = aggregate;
}
