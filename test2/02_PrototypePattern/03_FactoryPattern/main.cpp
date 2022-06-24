#include<iostream>
#include<string>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class Monster
	{
	public:
		Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {};	// ������ʱ����������Ϊ�麯��

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class M_Undead :public Monster
	{
	public:
		M_Undead(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "������������" << endl;
		}
		~M_Undead() {};
	};

	class M_Element :public Monster
	{
	public:
		M_Element(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "Ԫ����������" << endl;
		}
		~M_Element() {};
	};

	class M_Mechanic :public Monster
	{
	public:
		M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "��е��������" << endl;
		}
		~M_Mechanic() {};
	};

	class MonsterFactory
	{
	public:
		Monster* CreateMonster(string name)
		{
			Monster* monster = NULL;
			if (name == "undead")
				monster = new M_Undead(2000, 300, 100);
			else if (name == "element")
				monster = new M_Element(4000, 100, 200);
			else if (name == "mechanic")
				monster = new M_Mechanic(3000, 200, 100);
			return monster;
		}
	};
}

namespace _nmsp2
{
	class Monster
	{
	public:
		Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {};	// ������ʱ����������Ϊ�麯��

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class M_Undead :public Monster
	{
	public:
		M_Undead(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "������������" << endl;
		}
		~M_Undead() {};
	};

	class M_Element :public Monster
	{
	public:
		M_Element(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "Ԫ����������" << endl;
		}
		~M_Element() {};
	};

	class M_Mechanic :public Monster
	{
	public:
		M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "��е��������" << endl;
		}
		~M_Mechanic() {};
	};

	class M_ParFactory
	{
	public:
		virtual Monster* CreateMonster() = 0;
		virtual ~M_ParFactory() {}
	};

	class M_UndeadFactory :public M_ParFactory
	{
	public:
		Monster* CreateMonster() override
		{
			return new M_Undead(2000, 300, 100);
		}
	};

	class M_ElementFactory : public M_ParFactory
	{
	public:
		Monster* CreateMonster() override
		{
			return new M_Element(4000, 100, 200);
		}
	};

	class M_MechanicFactory : public M_ParFactory
	{
	public:
		Monster* CreateMonster() override
		{
			return new M_Mechanic(3000, 200, 100);
		}
	};


	template<typename T>
	class M_ChildFactory :public M_ParFactory
	{
	public :
		Monster* CreateMonster() override
		{
			return new T(300, 0, 50);
		}
	};
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//������ ����ģʽ��ԭ�ͣ�Prototype��ģʽ�������ߣ�Builder��ģʽ
	//��һ��  ����ģʽ:������ģʽ
	//new���Ѷ��󣬿���ʵ�ֶ�̬��
	//����ģʽ��ͨ���Ѵ�������Ĵ����װ������������������Ĵ���������ҵ���߼�����������Ŀ�ġ�
	//A *pobja = new A();
	//����ģʽϸ�֣�a)�򵥹���ģʽ��b)��������ģʽ��c)���󹤳�ģʽ��
	//�������������һ����Ҫԭ�򣺿���ԭ��

	//��1���򵥹�����Simple Factory��ģʽ
	//�߻�����������Ԫ��������е������������ֵ��ħ��ֵ���������������ԡ�
	//Monster��Ϊ���࣬M_Undead�������ࣩ��M_Element��Ԫ��������M_Mechanic����е������
	//ʹ��new +��������������������һ�� �����������͵Ľ���Ϲ�ϵ��
	//�򵥹���ģʽ��ʵ��˼·��ʹ�ù��������ʵ�ִ�������Ĵ���  ��  ���� ������������Ҫʵ�ֵ��߼�������롣
	//��װ�仯����������Χ��������С�������ױ仯�Ĵ����������һ��С��Χ�ڣ��Ϳ����ںܴ�̶�����ߴ���Ŀ�ά���ԺͿ���չ�ԡ�
	//ͨ�������µ�if else��֧���ﵽ֧���¹������ӵ�Ŀ�ġ���Υ����������������Ƶ�ԭ�򣺿���ԭ��Open Close Principle :OCP����
	//����ԭ��˵���Ǵ�����չ�����⡪������չ���ţ����޸Ĺرգ���գ���
	//����ԭ����ϸ�Ľ��ͣ��������¹��ܣ���Ӧ��ͨ���޸��Ѿ����ڵĴ��������У�����Ӧ��ͨ����չ����(�����������࣬�����³�Ա�����������С�
	//���if,else��֧���ࣨû����ʮ�ϰٸ��������ʵ�Υ������ԭ������ȫ���Խ��ܵġ�
	//���Ҫ�ڴ���Ŀɶ��ԺͿ���չing֮������Ȩ�⡣
	//���롰�򵥹��������ģʽ�Ķ��壨ʵ����ͼ��������һ��������(MonsterFactory)������ĳ�Ա����(createMonster)���Ը��ݲ�ͬ����
	  //���������ز�ͬ������󣬱������Ķ����������ࣨM_Undead��M_Element��M_Mechanic��һ�㶼������ͬ�ĸ��ࣨMonster����
	  //�����ߣ�����ָmain������������Ĵ��������ϸ�ڡ�
	//�򵥹�������ģʽ��ʵ���˴�����������루createMonster�������������ࣨM_Undead��M_Element��M_Mechanic������ϵ�Ч����

	//��2������������Factory Method��ģʽ:��ƹ���ģʽ���߶�̬����ģʽ��
	//��򵥹���ģʽ�ȣ�����Ը�ǿ��ʵ��Ҳ���Ӹ��ӣ������������ࡣ
	//M_UndeadFactory��M_ElementFactory��M_MechanicFactory�࣬��һ����ͬ�ĸ���M_ParFactory�����������ࣩ:
	  //���Ͽ���ԭ�򣬸����Ĵ�������Ҫ�����Ӷ���µĹ����ࡣ
	//���壨ʵ����ͼ��������һ�����ڴ�������Ľӿڣ�M_ParFactory���е�createMonster��Ա����������ʵ���Ǹ�������������������ģʽ������Ҳ���ɴ˶�����,
	  //�������ࣨM_UndeadFactory��M_ElementFactory��M_MechanicFactory������Ҫʵ������������һ����
	  //��ģʽʹ��ĳ���ࣨM_Undead��M_Element��M_Mechanic����ʵ�����ӳٵ����ࣨM_UndeadFactory��M_ElementFactory��M_MechanicFactory����
	//�����¹������ͣ�M_Beast��Ұ���ࣩ��
	//һ�������Ϊ�����򵥹���ģʽ�Ĵ��뾭���ѹ�������г������ɷ��Ͽ���ԭ���Ĵ��룬�ͱ���˹�������ģʽ�Ĵ��롣

	//����new���������е�ĳ������ĳЩ������ĳ�Ա������ȥ�����ĺô���
	//a)��װ�仯�� prtnobj = new M_Element(200,80,100); ->new M_Element(200,80,100,300);
	//b)��������ǰ��ҪһЩ�����ҵ����룬���Խ���Щ�������ӵ�����Ĺ������createMonster��Ա�����С�

	//�򵥹���ģʽ�Ѵ�����������·ŵ���һ��ͳһ�ĵط����������ԱȽϲ����������ģʽ�൱�ڽ�����һ������ʵ�ֿ�ܣ��Ӷ�������������������δ�����
	//��������ģʽ������Ҫ����һ�����Ʒ�ȼ��ṹ����Σ���ͬ�Ĺ����ȼ��ṹ����Ҳ����������Ĳ�νṹ����Ŀ��

	/*_nmsp2::M_ParFactory* mecFactory = new _nmsp2::M_MechanicFactory();
	_nmsp2::M_ParFactory* eleFactory = new _nmsp2::M_ElementFactory(); 
	_nmsp2::M_ParFactory* undFactory = new _nmsp2::M_UndeadFactory();

	_nmsp2::Monster* mechanic =  mecFactory->CreateMonster();
	_nmsp2::Monster* elelment = eleFactory->CreateMonster();
	_nmsp2::Monster* undead = undFactory->CreateMonster();

	delete mechanic;
	delete elelment;
	delete undead;

	delete mecFactory;
	delete eleFactory;
	delete undFactory;*/

	_nmsp2::M_ChildFactory<_nmsp2::M_Element> factory;
	_nmsp2::Monster* element = factory.CreateMonster();

	delete element;
}
