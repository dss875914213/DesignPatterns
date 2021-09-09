#include "Person.h"

void Man::Accept(Action* visitor)
{
	visitor->GetManConclusion(this);
}

void Woman::Accept(Action* visitor)
{
	visitor->GetWomanConclusion(this);
}
