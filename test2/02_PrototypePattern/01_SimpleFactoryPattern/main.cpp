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
	
	/*_nmsp1::Monster* undead = new _nmsp1::M_Undead(2000, 300, 100);
	_nmsp1::Monster* element = new _nmsp1::M_Element(4000, 100, 200);
	_nmsp1::Monster* mechanic = new _nmsp1::M_Mechanic(3000, 200, 100);

	delete undead;
	delete element;
	delete mechanic;*/

	_nmsp1::MonsterFactory* factory = new _nmsp1::MonsterFactory();
	_nmsp1::Monster *undead = factory->CreateMonster("undead");
	_nmsp1::Monster *element = factory->CreateMonster("element");
	_nmsp1::Monster *mechanic = factory->CreateMonster("mechanic");

	delete undead;
	delete element;
	delete mechanic;
	delete factory;
}
