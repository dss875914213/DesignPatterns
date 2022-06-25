#include<iostream>
#include<string>
#include "Fight.h"
#include "ItemStrategy.h"

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class M_Undead
	{
	public:
		void getInfo()
		{
			cout << "�����������" << endl;
		}
	};

	class M_Element
	{
	public:
		void getInfo()
		{
			cout << "����Ԫ�ع���" << endl;
		}
	};

	class M_Mechanic
	{
	public:
		void getInfo()
		{
			cout << "���ǻ�е����" << endl;
		}
	};

	class F_Warrior
	{
	public:
		void attackEnemyUndead(M_Undead* pobj)
		{
			pobj->getInfo();
		}

		void attackEnemyElement(M_Element* pobj)
		{
			pobj->getInfo();
		}

		void attackEnemyMechanic(M_Mechanic* pobj)
		{
			pobj->getInfo();
		}
	};
}

namespace _nmsp2
{
	class Monster
	{
	public:
		virtual ~Monster() {}
		virtual void GetInfo() = 0;
	};

	class M_Undead :public Monster
	{
	public:
		void GetInfo() override
		{
			cout << "�����������" << endl;
		}
	};

	class M_Element :public Monster
	{
	public:
		void GetInfo() override
		{
			cout << "����Ԫ�ع���" << endl;
		}
	};

	class M_Mechanic :public Monster
	{
	public:
		void GetInfo() override
		{
			cout << "���ǻ�е����" << endl;
		}
	};

	class F_Warrior
	{
	public:
		void AttackEnemy(Monster* obj)
		{
			obj->GetInfo();
		}
	};
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��4�� ���ԣ�Strategy��ģʽ
	//��1��һ������ʵ�ַ��������ع�
	//��Ѫ���ߣ�ҩƷ����
	  //a����Ѫ��������200������ֵ
	  //b���󻹵�������300������ֵ
	  //c���ػ���������500������ֵ
	//Fighter��F_Warrior��F_Mage
	//����  ���ģʽ�Ķ��壺����һϵ���㷨�������ࣩ����ÿ���㷨��װ�����������ǿ����໥�滻�����仰˵������ģʽͨ����һϵ���㷨
	   // ��װ��һϵ�о��������������Ϊ�������������࣬Ȼ�����ʵ����Ҫʹ����Щ���ࡣ
	//�������е����ֽ�ɫ
	//a)Context�������ࣩ��������ά����һ���Գ���������ָ������á�����ָFighter�ࡣ
	//b)Stategy����������ࣩ��������֧�ֵ��㷨�Ĺ����ӿڣ������в�����ĸ��ࡣ����ָItemStrategy�ࡣ
	//c)ConcreteStrategy����������ࣩ���������������࣬ʵ�ֳ���������������Ľӿڡ�����ָItemStrategy_BXD��ItemStrategy_DHD��ItemStrategy_SHD��
	//��������ŵ㣺
	//a)����չ�ķ�ʽ֧�ֶ�δ���ı仯�����Ͽ���ԭ��
	  //�����������ȶ���if������֧ ����switch��֧����Ҫ���ȿ����Ƿ����ͨ������ģʽ�����������ģʽ��if��switch������֧��ɱ�֡�
	//b)�㷨���Ա����á�
	//c)����ģʽ���Կ�������̳е�һ�����������ͨ��Ϊ���������ָ����ͬ�Ĳ��ԣ��Ϳ��Ըı价����������Ϊ��
	//�������ȱ�㣺
	//a)������������²����ࣻ
	//b)ʹ�ò���ʱ�������ߣ�main��������������֪���в�����Ĺ��ܲ�����ʵ����Ҫ���о���ʹ���ĸ������ࡣ
	
	//��2����������ԭ��Dependency Inversion Principle�����DIP
	 //�����������Ƶ���Ҫʵ�ַ�����ͬʱ Ҳ��ʵ�ֿ���ԭ�����Ҫʵ��;����
	//���ͣ��߲������Ӧ�������ڵͲ㣨����ʵ���ࣩ�����߶�Ӧ�������ڳ���㡣
	//����������ģʽʱ��������M_Undead��Ԫ����M_Element����е��M_Mechanic��

	/*ItemStrategy* bxd = new ItemStrategy_BXD();
	ItemStrategy* dhd = new ItemStrategy_DHD();
	ItemStrategy* shd = new ItemStrategy_SHD();
	Fighter* warrior = new FWarrior(100,30,50);
	warrior->SetItemStrategy(bxd);
	warrior->UseItem();

	warrior->SetItemStrategy(dhd);
	warrior->UseItem();

	warrior->SetItemStrategy(shd);
	warrior->UseItem();

	delete warrior;
	delete shd;
	delete dhd;
	delete bxd;*/

	/*_nmsp1::M_Undead* undead = new _nmsp1::M_Undead();
	_nmsp1::M_Element* element = new _nmsp1::M_Element();
	_nmsp1::M_Mechanic* mechanic = new _nmsp1::M_Mechanic();

	_nmsp1::F_Warrior* warrior = new _nmsp1::F_Warrior();
	warrior->attackEnemyElement(element);
	warrior->attackEnemyMechanic(mechanic);
	warrior->attackEnemyUndead(undead);

	delete warrior;
	delete undead;
	delete element;
	delete mechanic;*/

	_nmsp2::Monster* undead = new _nmsp2::M_Undead();
	_nmsp2::Monster* element = new _nmsp2::M_Element();
	_nmsp2::Monster* mechanic = new _nmsp2::M_Mechanic();

	_nmsp2::F_Warrior* warrior = new _nmsp2::F_Warrior();
	warrior->AttackEnemy(undead);
	warrior->AttackEnemy(element);
	warrior->AttackEnemy(mechanic);

	delete warrior;
	delete undead;
	delete element;
	delete mechanic;
}
