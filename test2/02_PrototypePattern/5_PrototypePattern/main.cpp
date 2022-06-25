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
		Monster(int life, int magic, int attack) 
			:m_life(life),
			m_magic(magic),
			m_attack(attack)
		{
		}
		virtual ~Monster() {};
		virtual Monster* Clone() = 0;

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class M_Undead :public Monster
	{
	public:
		M_Undead(int life, int magic, int attack)
			:Monster(life, magic, attack)
		{

		}

		M_Undead(const M_Undead& tmpobj) :Monster(tmpobj)
		{
			cout << "�������鿽�����캯��������һֻ����" << endl;
		}

		Monster* Clone()
		{
			return new M_Undead(*this);
		}
	};

	class M_Element :public Monster
	{
	public:
		M_Element(int life, int magic, int attack)
			:Monster(life, magic, attack)
		{

		}

		M_Element(const M_Element& tmpobj) :Monster(tmpobj)
		{
			cout << "����Ԫ�ؿ������캯��������һֻԪ��" << endl;
		}

		Monster* Clone()
		{
			return new M_Element(*this);
		}
	};

	class M_Mechanic :public Monster
	{
	public:
		M_Mechanic(int life, int magic, int attack)
			:Monster(life, magic, attack)
		{

		}

		M_Mechanic(const M_Mechanic& tmpobj) :Monster(tmpobj)
		{
			cout << "���û�е�������캯��������һֻ��е" << endl;
		}

		Monster* Clone()
		{
			return new M_Mechanic(*this);
		}
	};

}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	
	//�ڶ���  ԭ�ͣ�Prototype��ģʽ
		//ԭ��ģʽ��ͨ��һ������ԭ�Ͷ��󣩿�¡�����һģһ���Ķ���
	//��1��ͨ����������ģʽ�ݱ䵽ԭ��ģʽ
	  //��¡��������ʵ��������Ҫ������Ŀ������캯������C++�¾��䣺����ģ�͡�:�����ǳ����
	  //��¡������ζ�Ÿ��Ƴ�һ��ȫ�µĶ���������Ƶ���ǳ����ʱ��Ҫʵ�����
	//��2������ԭ�ͣ�Prototype��ģʽ
	//���壺��ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ��󡣼�˵������ͨ����¡�������µĶ���ʵ����
	//ԭ��ģʽ�����ֽ�ɫ��
	//a)Prototype������ԭ���ࣩ��Monster�ࡣ
	//b)ConcretePrototype������ԭ���ࣩ��M_Undead��M_Element��M_Mechanic�ࡣ
	//��������ڲ����ݱȽϸ��Ӷ�䲢���ڴ��������ʱ��ϣ�����ֶ���ĵ�ǰ״̬����ô��ԭ��ģʽ��Ȼ���ù�������ģʽ�����ʡ�

	//��������ģʽ��ԭ��ģʽ�ڴ�������ʱ����ͬ�㣺
	//a)������Ҫ����Ա֪������������������������
	//b)��������ģʽ�е�createMonster�Ծ����ڸ��������������¶���
	//c)ԭ��ģʽ�е�clone�Ǹ������ж����������¶���
	//���԰�ԭ��ģʽ������һ������Ĺ�������ģʽ��

	//ԭ��ģʽ��ȱ�㣺
	//a)����������¶����ڲ����ݱȽϸ����Ҷ�䣬ԭ��ģʽ���������Ч�ʿ��ܻ�ߺܶࡣ
	//b)ԭ��ģʽ�����ڶ���ĵȼ��ṹ����ԭ��ģʽ����Ҫ����Ĺ����ࡣ
	//c)clone�ӿڵ�ʵ�ַ����ж��֡�
	//d)��Щ����£���Ʒ���д���һ����¡����Ҳ��������ṩһЩ���Ա�����
	
	_nmsp1::Monster* undead = new _nmsp1::M_Undead(200, 40, 50);
	_nmsp1::Monster* undead2 = undead->Clone();
	_nmsp1::Monster* element = new _nmsp1::M_Element(200, 40, 50);
	_nmsp1::Monster* element2 = element->Clone();
	_nmsp1::Monster* mechanic = new _nmsp1::M_Mechanic(200, 40, 50);
	_nmsp1::Monster* mechanic2 = mechanic->Clone();

	delete undead;
	delete undead2;
	delete element;
	delete element2;
	delete mechanic;
	delete mechanic2;
}
