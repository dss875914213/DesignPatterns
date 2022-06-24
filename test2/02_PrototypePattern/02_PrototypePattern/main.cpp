#include<iostream>

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
#define new DEBUG_NEW
#endif
#endif

using namespace std;
namespace _nmsp1
{
	// ����սʿ��
	class Warrior
	{
	public:
		Warrior(int life, int magic, int attack): m_life(life), m_magic(magic), m_attack(attack){}
		void JN_Burn()
		{
			cout << "��Χ������ʧ 500 ����ֵ" << endl;
			cout << "������ʧ 300 ����ֵ" << endl;
			m_life -= 300;
			cout << "��ʱ������Ч" << endl;
		}

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};
}

namespace _nmsp2
{
	class Fighter
	{
	public:
		Fighter(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Fighter() {};	// ����������������Ҫ��Ϊ�麯��
		void JN_Burn()
		{
			if (!CanUseEffect())
				return;
			EffectEnemy();
			EffectSelf();
			ShowEffect();
		}

	private:
		virtual bool CanUseEffect() = 0;
		virtual void EffectEnemy() {};
		virtual void EffectSelf() {};
		void ShowEffect()
		{
			cout << "���ż���" << endl;
		}

	protected:	// ������õ�
		int m_life;
		int m_magic;
		int m_attack;
	};

	class Warrier : public Fighter
	{
	public:
		Warrier(int life, int magic, int attack) :Fighter(life, magic, attack) {}

	private:
		bool CanUseEffect() override
		{
			return m_life > 300;
		}

		void EffectEnemy() override
		{
			cout << "������ʧ 500 ����ֵ" << endl;
		}
		void EffectSelf() override
		{
			cout << "������ʧ 300 ����ֵ" << endl;
			m_life -= 300;
		}
	};

	class Mage :public Fighter
	{
	public:
		Mage(int life, int magic, int attack) :Fighter(life, magic, attack) {}

	private:
		bool CanUseEffect()
		{
			return m_magic > 150;
		}

		void EffectEnemy() override
		{
			cout << "������ʧ 650 ����ֵ" << endl;
		}
		void EffectSelf() override
		{
			cout << "����ʧȥ 150 ħ��ֵ" << endl;
			m_magic -= 150;
		}
	};
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�����˳�ʱ����ڴ�й©����ʾ�������������
	//�ڶ��� ģ�巽����Template Method��ģʽ
	//���ݳԷ��� ��ͣ����ˣ�³�ˣ�->ʳ��->���ˣ��ֽ����ÿ���΢�ţ�����Ϊ�⼸�������ǹ̶���������Ϊ�����塣
	//�ڹ̶�����ȷ��������£�ͨ����̬�����ڶ�������ж�ÿ�������ϸ�ڽ��в��컯ʵ�֣������ģ�巽��ģʽ�ܹ��ﵽ��Ч����
	//ģ�巽��ģʽ����Ϊ��ģʽ��

	//��1��һ������ʵ�ַ��������ع�
	//A��˾��һ��С��Ϸ��Ŀ�顪�������������ش�����Ϸ�����ƽֻ���ȭ����Ϸ����
	//һ����Ϸ��Ŀ��������Ҫ�������β�ͬ��ɫ��Ա����ɣ���Ϸ�߻�����Ϸ������Ϸ������
	  //a)��Ϸ�߻�����Ʋ߻� �����������Ϸ�ĸ����淨����ȷ����Ϸ�и�����ֵ����������ˣ�������ֵ��ħ��ֵ��
	  //b)��Ϸ���򣺼�Ƴ�����Ҫ����Ϸ�߻��������ͨ��������ʵ����Ϸ�߻�Ҫ��ĸ�����Ϸ���ܡ�
	  //c)��Ϸ��������ɫ��ƣ�������ƣ���Ϸ��Ч�ȵȡ�

	//��Ϸ�߻�������Ϸ�����Ǹ�սʿ������������ǿ������ֵ�Ƚ϶࣬���ᣩ������ͨ�����ϵ���ǰ�������أ��������˾ͽ��й�����
		 //����Ҳ�ᷴ��������Ҳ������ʱ�����������ǡ�
		 //���ǣ�����ֵ����1000��Ϊ0ʱ������������Ϸ��������ħ��ֵ����0����ʱ�ò��ϣ�������������������200�������һ�µ���ʧȥ���ٵ�����ֵ�� �������ԡ�
		 //���ܡ�ȼ�ա�����ʹ�øü��ܿ���ʹ�������е���ÿ��ʧȥ500������ֵ��������������Ҳ����ʧ��300������ֵ��

	//���� ��ʦ ��Ϊ���ǣ���������ǿ������ֵ�Ƚ��٣������ᣩ
		//���ǣ�����ֵ����800��ħ��ֵ����200����ʱ�ò��ϣ�������������������300  �������ԡ� 
		//���ܡ�ȼ�ա�����ʹ�øü��ܿ���ʹ�������е���ÿ��ʧȥ650������ֵ�����������������ʧ��100��ħ��ֵ��

	//��Ҫ���� ��ʦ ��Ϊ����
	//ÿ�����Ƕ���һ������ ȼ�� �ļ��ܡ�ÿ�������ͷ� ȼ�ռ���ʱЧ��������ͬ���������ǿ϶�����ģ���������������Ӱ�죬�Ե��˻����Ӱ�졣

	//սʿ�ͷ�ʦ�ͷ� ȼ�� ���ܱ����ǲ�ͬ�ģ����ֲ�ͬ�ı�����Ҫ��ͨ��F_Warrior��F_Mage�����е�effect_enemy��effect_self�麯�������ֵġ�
	

	//��2������ģ�巽����Template Method��ģʽ
	//�������������仯Ƶ���ģ�������ԱҪ����Ѱ�ұ仯�㣬�ѱ仯���ֺ��ȶ����ַ��뿪�����ڱ仯�ĵط�Ӧ�����ģʽ��
	//ѧϰ���ģʽ�����ѣ��ѵ����ں�ʱ�ε����ø�ģʽ��
	//���ģʽ��������� ��Ա���� ˵���� �㷨��
	//��󶨣�����ִ��ʱ��֪������Ҫִ���ĸ��麯����
	//��󶨣�����ʱ����ȷ��ִ�е����ĸ����ࣨF_Warrior����F_Mage�е�effect_enemy����effect_self����
	//ģ�巽��ģʽ�Ķ���(ʵ����ͼ)��������һ�������е��㷨�ĹǼܣ��ȶ����֣�������һЩ�����ӳٵ�������ȥʵ�֣������ж����麯����������ʵ��/��д����麯������
		  //�Ӷ��ﵽ�������ȶ���������ܹ�����һЩ�仯��Ŀ�ġ�
	//���ģʽ�ľ����ܽ᣺���ģʽ�����þ����ڱ仯���ȶ��м�Ѱ�Ҹ���㣬�����ȶ��ͱ仯,�Ӷ�������仯��
	//ģ�巽��ģʽҲ����Ϊ������һ�ַ�����ƽṹ�������ֽṹ����Ϊ�����뷨�򡪡���Ҫ�������ң��һ�ȥ�����㡣

	//��3��ģ�巽����Template Method��ģʽ��UMLͼ
	//UML��Unified Modeling Language��ͳһ��ģ���ԡ�
	//UML��һ�ֹ��ߣ�ͨ���ù��߿��Ի���һ����Ľṹͼ��������֮��Ĺ�ϵ�����ְ�����д�Ĵ�����ͼ�η�ʽ���ֶ��ڴ����ȫ���������պô��޴�

	//��4���������Ľ�һ�����Ƽ�Ӧ������
	//���ӷ��������๴ס����Ӷ�������Ƹ�����Ϊ����˼���������Ϊ���ӷ�����
	//MFC��ܣ�΢�������⣩��ͨ��MFC����һ�����ڶԻ����Ӧ�ó����Զ�����OnInitDialog��Ա�������൱��effect_enemy����effect_self�������麯������

	//�����ܹ�װ��ܶ��������������װ�乤��ǳ��̶�������ϸ����΢С�仯���Ϳ���
	   //����������һ�����࣬�������װ�乤�򣨳�Ա�������ͷǳ��ʺϲ���ģ�巽��ģʽ��ʵ�֣�������ĳ�������ϸ�ڿ���ֱ�ӷ������ࣨ���ĳ������������ࣩ�麯���н��С�

	/*_nmsp1::Warrior* warrior = new _nmsp1::Warrior(1000, 0, 100);
	warrior->JN_Burn();
	delete warrior;*/

	//_nmsp2::Fighter* prole_war = new _nmsp2::Warrier(1000, 0, 100);
	//prole_war->JN_Burn();
	//_nmsp2::Fighter* prole_mage = new _nmsp2::Mage(700, 500, 80);
	//prole_mage->JN_Burn();
	//delete prole_war;
	//delete prole_mage;

	// ���
	/*_nmsp2::Warrier roleWar(1000, 0, 100);
	roleWar.JN_Burn();*/

	_nmsp2::Fighter* prole_war = new _nmsp2::Warrier(50, 0, 100);
	prole_war->JN_Burn();
	delete prole_war;
	
	return 0;
}
