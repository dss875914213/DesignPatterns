#pragma once
#include <string>
#include <iostream>
using namespace std;
class PlayContext
{
public:
	string GetText();
	void SetText(string text);

private:
	string m_text;
};

