#include<iostream>
#include<string>
#include <list>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
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
			cout << "做鱼" << endl;
		}

		void CookMeat()
		{
			cout << "做肉" << endl;
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
			cout << "做鱼" << endl;
		}

		void CookMeat()
		{
			cout << "做肉" << endl;
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
		cout << "TC::Operator(int tv) 执行了, tv=" << tv << endl;
	}

	int operator()(int tv1, int tv2)
	{
		cout << "TC::Operator(int tv1, int tv2)执行了, tv1=" << tv1 << "tv2=" << tv2 << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

	//第9章  命令（Command）模式:行为型模式。
	//（1）通过一个范例引出命令模式代码编写方法
	//红烧鱼，锅包肉
	//（2）引入命令（Command）模式：五种角色
	//a)Receiver（接收者类）：Cook类，cook_fish,cook_meat；
	//b)Invoker（调用者类）：Waiter类。
	//c)Command（抽象命令类）：Command类。
	//d)ConcreteCommand（具体命令类）：CommandFish类和CommandMeat类。
	//e)Client（客户端）
	//定义：将一个请求或命令封装为一个对象,l以便这些请求可以以对象的方式通过参数进行传递，对象化了的请求还可以排队执行或者
	   //根据需要将这些请求录入日志供查看和排错，以及支持请求执行后的可撤销操作。
	//能力：对请求进行封装，命令对象将动作和接收者包裹到了对象中并只暴露了一个Execute方法让接收者执行动作。
	//（3）命令模式用途研究:异步执行、延迟执行、排队执行、撤销、执行过程中增加日志记录等，是命令模式主要应用场景
	//（3.1）改造范例增加对象使用时的独立性
	//（3.2）命令模式使用场景谈与特点总结
	//a)在一些绘图软件中
	//b)遥控器实现对控制设备的解耦
	//c)任务的定期调度执行：Task Scheduler
	//d)游戏中时光倒流系统和回放系统的实现

	//命令模式的特点：
	//a)
	//b)
	//c)
	//问题思考：
	//a)命令对象作为回调函数的替代: Command 模式是回调机制的一个面向对象的替代品。
	//b)极端情形：不引入调用者类；Command子类自己实现相关功能不引入接收者。
	//c)命令模式中命令对象与现代C++中可调用对象的比较

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
