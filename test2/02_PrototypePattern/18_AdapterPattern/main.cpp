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
	class LogToFile
	{
	public:
		void InitFile()
		{

		}
		void WriteToFile(const char* pContent)
		{

		}
		void ReadFromFile()
		{

		}
		void CloseFile()
		{

		}
	};

	//class LogToDataBase
	//{
	//public:
	//	void InitDB()
	//	{

	//	}
	//	void WriteToDB(const char* pContent)
	//	{

	//	}
	//	void ReadFromDB()
	//	{

	//	}
	//	void CloseDB()
	//	{

	//	}
	//};

	class LogToDataBase
	{
	public:
		virtual void InitDB() = 0;
		virtual void WriteToDB(const char* pContent) = 0;
		virtual void ReadFromDB() = 0;
		virtual void CloseDB() = 0;
		virtual ~LogToDataBase() {}
	};

	class LogAdapter :public LogToDataBase
	{
	public:
		LogAdapter(LogToFile* pFile)
			:m_pFile(pFile)
		{

		}

		void InitDB() override
		{
			cout << "在 LogAdapter::InitDB 中适配 LogToFile::InitFile()" << endl;
			m_pFile->InitFile();
		}

		void WriteToDB(const char* pContent) override
		{
			cout << "在 LogAdapter::WriteToDB 中适配 LogToFile::WriteToFile()" << endl;
			m_pFile->WriteToFile(pContent);
		}

		void ReadFromDB() override
		{
			cout << "在 LogAdapter::ReadFromDB() 中适配 LogToFile::ReadFromFile()" << endl;
			m_pFile->ReadFromFile();
		}

		void CloseDB() override
		{
			cout << "在 LogAdapter::CloseDB() 中适配 LogToFile::CloseFile()" << endl;
			m_pFile->CloseFile();
		}

	private:
		LogToFile* m_pFile;
	};
}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第15章 适配器（Adapter）模式：结构型模式
	//（1）一个简单的范例
	//有一天，意外情况/特殊需求
	//a)机房断电导致数据库中的数据发生了损坏无法正确读写，或者网络电缆遭到破坏导致数据库无法成功连接。
	//b)要从以往使用LogToFile类所生成的日志文件中读取一些日志信息。
	//制约因素：
	//a)LogToFile类实现源码很复杂,迁移功能到LogToDatabase类需要很久时间，影响业务。
	//b)LogToFile库提供给项目使用。源码拿不到（只能使用，不能修改）。
	//对一种接口的调用转换成对另外一种接口的调用，说明：
	//a)存在转换的可能
	//b)转换很可能不是一对一，而是一对多。可能转换起来很复杂

	//（2）引入适配器（Adapter）模式
	//定义（实现意图）：将一个类的接口转换成客户希望的另外一个接口。该模式使得原本接口不兼容而不能一起工作的类可以一起工作。
	  //适配器模式 别名 包装器（Wrapper）
	//三种角色：
	//a)Target(目标抽象类），LogToDatabase类
	//b)Adaptee（适配者类），LogToFile 类
	//c)Adapter（适配器类），LogAdapter类。

	//适配器模式-装饰模式。


	//（3）类适配器
	//a)对象适配器(LogToAdapter类)  b)类适配器

	//（4）适配器模式的扩展运用
	//c++标准库:容器适配器、算法（函数）适配器、迭代器适配器：把一个既有的东西进行适当改造比如增加或者减少一点东西就成为了一个适配器。
	//容器适配器：deque，stack,queue
	//算法适配器：std::bind(绑定器)
	//迭代器适配器：reverse_iterator（反向迭代器），对iterator的一层简单封装。
	/*_nmsp1::LogToFile* plog = new _nmsp1::LogToFile();
	plog->InitFile();
	plog->WriteToFile("向日志文件中写入一条日志");
	plog->ReadFromFile();
	plog->CloseFile();
	delete plog;

	_nmsp1::LogToDataBase* plogDB = new _nmsp1::LogToDataBase();
	plogDB->InitDB();
	plogDB->WriteToDB("向数据库写入一条日志");
	plogDB->ReadFromDB();
	plogDB->CloseDB();
	delete plogDB;*/

	_nmsp1::LogToFile* plog2 = new _nmsp1::LogToFile();
	_nmsp1::LogToDataBase* plogdb2 = new _nmsp1::LogAdapter(plog2);
	plogdb2->InitDB();
	plogdb2->WriteToDB("向数据库中写入一条体质，实际是想日志文件写入一条日志");
	plogdb2->ReadFromDB();
	plogdb2->CloseDB();
	delete plogdb2;
	delete plog2;
}
