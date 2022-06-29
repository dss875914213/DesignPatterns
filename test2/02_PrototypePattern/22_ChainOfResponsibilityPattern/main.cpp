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
	class SalaryHandler
	{
	public:
		void RaiseRequest(const string& sname, int salfigure)
		{
			if (salfigure <= 1000)
				DepManagerSP(sname, salfigure);
			else if (salfigure <= 5000)
				CTOSP(sname, salfigure);
			else
				GenManagerSP(sname, salfigure);
		}

	private:
		void DepManagerSP(const string& sname, int salfigure)
		{
			cout << sname << "的加薪要求为: " << salfigure << "元，部门经理审批通过" << endl;
		}

		void CTOSP(const string& sname, int salfigure)
		{
			cout << sname << "的加薪要求为: " << salfigure << "元，技术总监审批通过" << endl;
		}

		void GenManagerSP(const string& sname, int salfigure)
		{
			cout << sname << "的加薪要求为: " << salfigure << "元，总经理审批通过" << endl;
		}
	};
}

namespace _nmsp2
{
	class RaiseRequest
	{
	public:
		RaiseRequest(const string& sname, int salfigure)
			:m_sname(sname),
			m_isalfigure(salfigure)
		{

		}

		const string& GetName() const
		{
			return m_sname;
		}

		int GetSalFigure() const
		{
			return m_isalfigure;
		}

	private:
		string m_sname;
		int m_isalfigure;
	};

	class ParSalApprover
	{
	public:
		ParSalApprover()
			:m_nextChain(nullptr)
		{

		}

		virtual ~ParSalApprover() {}
		
		void SetNextChain(ParSalApprover* next)
		{
			m_nextChain = next;
		}

		virtual void ProcessRequest(const RaiseRequest& req) = 0;

	protected:
		void SendRequestToNextHandler(const RaiseRequest& req)
		{
			if (m_nextChain != nullptr)
			{
				m_nextChain->ProcessRequest(req);
			}
			else
				cout << req.GetName() << "的加薪要求为: " << req.GetSalFigure() <<"元，但无人能审批" << endl;
		}

	private:
		ParSalApprover* m_nextChain;
	};

	class DepManager_SA :public ParSalApprover
	{
	public:
		void ProcessRequest(const RaiseRequest& req) override
		{
			int salfigure = req.GetSalFigure();
			if (salfigure <= 1000)
				cout << req.GetName() << "的加薪要求为: " << req.GetSalFigure() << "元，部门经理审批通过!" << endl;
			else
				SendRequestToNextHandler(req);
		}
	};

	class CTO_SA :public ParSalApprover
	{
	public:
		void ProcessRequest(const RaiseRequest& req) override
		{
			int salfigure = req.GetSalFigure();
			if (salfigure > 1000 && salfigure<=5000)
				cout << req.GetName() << "的加薪要求为: " << req.GetSalFigure() << "元，技术总监审批通过!" << endl;
			else
				SendRequestToNextHandler(req);
		}
	};

	class GenManager_SA :public ParSalApprover
	{
	public:
		void ProcessRequest(const RaiseRequest& req)
		{
			int salfingure = req.GetSalFigure();
			if(salfingure>5000)
				cout << req.GetName() << "的加薪要求为: " << req.GetSalFigure() << "元，总经理审批通过!" << endl;
			else
				SendRequestToNextHandler(req);
		}
	};
}

namespace _nmsp3
{
	class ParWordFilter
	{
	public:
		ParWordFilter()
			:m_nextChain(nullptr)
		{

		}

		virtual ~ParWordFilter()
		{

		}

		void SetNextChain(ParWordFilter* next)
		{
			m_nextChain = next;
		}

		virtual string ProcessRequest(string strWord) = 0;

	protected:
		string SendRequestToNextHandler(string strWord)
		{
			if (m_nextChain != nullptr)
				return m_nextChain->ProcessRequest(strWord);
			return strWord;
		}

	private:
		ParWordFilter* m_nextChain;
	};

	class SexyWordFilter :public ParWordFilter
	{
	public:
		string ProcessRequest(string strWord) override
		{
			cout << "通过与词库对比，在 strWord 中查找\"性\"敏感词并用xxx来代替" << endl;
			strWord += "XXX";
			return SendRequestToNextHandler(strWord);
		}
	};

	class DirtyWordFilter :public ParWordFilter
	{
	public:
		string ProcessRequest(string strWord) override
		{
			cout << "通过与词库对比，在 strWord 中查找\"脏话\"敏感词并用YYY来代替" << endl;
			strWord += "YYY";
			return SendRequestToNextHandler(strWord);
		}
	};

	class PoliticsWordFilter :public ParWordFilter
	{
	public:
		string ProcessRequest(string strWord) override
		{
			cout << "通过与词库对比，在 strWord 中查找\"政治\"敏感词并用zzz来代替" << endl;
			strWord += "ZZZ";
			return SendRequestToNextHandler(strWord);
		}
	};
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第19章 职责链（Chain Of Responsibility ）模式
	//也叫做责任链模式，行为型模式。----看起来与链表非常类似。

	//（1）一个关于涨薪审批的范例
	//加薪请求： <= 1000，部门经理审批。  1000 < 加薪请求 <= 5000，技术总监审批。   加薪请求 > 5000，总经理审批。

	//（2）引入职责链（Chain Of Responsibility ）模式
	//定义：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成一条链（构成对象链），
	  //并沿着这条链传递该请求，直到有一个对象处理它为止。
	//3种角色：
	//a)Handler(处理者），ParSalApprover类。
	//b)ConcreteHandler（具体处理者），depManager_SA，CTO_SA，genManager_SA类。
	//c)Client （请求者/客户端）.

	//职责链模式的特点：
	//a)一个请求对应多个接收者，但最后只有一个接收者会处理该请求。 请求发送者和接收者是解耦的。
	//b)直线型职责链，可能会看到环形的或者树形结构的职责链。程序运行期间可以动态的添加、修改、删除
		//职责链上的接收者，使针对请求的处理更具有灵活性。这是职责链模式的重要特色。
	//c)增加新处理者不需要修改原有代码。符合开闭原则。
	//d)如果请求传递到职责链末尾仍没有得到处理，则应该有一个合理的缺省处理方式。
	//e)如果职责链比较长，能够处理该请求的接收者在职责链中比较靠后，则可能导致请求处理的延迟。
	  //若需要非常快的请求处理速度，则要权衡是否使用职责链模式。
	//f)可以分别选择不同的接收者对象创建多条不同的职责链以增加接收者在职责链模式中的复用性。

	//（3）单纯与非单纯的职责链模式
	//单纯的职责链模式。
	//非单纯的职责链模式 --- 功能链（可以被多个处理者来处理），即便一个请求未被任何处理者对象处理，也允许。
	   //一般用于权限的多次多次校验，数据的多重检查和过滤等场合。
	//范例：敏感词过滤器。

	//_nmsp1::SalaryHandler sh;
	//sh.RaiseRequest("张三", 15000);
	//sh.RaiseRequest("李四", 3500);
	//sh.RaiseRequest("王五", 800);

	/*_nmsp2::ParSalApprover* pzzlinkobj1 = new _nmsp2::DepManager_SA();
	_nmsp2::ParSalApprover* pzzlinkobj2 = new _nmsp2::CTO_SA();
	_nmsp2::ParSalApprover* pzzlinkobj3 = new _nmsp2::GenManager_SA();

	pzzlinkobj1->SetNextChain(pzzlinkobj2);
	pzzlinkobj2->SetNextChain(pzzlinkobj3);
	pzzlinkobj3->SetNextChain(nullptr);

	_nmsp2::RaiseRequest emp1Req("张三", 15000);
	_nmsp2::RaiseRequest emp2Req("李四", 3500);
	_nmsp2::RaiseRequest emp3Req("王五", 800);

	pzzlinkobj1->ProcessRequest(emp1Req);
	pzzlinkobj1->ProcessRequest(emp2Req);
	pzzlinkobj1->ProcessRequest(emp3Req);

	delete pzzlinkobj1;
	delete pzzlinkobj2;
	delete pzzlinkobj3;*/

	_nmsp3::ParWordFilter* pwflinkobj1 = new _nmsp3::SexyWordFilter();
	_nmsp3::ParWordFilter* pwflinkobj2 = new _nmsp3::DirtyWordFilter();
	_nmsp3::ParWordFilter* pwflinkobj3 = new _nmsp3::PoliticsWordFilter();

	pwflinkobj1->SetNextChain(pwflinkobj2);
	pwflinkobj2->SetNextChain(pwflinkobj3);
	pwflinkobj3->SetNextChain(nullptr);

	string strWordFilterResult = pwflinkobj1->ProcessRequest("你好，这是过滤敏感词测试范例");
	cout << "对敏感词过滤后结果为: " << strWordFilterResult << endl;

	delete pwflinkobj1;
	delete pwflinkobj2;
	delete pwflinkobj3;
}
