#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
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
			cout << "���: " << otherPlayer->m_sPlayerName << "�յ�" << m_sPlayerName << "���͵���Ϣ" << tmpContext << endl;
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
			cout << "���: " << m_sPlayerName  << "�յ�" << otherPlayer->m_sPlayerName << "���͵���Ϣ" << tmpContext << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��5�� �۲��ߣ�Observer��ģʽ
	//��1��һ���������⵼�µĵ�Ч�ʷ���
	//��2������۲��ߣ�Observer��ģʽ
	 //�۲������ģʽ ���壨ʵ����ͼ�������������һ��һ�Զ��������ϵ����һ�������״̬�����ı�ʱ������������
		//���Ķ��󶼻��Զ��õ�֪ͨ��
	//����-����(Publish-Subscribe����

	//�۲���ģʽ�����ֽ�ɫ
	//a)Subject�����⣩���۲�Ŀ�꣬����ָNotifier�ࡣ
	//b)ConcreteSubject���������⣩������ָTalkNotifier�ࡣ
	//c)Observer���۲��ߣ�������ָFighter�ࡣ
	//d)ConcreteObserver(����۲��ߣ�������ָF_Warrior��F_Mage���ࡣ

	//�۲���ģʽ���ص㣺
	//a)�ڹ۲��ߺ͹۲�Ŀ��֮�佨����һ����������
	//b)�۲�Ŀ�����۲����б��е����й۲��߷���֪ͨ��
	//c)����ͨ�����Ӵ����������µĹ۲��߻��߹۲�Ŀ�꣬���Ͽ���ԭ��
	//��3��Ӧ������
	//a)��Ԯ�����Ա�ڳ�
	//b)�������Ƽ���������θ�ڵĶ���
	//c)ͨ���ı�������Ƶ�ͼ������ʵ�ķ�Ӧ��˾���������ݡ�
	//d)��¥ֻ���30���ڵ���ң��б�����ң����й�����
	
	/*_nmsp1::Fighter* pplayerobj1 = new _nmsp1::F_Warrior(10, "����");
	_nmsp1::g_playerList.push_back(pplayerobj1);
	pplayerobj1->SetFamilyID(100);

	_nmsp1::Fighter* pplayerobj2 = new _nmsp1::F_Warrior(20, "����");
	_nmsp1::g_playerList.push_back(pplayerobj2);
	pplayerobj2->SetFamilyID(100);

	_nmsp1::Fighter* pplayerobj3 = new _nmsp1::F_Mage(30, "����");
	_nmsp1::g_playerList.push_back(pplayerobj3);
	pplayerobj3->SetFamilyID(100);

	_nmsp1::Fighter* pplayerobj4 = new _nmsp1::F_Mage(40, "����");
	_nmsp1::g_playerList.push_back(pplayerobj4);
	pplayerobj4->SetFamilyID(200);

	pplayerobj1->SayWords("ȫ��ۺ�,׼������!");
	for (auto iter = _nmsp1::g_playerList.begin(); iter != _nmsp1::g_playerList.end(); iter++)
	{
		delete(*iter);
	}*/

	_nmsp2::Fighter* pplayerobj1 = new _nmsp2::F_Warrior(10, "����");
	pplayerobj1->SetFamilyID(100);

	_nmsp2::Fighter* pplayerobj2 = new _nmsp2::F_Warrior(20, "����");
	pplayerobj2->SetFamilyID(100);

	_nmsp2::Fighter* pplayerobj3 = new _nmsp2::F_Mage(30, "����");
	pplayerobj3->SetFamilyID(100);

	_nmsp2::Fighter* pplayerobj4 = new _nmsp2::F_Mage(40, "����");
	pplayerobj4->SetFamilyID(200);

	_nmsp2::Notifier* notifier = new _nmsp2::TalkNotifier();
	notifier->AddToList(pplayerobj1);
	notifier->AddToList(pplayerobj2);
	notifier->AddToList(pplayerobj3);
	notifier->AddToList(pplayerobj4);

	pplayerobj1->SayWords("���ϣ�׼������!", notifier);

	notifier->RemoveFromList(pplayerobj3);
	pplayerobj2->SayWords("���ӵ�ǲ", notifier);

	delete notifier;
	delete pplayerobj1;
	delete pplayerobj2;
	delete pplayerobj3;
	delete pplayerobj4;
}
