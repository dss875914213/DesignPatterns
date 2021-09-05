#include <iostream>
#include "Builder.h"

using namespace std;
int main()
{
	PersonDirector* pd = new PersonDirector();
	PersonThinBuilder* ptd = new PersonThinBuilder();
	PersonFatBuilder* pfd = new PersonFatBuilder();
	pd->CreatePerson(ptd);
	pd->CreatePerson(pfd);
}
