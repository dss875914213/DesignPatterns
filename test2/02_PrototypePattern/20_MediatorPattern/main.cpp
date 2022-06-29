#include<iostream>
#include<string>
#include <map>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class CtlParent
	{
	public:
		CtlParent(string caption)
			:m_caption(caption)
		{

		}
		virtual ~CtlParent() {}
	public:
		virtual void Changed(map<string, CtlParent*>& tmpuictllist) = 0;
		virtual void Enable(bool sign) = 0;

	protected:
		string m_caption;
	};

	class Button :public CtlParent
	{
	public:
		Button(string caption)
			:CtlParent(caption)
		{}

		void Enable(bool sign) override
		{
			if (sign == true)
				cout << "按钮\"" << m_caption << "\"被设置为了\"启用\"状态" << endl;
			else
				cout << "按钮\"" << m_caption << "\"被设置为了\"禁用\"状态" << endl;
		}


		void Changed(map<string, CtlParent*>& tmpuicullist) override
		{
			if (m_caption == "登录")
				cout << "开始游戏登录验证" << endl;
			else if (m_caption == "退出")
				cout << "游戏退出，再见!" << endl;
		}
	};

	class RadioBtn :public CtlParent
	{
	public:
		RadioBtn(string caption)
			:CtlParent(caption)
		{}

		void Enable(bool sign) override
		{
			
		}

		void Selected(bool sign)
		{
			if (sign == true)
				cout << "单选按钮\"" << m_caption << "\"被选中" << endl;
			else
				cout << "单选按钮\"" << m_caption << "\"被取消选中" << endl;
		}

		void Changed(map<string, CtlParent*>& tmpuicullist) override;
		
	};

	class EditCtl :public CtlParent
	{
	public:
		EditCtl(string caption)
			:CtlParent(caption)
		{}

		void Enable(bool sign) override
		{
			if (sign == true)
				cout << "编辑框\"" << m_caption << "\"被设置为了\"启用\"状态" << endl;
			else
				cout << "编辑框\"" << m_caption << "\"被设置为了\"禁用\"状态" << endl;
		}

		bool IsContentEmpty()
		{
			return m_content.empty();
		}

		void Changed(map<string, CtlParent*>& tmpuicullist) override
		{
			if ((static_cast<EditCtl*>(tmpuicullist["账号"]))->IsContentEmpty()
				|| (static_cast<EditCtl*>(tmpuicullist["密码"]))->IsContentEmpty())
				tmpuicullist["登录"]->Enable(false);
			else
				tmpuicullist["登录"]->Enable(true);
		}
	private:
		string m_content;
	};

	void RadioBtn::Changed(map<string, CtlParent*>& tmpuicullist)
	{
		if (m_caption == "游客登录")
		{
			(static_cast<RadioBtn*>(tmpuicullist["游客登录"]))->Selected(true);
			(static_cast<RadioBtn*>(tmpuicullist["账号登录"]))->Selected(false);

			tmpuicullist["账号"]->Enable(false);
			tmpuicullist["密码"]->Enable(false);

			tmpuicullist["登录"]->Enable(true);
		}
		else if (m_caption == "账号登录")
		{
			(static_cast<RadioBtn*>(tmpuicullist["游客登录"]))->Selected(false);
			(static_cast<RadioBtn*>(tmpuicullist["账号登录"]))->Selected(true);

			tmpuicullist["账号"]->Enable(true);
			tmpuicullist["密码"]->Enable(true);

			if ((static_cast<EditCtl*>(tmpuicullist["账号"]))->IsContentEmpty()
				|| (static_cast<EditCtl*>(tmpuicullist["密码"]))->IsContentEmpty())
			{
				tmpuicullist["登录"]->Enable(false);
			}
			else
				tmpuicullist["登录"]->Enable(true);
		}
	}
}

namespace _nmsp2
{
	class CtlParent;

	class Mediator
	{
	public:
		virtual ~Mediator() {}
	public:
		virtual void CreateCtrl() = 0;
		virtual void CtlChanged(CtlParent*) = 0;
	};

	class CtlParent
	{
	public:
		CtlParent(Mediator* ptmpm, string caption)
			:m_pMediator(ptmpm),
			m_caption(caption)
		{

		}
		virtual ~CtlParent() {}

	public:
		virtual void Changed()
		{
			m_pMediator->CtlChanged(this);
		}

		virtual void Enable(bool sign) = 0;

	protected:
		Mediator* m_pMediator;
		string m_caption;
	};

	class Button :public CtlParent
	{
	public:
		Button(Mediator* ptmpm, string caption)
			:CtlParent(ptmpm, caption)
		{

		}

		void Enable(bool sign) override
		{
			if (sign == true)
				cout << "按钮\"" << m_caption << "\"被设置为了\"启用\"状态" << endl;
			else
				cout << "按钮\"" << m_caption << "\"被设置为了\"禁用\"状态" << endl;
		}
	};

	class RadioBtn :public CtlParent
	{
	public:
		RadioBtn(Mediator* ptmpm, string caption)
			:CtlParent(ptmpm, caption)
		{

		}

		void Enable(bool sign) override
		{
			
		}

		void Selected(bool sign)
		{
			if (sign == true)
				cout << "单选按钮\"" << m_caption << "\"被选中" << endl;
			else
				cout << "单选按钮\"" << m_caption << "\"被取消选中" << endl;
		}
	};

	class EditCtl :public CtlParent
	{
	public:
		EditCtl(Mediator* ptmpm, string caption)
			:CtlParent(ptmpm, caption)
		{

		}

		void Enable(bool sign) override
		{
			if (sign == true)
				cout << "编辑框\"" << m_caption << "\"被设置为了\"启用\"状态" << endl;
			else
				cout << "编辑框\"" << m_caption << "\"被设置为了\"禁用\"状态" << endl;
		}

		bool IsContentEmpty()
		{
			return m_content.empty();
		}

	private:
		string m_content;
	};

	class ConcreMediator :public Mediator
	{
	public:
		ConcreMediator()
			:m_pLogin(NULL),
			m_pLogout(NULL),
			m_pRbtn1(NULL),
			m_pRbtn2(NULL),
			m_pEdtctl1(NULL),
			m_pEdtctl2(NULL)
		{

		}

		~ConcreMediator()
		{
			if (m_pLogin)
			{
				delete m_pLogin;
				m_pLogin = NULL;
			}

			if (m_pLogout)
			{
				delete m_pLogout;
				m_pLogout = NULL;
			}

			if (m_pRbtn1)
			{
				delete m_pRbtn1;
				m_pRbtn1 = NULL;
			}

			if (m_pRbtn2)
			{
				delete m_pRbtn2;
				m_pRbtn2 = NULL;
			}

			if (m_pEdtctl1)
			{
				delete m_pEdtctl1;
				m_pEdtctl1 = NULL;
			}

			if (m_pEdtctl2)
			{
				delete m_pEdtctl2;
				m_pEdtctl2 = NULL;
			}
		}

		void CreateCtrl() override
		{
			m_pLogin = new Button(this, "登录");
			m_pLogout = new Button(this, "退出");

			m_pRbtn1 = new RadioBtn(this, "游客登录");
			m_pRbtn2 = new RadioBtn(this, "账号登录");

			m_pEdtctl1 = new EditCtl(this, "账号");
			m_pEdtctl2 = new EditCtl(this, "密码");

			m_pRbtn1->Selected(true);
			m_pRbtn2->Selected(false);

			m_pEdtctl1->Enable(false);
			m_pEdtctl2->Enable(false);

			m_pLogin->Enable(true);
			m_pLogout->Enable(true);
		}

		void CtlChanged(CtlParent* pCtrl) override
		{
			if (pCtrl == m_pLogin)
				cout << "开始游戏登录验证" << endl;
			else if (pCtrl == m_pLogout)
				cout << "游戏退出" << endl;

			if (pCtrl == m_pRbtn1)
			{
				m_pRbtn1->Selected(true);
				m_pRbtn2->Selected(false);

				m_pEdtctl1->Enable(false);
				m_pEdtctl2->Enable(false);

				m_pLogin->Enable(true);
			}
			else if (pCtrl == m_pRbtn2)
			{
				m_pRbtn1->Selected(false);
				m_pRbtn2->Selected(true);
				m_pEdtctl1->Enable(true);
				m_pEdtctl2->Enable(true);
				if (m_pEdtctl1->IsContentEmpty() || m_pEdtctl2->IsContentEmpty())
					m_pLogin->Enable(false);
				else
					m_pLogin->Enable(true);
			}

			if (pCtrl == m_pEdtctl1 || pCtrl == m_pEdtctl2)
			{
				if (m_pEdtctl1->IsContentEmpty() || m_pEdtctl2->IsContentEmpty())
					m_pLogin->Enable(false);
				else
					m_pLogin->Enable(true);
			}

		}

	public:
		Button* m_pLogin;
		Button* m_pLogout;
		RadioBtn* m_pRbtn1;
		RadioBtn* m_pRbtn2;
		EditCtl* m_pEdtctl1;
		EditCtl* m_pEdtctl2;
	};

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第17章 中介者（Mediator）模式：调停者模式，行为型模式。
	//（1）中介者的基本概念
	//a)计算的各个组成部件：主板
	//b)qq聊天：与好友或者陌生人单独聊天（私聊）；加入到一个qq群中。
	//c)飞机的安全飞行与安全着陆：塔台

	//（2）中介者模式范例的引入:事件类驱动的软件中有比较广泛的应用，尤其是常常运用在程序的UI界面设计中
	//（3）引入中介者（Mediator）模式
	//定义：用一个中介对象（中介者）来封装一系列的对象交互。中介者使各个对象不需要显式地相互引用，从而使其耦合松散，
	  //而且可以独立地改变他们之间的交互。
	//4种角色
	//a)Mediator(抽象中介者类），Mediator类。
	//b)ConcreteMediator(具体中介者类）：concrMediator类。
	//c)Colleague(抽象同事类)，CtlParent类。
	//d)ConcreteColleague(具体同事类），Button,RadioBtn,EditCtrl类。
	//中介者模式一般用于一组对象以定义良好但复杂的方式进行通信的场合，由中介者负责控制和协调一组对象之间的交互。
	//优缺点：
	//a)集中处理复杂的对象之间的沟通和控制，将以往多对多简化为1对多。
	//b)将同事对象进行解耦。
	//c)将各种控制逻辑代码都集中（转移）到了中介者类中实现。可能会中介者类的实现变得非常复杂甚至难以维护。要平衡好交互复杂度和实现复杂度。
	//如果中介者实现的太复杂，可能会抵消掉使用该模式在其他方面带来的好处。

	//在什么情况下考虑使用中介者模式：
	//a)对象之间引用关系过于复杂，某个对象变化会导致大量其他对象的变化。
	//b)某个对象与大量其他对象进行连接，通信从而造成该对象很难被复用。
	//c)希望将多个类（同事类）中的行为封装到一个类（中介者类）中来实现。

	/*map<string, _nmsp1::CtlParent*> uictllist;
	uictllist["登录"] = new _nmsp1::Button("登录");
	uictllist["退出"] = new _nmsp1::Button("退出");

	uictllist["游客登录"] = new _nmsp1::RadioBtn("游客登录");
	uictllist["账号登录"] = new _nmsp1::RadioBtn("账号登录");

	uictllist["账号"] = new _nmsp1::EditCtl("账号");
	uictllist["密码"] = new _nmsp1::EditCtl("密码");

	(static_cast<_nmsp1::RadioBtn*>(uictllist["游客登录"]))->Selected(true);
	(static_cast<_nmsp1::RadioBtn*>(uictllist["账号登录"]))->Selected(false);

	uictllist["账号"]->Enable(false);
	uictllist["密码"]->Enable(false);
	uictllist["登录"]->Enable(true);
	uictllist["退出"]->Enable(true);

	cout << "------------" << endl;
	uictllist["账号登录"]->Changed(uictllist);

	for (auto iter = uictllist.begin(); iter != uictllist.end(); iter++)
	{
		delete iter->second;
		iter->second = nullptr;
	}*/

	_nmsp2::ConcreMediator mymedia;
	mymedia.CreateCtrl();
	mymedia.m_pRbtn2->Changed();
}
