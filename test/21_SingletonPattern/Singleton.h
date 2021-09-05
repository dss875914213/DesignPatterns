#pragma once
#include <mutex>

class Singleton
{
public:
	static Singleton* GetInstance();
	void ShowState();

private:
	Singleton();

private:
	static Singleton* instance;
	static std::mutex mtx;
};

