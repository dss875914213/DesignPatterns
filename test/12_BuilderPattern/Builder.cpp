#include "Builder.h"
#include <string>
#include <iostream>
using namespace std;

void PersonThinBuilder::BuildHead()
{
	cout << "��Сͷ" << endl;
}

void PersonThinBuilder::BuildBody()
{
	cout << "��С����" << endl;
}

void PersonFatBuilder::BuildHead()
{
	cout << "����ͷ" << endl;
}

void PersonFatBuilder::BuildBody()
{
	cout << "��������" << endl;
}

void PersonDirector::CreatePerson(PersonBuilder* pb)
{
	pb->BuildHead();
	pb->BuildBody();
}
