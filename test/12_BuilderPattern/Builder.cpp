#include "Builder.h"
#include <string>
#include <iostream>
using namespace std;

void PersonThinBuilder::BuildHead()
{
	cout << "画小头" << endl;
}

void PersonThinBuilder::BuildBody()
{
	cout << "画小身体" << endl;
}

void PersonFatBuilder::BuildHead()
{
	cout << "画大头" << endl;
}

void PersonFatBuilder::BuildBody()
{
	cout << "画大身体" << endl;
}

void PersonDirector::CreatePerson(PersonBuilder* pb)
{
	pb->BuildHead();
	pb->BuildBody();
}
