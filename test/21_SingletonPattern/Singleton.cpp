#include "Singleton.h"
#include <string>
#include <iostream>
using namespace std;

Singleton* Singleton::instance;
std::mutex Singleton::mtx;

Singleton* Singleton::GetInstance()
{
	if (instance == nullptr)
	{
		mtx.lock();
		instance = new Singleton();
		mtx.unlock();
	}
	return instance;
}

void Singleton::ShowState()
{
	cout << "Hello world" << this << endl;
}

Singleton::Singleton()
{

}
