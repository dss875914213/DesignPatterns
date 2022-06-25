#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class Fighter;
	list<Fighter*>  g_playerList;

	class Fighter
	{
	public:
		Fighter(int playerID, string playerName)
			:m_iPlayerID(playerID),
			m_sPlayerName(playerName),
			m_iFamilyID(-1)
		{

		}
		virtual ~Fighter() {}
		void SetFamilyID(int familyID)
		{
			m_iFamilyID = familyID;
		}

		void SayWords(string tmpContent)
		{
			if (m_iFamilyID != -1)
			{
				for (auto iter = g_playerList.begin(); iter != g_playerList.end(); iter++)
				{
					if ((*iter)->m_iFamilyID == m_iFamilyID)
						NotifyWords(*iter, tmpContent);
				}
			}
		}

	private:
		void NotifyWords(Fighter* otherPlayer, string tmpContext)
		{
			cout << "玩家: " << otherPlayer->m_sPlayerName << "收到" << m_sPlayerName << "发送的消息" << tmpContext << endl;
		}

	private:
		int m_iPlayerID;
		string m_sPlayerName;
		int m_iFamilyID;
	};

	class F_Warrior :public Fighter
	{
	public:
		F_Warrior(int playerID, string playerName)
			:Fighter(playerID, playerName)
		{

		}
	};

	class F_Mage :public Fighter
	{
	public:
		F_Mage(int playerID, string playerName)
			:Fighter(playerID, playerName)
		{

		}
	};
}

namespace _nmsp2
{
	class Fighter;
	class Notifier
	{
	public:
		virtual ~Notifier(){}
		virtual void AddToList(Fighter* fighter) = 0;
		virtual void RemoveFromList(Fighter* fighter) = 0;
		virtual void Notify(Fighter* fighter, string tmpContent) = 0;
	};

	class Fighter
	{
	public:
		Fighter(int playerID, string playerName)
			:m_iPlayerID(playerID),
			m_sPlayerName(playerName),
			m_iFamilyID(-1)
		{

		}

		virtual ~Fighter(){}

		void SetFamilyID(int familyID)
		{
			m_iFamilyID = familyID;
		}

		int GetFamilyID()
		{
			return m_iFamilyID;
		}

		void SayWords(string tmpContent, Notifier* notifier)
		{
			notifier->Notify(this, tmpContent);
		}

		void NotifyWords(Fighter* otherPlayer, string tmpContext)
		{
			cout << "玩家: " << m_sPlayerName  << "收到" << otherPlayer->m_sPlayerName << "发送的消息" << tmpContext << endl;
		}

	private:
		int m_iPlayerID;
		string m_sPlayerName;
		int m_iFamilyID;
	};

	class F_Warrior :public Fighter
	{
	public:
		F_Warrior(int playerID, string playerName)
			:Fighter(playerID, playerName)
		{

		}
	};

	class F_Mage :public Fighter
	{
	public:
		F_Mage(int playerID, string playerName)
			:Fighter(playerID, playerName)
		{

		}
	};

	class TalkNotifier :public Notifier
	{
	public:
		void AddToList(Fighter* fighter) override
		{
			if (fighter->GetFamilyID() != -1)
			{
				auto iter = m_familyList.find(fighter->GetFamilyID());
				if (iter != m_familyList.end())
				{
					iter->second.push_back(fighter);
				}
				else
				{
					list<Fighter*> fighters;
					fighters.push_back(fighter);
					m_familyList[fighter->GetFamilyID()] = fighters;
				}
			}
		}

		void RemoveFromList(Fighter* fighter) override
		{
			if (fighter->GetFamilyID() != -1)
			{
				if (m_familyList.find(fighter->GetFamilyID()) != m_familyList.end())
				{
					m_familyList[fighter->GetFamilyID()].remove(fighter);
				}
			}
		}

		void Notify(Fighter* fighter, string tmpContent)
		{
			if (fighter->GetFamilyID() != -1)
			{
				if (m_familyList.find(fighter->GetFamilyID()) != m_familyList.end())
				{
					for (auto it = m_familyList[fighter->GetFamilyID()].begin(); it != m_familyList[fighter->GetFamilyID()].end(); it++)
					{
						(*it)->NotifyWords(fighter, tmpContent);
					}
				}
			}
		}

	private:
		map<int, list<Fighter*>> m_familyList;
	};
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第5章 观察者（Observer）模式
	//（1）一个遍历问题导致的低效率范例
	//（2）引入观察者（Observer）模式
	 //观察者设计模式 定义（实现意图）：定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于
		//它的对象都会自动得到通知。
	//发布-订阅(Publish-Subscribe）；

	//观察者模式的四种角色
	//a)Subject（主题）：观察目标，这里指Notifier类。
	//b)ConcreteSubject（具体主题）：这里指TalkNotifier类。
	//c)Observer（观察者）：这里指Fighter类。
	//d)ConcreteObserver(具体观察者）：这里指F_Warrior和F_Mage子类。

	//观察者模式的特点：
	//a)在观察者和观察目标之间建立了一个抽象的耦合
	//b)观察目标会向观察者列表中的所有观察者发送通知。
	//c)可以通过增加代码来增加新的观察者或者观察目标，符合开闭原则
	//（3）应用联想
	//a)救援家族成员镖车
	//b)将新闻推荐给符合其胃口的读者
	//c)通过改变自身绘制的图形来真实的反应公司的销售数据。
	//d)炮楼只会对30米内的玩家（列表内玩家）进行攻击。
	
	/*_nmsp1::Fighter* pplayerobj1 = new _nmsp1::F_Warrior(10, "张三");
	_nmsp1::g_playerList.push_back(pplayerobj1);
	pplayerobj1->SetFamilyID(100);

	_nmsp1::Fighter* pplayerobj2 = new _nmsp1::F_Warrior(20, "李四");
	_nmsp1::g_playerList.push_back(pplayerobj2);
	pplayerobj2->SetFamilyID(100);

	_nmsp1::Fighter* pplayerobj3 = new _nmsp1::F_Mage(30, "王五");
	_nmsp1::g_playerList.push_back(pplayerobj3);
	pplayerobj3->SetFamilyID(100);

	_nmsp1::Fighter* pplayerobj4 = new _nmsp1::F_Mage(40, "赵六");
	_nmsp1::g_playerList.push_back(pplayerobj4);
	pplayerobj4->SetFamilyID(200);

	pplayerobj1->SayWords("全族聚合,准备进攻!");
	for (auto iter = _nmsp1::g_playerList.begin(); iter != _nmsp1::g_playerList.end(); iter++)
	{
		delete(*iter);
	}*/

	_nmsp2::Fighter* pplayerobj1 = new _nmsp2::F_Warrior(10, "张三");
	pplayerobj1->SetFamilyID(100);

	_nmsp2::Fighter* pplayerobj2 = new _nmsp2::F_Warrior(20, "李四");
	pplayerobj2->SetFamilyID(100);

	_nmsp2::Fighter* pplayerobj3 = new _nmsp2::F_Mage(30, "王五");
	pplayerobj3->SetFamilyID(100);

	_nmsp2::Fighter* pplayerobj4 = new _nmsp2::F_Mage(40, "赵六");
	pplayerobj4->SetFamilyID(200);

	_nmsp2::Notifier* notifier = new _nmsp2::TalkNotifier();
	notifier->AddToList(pplayerobj1);
	notifier->AddToList(pplayerobj2);
	notifier->AddToList(pplayerobj3);
	notifier->AddToList(pplayerobj4);

	pplayerobj1->SayWords("集合，准备攻击!", notifier);

	notifier->RemoveFromList(pplayerobj3);
	pplayerobj2->SayWords("听从调遣", notifier);

	delete notifier;
	delete pplayerobj1;
	delete pplayerobj2;
	delete pplayerobj3;
	delete pplayerobj4;
}
