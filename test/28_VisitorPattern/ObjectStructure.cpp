#include "ObjectStructure.h"

void ObjectStructure::Attach(Person* element)
{
	elements.push_back(element);
}

void ObjectStructure::Detach(Person* element)
{
	// TODO
}

void ObjectStructure::Display(Action* visitor)
{
	for (auto& it : elements)
	{
		it->Accept(visitor);
	}
}
