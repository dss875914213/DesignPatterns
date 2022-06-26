#include<iostream>
#include<string>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	template<typename T>
	class MyIter
	{
	public:
		virtual void First() = 0; // 指向容器中第一个元素
		virtual void Next() = 0;	// 指向下一个元素
		virtual bool IsDone() = 0;	// 是否遍历完
		virtual T& CurrentItem() = 0;	// 获取当前的元素
		virtual ~MyIter() {}	//	做父类时析构函数应该为虚函数
	};

	template<typename T>
	class MyContainter
	{
	public:
		virtual MyIter<T>* CreateIterator() = 0;	// 创建迭代器
		virtual T& GetItem(int index) = 0;		// 获取当前元素
		virtual int GetSize() = 0;			// 容器元素数量
		virtual ~MyContainter() {}
	};

	template<typename T>
	class MyVectorIter :public MyIter<T>
	{
	public:
		MyVectorIter(MyContainter<T>* tmpc)
			:m_myvector(tmpc),
			m_current(0)
		{
		}
		void First() override
		{
			m_current = 0;
		}

		void Next() override
		{
			m_current++;
		}

		bool IsDone() override
		{
			if (m_current >= m_myvector->GetSize())
				return true;
			return false;
		}

		T& CurrentItem()
		{
			return m_myvector->GetItem(m_current);
		}


	private:
		MyContainter<T>* m_myvector;
		int m_current;
	};

	template<typename T>
	class MyVector :public MyContainter<T>
	{
	public:
		MyVector()
		{
			for (int i = 0; i < 10; i++)
			{
				m_elem[i] = i;
			}
		}

		MyIter<T>* CreateIterator() override
		{
			return new MyVectorIter<T>(this);
		}

		T& GetItem(int index) override
		{
			return m_elem[index];
		}

		int GetSize() override
		{
			return 10;
		}

	private:
		T m_elem[10];
	};
}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第10章 迭代器（Iterator）模式：行为型模式
	//（1）容器和迭代器的简单范例: vector，list
	//迭代器模式正式用来设计和书写迭代器 。
	//将迭代器单独实现为一个类模板。

	//（2）单一职责原则(Single Responsibility Principle：简称SRP)
	//（2.1）单一职责原则的定义：一个类应该只有一个引起变化的原因，通俗的说就是一个类的职责应该单一，应该只做一类事情或者对外只提供一种功能。
	//（2.2）内聚与耦合
	//内聚性：用于衡量一个模块（类）紧密的达到单一目的特性，指的是从功能角度来度量模块内的联系。模块只支持一组功能——高内聚。
	  //如果支持一组不相关的功能——低内聚。
	//耦合性：模块之间相互关联的程度。取决于两者间的接口的复杂程度，相互间的调用方式以及调用时哪些信息需要交互。
	//耦合性几种类型（从高到低）： 
	   //a)内容耦合：耦合程度最高，应该避免使用
	   //b)公共耦合：
	   //c)外部耦合：
	   //d)控制耦合：
	   //e)标记耦合：
	   //f)数据耦合：耦合程度最低 
	//尽量使用数据耦合，少用控制耦合，限制公共耦合的范围，尽量避免使用内容耦合。
	//程序设计：高内聚 低耦合
	//一个类的职责越单一，内聚度就越高，而要达到低耦合的目的，也要尽量遵循依赖倒置原则——高层组件和底层组件都依赖于抽象层或者说尽量使用抽象耦合来代替具体耦合。

	//（3）迭代器模式的范例及现代C++中的迭代器
	//（3.1）迭代器模式范例
	//迭代器设计模式的定义：提供一种方法顺序访问一个聚合对象（容器）中各个元素，而又不暴露该对象的内部表示（实现代码）；
	//4种角色：
	//a)Iterator(抽象迭代器）：MyIter类模板。
	//b)ConcreteIterator(具体迭代器）：MyVector类模板。
	//c)Aggregate（抽象聚合）：MyContainer类模板。
	//d)ConcreteAggregate(具体聚合)：MyVector类模板。
	//（3.2）现代C++中的迭代器

	_nmsp1::MyContainter<int>* vec = new _nmsp1::MyVector<int>();
	_nmsp1::MyIter<int>* iter = new _nmsp1::MyVectorIter<int>(vec);
	for (iter->First(); !iter->IsDone(); iter->Next())
	{
		cout << iter->CurrentItem() << endl;
	}
	delete iter;
	delete vec;
}
