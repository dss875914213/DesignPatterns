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

	class M_Undead_Swamp :public Monster
	{
	public:
		M_Undead_Swamp(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "����������������" << endl;
		}
		~M_Undead_Swamp() {};
	};

	class M_Element_Swamp :public Monster
	{
	public:
		M_Element_Swamp(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "����Ԫ����������" << endl;
		}
		~M_Element_Swamp() {};
	};

	class M_Mechanic_Swamp :public Monster
	{
	public:
		M_Mechanic_Swamp(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "�����е��������" << endl;
		}
		~M_Mechanic_Swamp() {};
	};

	class M_Undead_Mountain :public Monster
	{
	public:
		M_Undead_Mountain(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "ɽ��������������" << endl;
		}
		~M_Undead_Mountain() {};
	};

	class M_Element_Mountain :public Monster
	{
	public:
		M_Element_Mountain(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "ɽ��Ԫ����������" << endl;
		}
		~M_Element_Mountain() {};
	};

	class M_Mechanic_Mountain :public Monster
	{
	public:
		M_Mechanic_Mountain(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "ɽ�ػ�е��������" << endl;
		}
		~M_Mechanic_Mountain() {};
	};

	class M_Undead_Town :public Monster
	{
	public:
		M_Undead_Town(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "����������������" << endl;
		}
		~M_Undead_Town() {};
	};

	class M_Element_Town :public Monster
	{
	public:
		M_Element_Town(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "����Ԫ����������" << endl;
		}
		~M_Element_Town() {};
	};

	class M_Mechanic_Town :public Monster
	{
	public:
		M_Mechanic_Town(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "���л�е��������" << endl;
		}
		~M_Mechanic_Town() {};
	};

	class M_ParFactory
	{
	public:
		M_ParFactory()
		{

		}
		virtual ~M_ParFactory() {}
		virtual Monster* CreateMonster_Undead() = 0;
		virtual Monster* CreateMonster_Element() = 0;
		virtual Monster* CreateMonster_Mechanic() = 0;
	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class M_Factory_Swamp :public M_ParFactory
	{
	public:
		Monster* CreateMonster_Undead() override
		{
			return new M_Undead_Swamp(100, 20, 4);
		}
		Monster* CreateMonster_Element() override
		{
			return new M_Element_Swamp(100, 20, 5);
		}
		Monster* CreateMonster_Mechanic() override
		{
			return new M_Mechanic_Swamp(100, 20, 6);
		}
	};

	class M_Factory_Mountain :public M_ParFactory
	{
	public:
		Monster* CreateMonster_Undead() override
		{
			return new M_Undead_Mountain(100, 20, 4);
		}
		Monster* CreateMonster_Element() override
		{
			return new M_Element_Mountain(100, 20, 5);
		}
		Monster* CreateMonster_Mechanic() override
		{
			return new M_Mechanic_Mountain(100, 20, 6);
		}
	};

	class M_Factory_Town :public M_ParFactory
	{
	public:
		Monster* CreateMonster_Undead() override
		{
			return new M_Undead_Town(100, 20, 4);
		}
		Monster* CreateMonster_Element() override
		{
			return new M_Element_Town(100, 20, 5);
		}
		Monster* CreateMonster_Mechanic() override
		{
			return new M_Mechanic_Town(100, 20, 6);
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

	//��3�����󹤳���Abstract Factory��ģʽ
	//��3.1��ս���������෶��
	//������ࣺ�����࣬Ԫ���࣬��е��
	//ս���������ࣺ���������ɽ������������
	//9�����====>����������ࡢԪ���ࡢ��е�࣬ɽ�����������ࡢԪ���ࡢ��е�࣬�����е������ࡢԪ���ࡢ��е��
	//��������ģʽ��һ����������һ������
	//�����һ�����������ܹ�������ֹһ�ֶ��Ƕ��־�����ͬ����Ĺ��������ô�Ϳ�����Ч�ļ����������Ĺ�����������������ǳ��󹤳�ģʽ�ĺ���˼�롣

	//�������a)��Ʒ�ȼ��ṹ   b)��Ʒ��
	//���󹤳�ģʽ�ǰ��ղ�Ʒ����������Ʒ��������ͬ����һ������������������һ���ص���һ���������ù����������������ص����в�Ʒ��

	//���󹤳�ģʽ��ȱ�㣺
	//a)����ɭ�����³������������಻�䡣��ֻ��Ҫ����һ�����ӹ�������M_Factory_Forest�����Ͽ���ԭ��
	//b)�����¹�������������࣬����Ҫ���������̳���Monster�����࣬��Ҫ���M_ParFactory�����µ��麯���ӿڱ���createMonster_Dragon��
	   //ͬʱ�����ӹ����඼��Ҫʵ��createMonster_Dragon�������޸Ĵ���ķ�ʽ�������¹������࣬�����Ͽ���ԭ�����������¹�������β��ʺϳ��󹤳�ģʽ��
	//c)ֻ����һ����Ʒ������Ͽ���ԭ��ֻ��Ҫ�����¹������࣬���Ǹ�ģʽ���ŵ㡣
		  //���������²�Ʒ�ȼ��ṹ����Ҫ�޸ĳ������룬���ǳ��󹤳�ģʽ��ȱ�㣬���ԣ�Ӧ�����ڲ�Ʒ�ȼ��ṹ���ȶ��������ʹ�ø�ģʽ��
		  //Ҳ����˵�������Ϸ�й������ࣨ�����࣬Ԫ���࣬��е�ࣩ�ȽϹ̶�������£����ʺ�ʹ�ó��󹤳�ģʽ��
	
	_nmsp1::M_ParFactory* factorySwamp = new _nmsp1::M_Factory_Swamp();
	_nmsp1::M_ParFactory* factoryMountain = new _nmsp1::M_Factory_Mountain();
	_nmsp1::M_ParFactory* factoryTown = new _nmsp1::M_Factory_Town();

	_nmsp1::Monster* swampUndead = factorySwamp->CreateMonster_Undead();
	_nmsp1::Monster* swampElement = factorySwamp->CreateMonster_Element();
	_nmsp1::Monster* swampMechanic = factorySwamp->CreateMonster_Mechanic();

	_nmsp1::Monster* mountainUndead = factoryMountain->CreateMonster_Undead();
	_nmsp1::Monster* mountainElement = factoryMountain->CreateMonster_Element();
	_nmsp1::Monster* mountainMechanic = factoryMountain->CreateMonster_Mechanic();

	_nmsp1::Monster* townUndead = factoryTown->CreateMonster_Undead();
	_nmsp1::Monster* townElement = factoryTown->CreateMonster_Element();
	_nmsp1::Monster* townMechanic = factoryTown->CreateMonster_Mechanic();

	delete factorySwamp;
	delete factoryMountain;
	delete factoryTown;

	delete swampUndead;
	delete swampElement;
	delete swampMechanic;

	delete mountainUndead;
	delete mountainElement;
	delete mountainMechanic;

	delete townUndead;
	delete townElement;
	delete townMechanic;

}
