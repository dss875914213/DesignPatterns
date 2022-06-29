#include<iostream>
#include<string>
#include<vector>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
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
			cout << "������ǵ�ǰ������ֵ��ħ��ֵ���������ֱ�Ϊ��" << m_life << ", " << m_magic << ", " << m_attack << endl;
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

	// ֧�ֶ������
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��18�� ����¼��Memento��ģʽ:����ģʽ(Snapshot)����Ϊ��ģʽ��
	//��1��һ������ʵ�ַ���
	// һ���ģʽ��������һ�� �����ߣ������ˣ��࣬�����Ⲣ���Ǳ���ġ� FCareTaker

	//��2�����뱸��¼��Memento��ģʽ
	//���壺�ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬��
	  //�����Ժ�Ϳ��Խ��ö���ָ���ԭ�ȱ����״̬
	//3�ֽ�ɫ
	//a)Originator(ԭ����)��Fighter�ࡣ
	//b)Memento������¼����FighterMemnto�ࡣ
	//c)CareTaker��������/�����ߣ���FCareTaker�ࡣ
	//����¼���������ò����Ǳ������ݣ����ǻָ����ݡ�

	//˵����
	//a)���ա���������ζ������������������Ϣ��Ҫ������¼�б��档
	//b)�����ղ���Ҫ���������������Ҫ������ֶζ�һһ��Ӧ����¼����ͬ���ֶΣ�����¼�п�����
	   //�ڴ������ַ��������루Hex���롢Base64���룩��ʽ�洢���߻�ԭ��������������е����ݡ�
	   //�������л���
	//c)����������������ղ�����������һ�Ρ�FCareTaker2����ο��ա�����һ������
	//d)friend
	//e)���ʺϱ���ԭ���������е�һ���֣��������У��ڲ�״̬���������ԭ��ģʽ��
	//f)�ŵ㣺����ص�һ���ض�����ʷ���衣ȱ�㣺����Դ�����ġ�
	//g)��ȫ�洢�������洢��Ӧ��Ƶ�������ա�  ��ȫ�洢�������洢��ʽ���ʹ�á�Redis��RDB����ȫ���ݣ���AOF���������ݣ���
	   //������Ҫ��¼�����ݡ�
	//h)Ӧ�ó��ϣ�������壬������ʷ��¼�������ա�
	//i)���ݱ������ڴ����Լ����ڴ��лָ����ݡ�

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
