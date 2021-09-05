#pragma once

#include <string>
using namespace std;

class Player
{
public:
	Player(string name) :m_name(name) {}
	virtual void Attack() = 0;
	virtual void Defense() = 0;

protected:
	string m_name;
};

class Forwards : public Player
{
public:
	Forwards(string name) : Player(name) {}
	void Attack() override;
	void Defense() override;
};

class Center : public Player
{
public:
	Center(string name) : Player(name) {}
	void Attack() override;
	void Defense() override;
};


class ForeignCenter
{
public:
	void ChineseAttack();
	void ChineseDefense();
	void SetName(string name);
	string GetName();

private:
	string m_name;
};

class Translator :public Player
{
public:
	Translator(string name) :Player(name) { wjzf = new ForeignCenter(); wjzf->SetName(name); }
	void Attack();
	void Defense();
private:
	ForeignCenter* wjzf;
};

