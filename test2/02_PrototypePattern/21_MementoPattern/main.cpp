#include<iostream>
#include<string>
#include<vector>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class FightMemento
	{
	private:
		FightMemento(int life, int magic, int attack) :
			m_life(life),
			m_magic(magic),
			m_attack(attack)
		{

		}

	private:
		friend class Fighter;
		int GetLife() const
		{
			return m_life;
		}

		void SetLife(int life)
		{
			m_life = life;
		}

		int GetMagic() const
		{
			return m_magic;
		}

		void SetMagic(int magic)
		{
			m_magic = magic;
		}

		int GetAttack() const
		{
			return m_attack;
		}

		void SetAttack(int attack)
		{
			m_attack = attack;
		}

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class Fighter
	{
	public:
		Fighter(int life, int magic, int attack)
			:m_life(life),
			m_magic(magic),
			m_attack(attack)
		{

		}

	public:
		FightMemento* CreateMomento()
		{
			return new FightMemento(m_life, m_magic, m_attack);
		}

		void RestoreMomento(FightMemento* pfm)
		{
			m_life = pfm->GetLife();
			m_magic = pfm->GetMagic();
			m_attack = pfm->GetAttack();
		}

		void SetToDead()
		{
			m_life = 0;
		}

		void DisplayInfo()
		{
			cout << "玩家主角当前的生命值、魔法值、攻击力分别为：" << m_life << ", " << m_magic << ", " << m_attack << endl;
		}

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class FCareTaker
	{
	public:
		FCareTaker(FightMemento* ptmpfm)
			:m_pfm(ptmpfm)
		{

		}

		FightMemento* GetMemento()
		{
			return m_pfm;
		}

		void SetMemento(FightMemento* ptmpfm)
		{
			m_pfm = ptmpfm;
		}

	private:
		FightMemento* m_pfm;
	};

	// 支持多个快照
	class FCareTaker2
	{
	public:
		~FCareTaker2()
		{
			for (auto iter = m_pfmContainer.begin(); iter != m_pfmContainer.end(); iter++)
			{
				delete (*iter);
			}
		}

		void SetMemento(FightMemento* ptmpfm)
		{
			m_pfmContainer.push_back(ptmpfm);
		}

		FightMemento* GetMemento(int index)
		{
			auto iter = m_pfmContainer.begin();
			for (int i = 0; i <= index; i++)
			{
				if (i == index)
					return (*iter);
				else
					++iter;
			}
			return NULL;
		}

	private:
		vector<FightMemento*> m_pfmContainer;
	};
}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第18章 备忘录（Memento）模式:快照模式(Snapshot)，行为型模式。
	//（1）一个具体实现范例
	// 一般该模式还会引入一个 管理者（负责人）类，但是这并不是必须的。 FCareTaker

	//（2）引入备忘录（Memento）模式
	//定义：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，
	  //这样以后就可以将该对象恢复到原先保存的状态
	//3种角色
	//a)Originator(原发器)：Fighter类。
	//b)Memento（备忘录）：FighterMemnto类。
	//c)CareTaker（负责人/管理者）：FCareTaker类。
	//备忘录真正的作用并不是保存数据，而是恢复数据。

	//说明：
	//a)快照——并不意味着所有玩家主角类的信息都要往备忘录中保存。
	//b)做快照并不要求玩家主角类中需要保存的字段都一一对应备忘录中相同的字段，备忘录中可以以
	   //内存流，字符串，编码（Hex编码、Base64编码）方式存储或者还原来自玩家主角类中的数据。
	   //数据序列化。
	//c)给玩家主角类做快照并不仅仅限于一次。FCareTaker2做多次快照。给了一个范例
	//d)friend
	//e)更适合保存原发器对象中的一部分（不是所有）内部状态，否则采用原型模式。
	//f)优点：方便回到一个特定的历史步骤。缺点：对资源的消耗。
	//g)完全存储。增量存储来应付频繁做快照。  完全存储和增量存储方式结合使用。Redis，RDB（完全备份），AOF（增量备份）。
	   //减少需要记录的数据。
	//h)应用场合：下棋悔棋，保存历史记录，做快照。
	//i)数据保存在内存中以及从内存中恢复数据。

	//_nmsp1::Fighter* p_fighter = new _nmsp1::Fighter(800, 200, 300);
	//p_fighter->DisplayInfo();

	////_nmsp1::FightMemento* p_fighterMemo = p_fighter->CreateMomento();
	//_nmsp1::FCareTaker* pfcaretaker = new _nmsp1::FCareTaker(p_fighter->CreateMomento());

	//p_fighter->SetToDead();
	//p_fighter->DisplayInfo();

	//p_fighter->RestoreMomento(pfcaretaker->GetMemento());
	//p_fighter->DisplayInfo();

	//delete p_fighter;
	//delete pfcaretaker->GetMemento();
	//delete pfcaretaker;

	_nmsp1::Fighter* pfighter2 = new _nmsp1::Fighter(800, 200, 300);
	_nmsp1::FCareTaker2* pfcaretaker2 = new _nmsp1::FCareTaker2();
	pfcaretaker2->SetMemento(pfighter2->CreateMomento());
	pfighter2->SetToDead();
	pfcaretaker2->SetMemento(pfighter2->CreateMomento());
	pfighter2->DisplayInfo();

	pfighter2->RestoreMomento(pfcaretaker2->GetMemento(0));
	pfighter2->DisplayInfo();

	delete pfighter2;
	delete pfcaretaker2;


}
