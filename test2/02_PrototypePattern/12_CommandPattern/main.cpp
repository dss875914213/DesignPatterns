#include<iostream>
#include<string>
#include <list>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class Cook
	{
	public:
		void CookFish()
		{
			cout << "����" << endl;
		}

		void CookMeat()
		{
			cout << "����" << endl;
		}
	};

	class Command
	{
	public:
		Command(Cook* cook)
			:m_cook(cook)
		{

		}
		virtual ~Command()
		{

		}
		virtual void Execute() = 0;

	protected:
		Cook* m_cook;
	};

	class CommandFish :public Command
	{
	public:
		CommandFish(Cook* cook)
			:Command(cook)
		{

		}

		void Execute()
		{
			m_cook->CookFish();
		}
	};

	class CommandMeat :public Command
	{
	public:
		CommandMeat(Cook* cook)
			:Command(cook)
		{

		}

		void Execute()
		{
			m_cook->CookMeat();
		}
	};
}

namespace _nmsp2
{
	class Cook
	{
	public:
		void CookFish()
		{
			cout << "����" << endl;
		}

		void CookMeat()
		{
			cout << "����" << endl;
		}
	};

	class Command
	{
	public:
		Command(Cook* cook)
			:m_cook(cook)
		{

		}
		virtual ~Command()
		{

		}
		virtual void Execute() = 0;

	protected:
		Cook* m_cook;
	};

	class CommandFish :public Command
	{
	public:
		CommandFish(Cook* cook)
			:Command(cook)
		{

		}

		void Execute()
		{
			m_cook->CookFish();
		}
	};

	class CommandMeat :public Command
	{
	public:
		CommandMeat(Cook* cook)
			:Command(cook)
		{

		}

		void Execute()
		{
			m_cook->CookMeat();
		}
	};

	class Waiter
	{
	public:
		void AddCommand(Command* command)
		{
			m_listCommand.push_back(command);
		}

		void DelCommand(Command* command)
		{
			m_listCommand.remove(command);
		}

		void Notify()
		{
			for (auto iter = m_listCommand.begin(); iter != m_listCommand.end(); iter++)
			{
				(*iter)->Execute();
			}
		}

	private:
		list<Command*> m_listCommand;
	};
}

class TC
{
public:
	void operator()(int tv)
	{
		cout << "TC::Operator(int tv) ִ����, tv=" << tv << endl;
	}

	int operator()(int tv1, int tv2)
	{
		cout << "TC::Operator(int tv1, int tv2)ִ����, tv1=" << tv1 << "tv2=" << tv2 << endl;
		return 1;
	}
};

template<class T>
void FunctmpText(T callobj)
{
	callobj(100);
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������

	//��9��  ���Command��ģʽ:��Ϊ��ģʽ��
	//��1��ͨ��һ��������������ģʽ�����д����
	//�����㣬������
	//��2���������Command��ģʽ�����ֽ�ɫ
	//a)Receiver���������ࣩ��Cook�࣬cook_fish,cook_meat��
	//b)Invoker���������ࣩ��Waiter�ࡣ
	//c)Command�����������ࣩ��Command�ࡣ
	//d)ConcreteCommand�����������ࣩ��CommandFish���CommandMeat�ࡣ
	//e)Client���ͻ��ˣ�
	//���壺��һ������������װΪһ������,l�Ա���Щ��������Զ���ķ�ʽͨ���������д��ݣ������˵����󻹿����Ŷ�ִ�л���
	   //������Ҫ����Щ����¼����־���鿴���Ŵ��Լ�֧������ִ�к�Ŀɳ���������
	//��������������з�װ��������󽫶����ͽ����߰������˶����в�ֻ��¶��һ��Execute�����ý�����ִ�ж�����
	//��3������ģʽ��;�о�:�첽ִ�С��ӳ�ִ�С��Ŷ�ִ�С�������ִ�й�����������־��¼�ȣ�������ģʽ��ҪӦ�ó���
	//��3.1�����췶�����Ӷ���ʹ��ʱ�Ķ�����
	//��3.2������ģʽʹ�ó���̸���ص��ܽ�
	//a)��һЩ��ͼ�����
	//b)ң����ʵ�ֶԿ����豸�Ľ���
	//c)����Ķ��ڵ���ִ�У�Task Scheduler
	//d)��Ϸ��ʱ�⵹��ϵͳ�ͻط�ϵͳ��ʵ��

	//����ģʽ���ص㣺
	//a)
	//b)
	//c)
	//����˼����
	//a)���������Ϊ�ص����������: Command ģʽ�ǻص����Ƶ�һ�������������Ʒ��
	//b)�������Σ�������������ࣻCommand�����Լ�ʵ����ع��ܲ���������ߡ�
	//c)����ģʽ������������ִ�C++�пɵ��ö���ıȽ�

	/*_nmsp1::Cook* cook = new _nmsp1::Cook();
	_nmsp1::Command* commandFish = new _nmsp1::CommandFish(cook);
	commandFish->Execute();
	_nmsp1::Command* commandMeat = new _nmsp1::CommandMeat(cook);
	commandMeat->Execute();

	delete commandMeat;
	delete commandFish;
	delete cook;*/

	/*_nmsp2::Cook* cook = new _nmsp2::Cook();
	_nmsp2::Command* commandFish = new _nmsp2::CommandFish(cook);
	_nmsp2::Command* commandMeat = new _nmsp2::CommandMeat(cook);
	_nmsp2::Waiter* waiter = new _nmsp2::Waiter();
	waiter->AddCommand(commandFish);
	waiter->AddCommand(commandMeat);
	waiter->Notify();

	delete waiter;
	delete commandMeat;
	delete commandFish;
	delete cook;*/

	TC tc;
	tc(20);
	tc(30, 50);
	FunctmpText(tc);

}
