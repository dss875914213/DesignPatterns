#include <iostream>
#include "Singleton.h"

using namespace std;
int main()
{
	Singleton* singleton1 = Singleton::GetInstance();
	Singleton* singleton2 = Singleton::GetInstance();
	singleton1->ShowState();
	singleton2->ShowState();
}
