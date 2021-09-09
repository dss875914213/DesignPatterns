#pragma once
#include <vector>
#include "Person.h"
#include "Action.h"

using namespace std;

class ObjectStructure
{
public:
	void Attach(Person* element);
	void Detach(Person* element);
	void Display(Action* visitor);
private:
	vector<Person*> elements;
};

