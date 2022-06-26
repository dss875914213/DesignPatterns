#include<iostream>
#include<string>
#include <vector>
#include <fstream>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class WebAddr
	{
	public:
		virtual void Visit() = 0;
		virtual ~WebAddr(){}
	};

	class WebAddrShopping :public WebAddr
	{
	public:
		void Visit() override
		{
			cout << "访问 WebAddr_Shopping购物网站" << endl;
		}
	};

	class WebAddrVideo :public WebAddr
	{
	public:
		void Visit() override
		{
			cout << "访问 WebAddr_Video购物网站" << endl;
		}
	};

	class WebAddrProxy :public WebAddr
	{
	public:
		WebAddrProxy(WebAddr* pwebaddr)
			:m_pwebAddr(pwebaddr)
		{

		}

		void Visit() override
		{
			m_pwebAddr->Visit();
		}

	private:
		WebAddr* m_pwebAddr;
	};

	class WebAddr_Shopping_Proxy :public WebAddr
	{
	public:
		void Visit() override
		{
			WebAddr* pWebAddr = new WebAddrShopping();
			pWebAddr->Visit();

			delete pWebAddr;
		}
	};
}

namespace _nmsp2
{
	vector<string> g_fileItemList;

	class ReadInfo
	{
	public:
		virtual void Read() = 0;
		virtual ~ReadInfo() {}
	};

	class ReadInfoFromFile :public ReadInfo
	{
	public:
		void Read() override
		{
			ifstream fin("test.txt");
			if (!fin)
			{
				cout << "文件打开失败" << endl;
				return;
			}
			string linebuf;
			while (getline(fin, linebuf))
			{
				if (!linebuf.empty())
				{
					g_fileItemList.push_back(linebuf);
				}
			}
			fin.close();
		}
	};

	class ReadInfoProxy :public ReadInfo
	{
	public:
		void Read() override
		{
			if (!m_loaded)
			{
				m_loaded = true;
				cout << "从文件中读取如下数据--------" << endl;
				ReadInfoFromFile* rf = new ReadInfoFromFile();
				rf->Read();
				delete rf;
			}
			else
			{
				cout << "从缓存中读取如下数据--------" << endl;
			}

			for (auto iter = g_fileItemList.begin(); iter != g_fileItemList.end(); iter++)
				cout << *iter << endl;
		}

	private:
		bool m_loaded = false;
	};
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第14章 代理（Proxy）模式：结构型模式
	//目的：为客户端增加额外的功能、约束或针对客户端的调用屏蔽一些复杂的细节问题。
	//（1）基本概念和范例
	//通过引入代理类来为原始类（被代理类）增加额外的能力——新功能、新服务，约束或者限制。
	//使用代理类的程序员与开发这个代理类的程序员并不是同一个程序员甚至可能是两个不同公司的程序员。

	//（2）引入代理（Proxy）模式：
	//定义（实现意图）：为其他对象提供一种代理以控制对这个对象的访问。
	//三种角色：
	//a)Subject（抽象主题），WebAddr类。
	//b)Proxy（代理主题）：WebAddr_Shopping_Proxy类。
	//c)RealSubject（真实主题）：WebAddr_Shopping

	//代理模式和装饰模式对比；
	//代理模式：代表真实主题并给真实主题增加一些新能力或者责任，这些功能与真实主题要实现的功能可能没有相关性，主要是控制对真实主题的访问。
	//装饰模式：新功能与原有构件能力具有相关性，是对原有构件能力或者行为的扩展（增强）。

	//（3）代理模式的应用场合探究
	//（ 3.1 ）代理模式常用应用场景
	//常见的代理包括但不限于如下这些类型：
	//a)远程代理（Remote Proxy）
	//b)虚拟代理（Virtual Proxy)
	//c)保护代理（Protect Proxy）
	//d)缓存/缓冲代理（Cache Proxy）
	//e)智能引用代理（Smart Reference Proxy）。shared_ptr
	//f)写时复制（copy-on-write)优化代理：string
	//g)防火墙代理、同步代理，复杂隐藏代理等。

	//（ 3.2 ）缓存 / 缓冲代理（Cache Proxy）一例

	/*_nmsp1::WebAddr* wba1 = new _nmsp1::WebAddrShopping();
	wba1->Visit();

	_nmsp1::WebAddr* wba2 = new _nmsp1::WebAddrVideo();
	wba2->Visit();

	delete wba1;
	delete wba2;*/


	/*_nmsp1::WebAddr* wba1 = new _nmsp1::WebAddrShopping();
	_nmsp1::WebAddr* wba2 = new _nmsp1::WebAddrVideo();
	_nmsp1::WebAddrProxy* wbaProxy1 = new _nmsp1::WebAddrProxy(wba1);
	wbaProxy1->Visit();

	_nmsp1::WebAddrProxy* wbaProxy2 = new _nmsp1::WebAddrProxy(wba2);
	wbaProxy2->Visit();

	delete wba1;
	delete wba2;
	delete wbaProxy1;
	delete wbaProxy2;

	_nmsp1::WebAddr_Shopping_Proxy* wbasproxy = new _nmsp1::WebAddr_Shopping_Proxy();
	wbasproxy->Visit();

	delete wbasproxy;*/

	_nmsp2::ReadInfo* preadInfoProxy = new _nmsp2::ReadInfoProxy();
	preadInfoProxy->Read();
	preadInfoProxy->Read();
	preadInfoProxy->Read();

	delete preadInfoProxy;
}
