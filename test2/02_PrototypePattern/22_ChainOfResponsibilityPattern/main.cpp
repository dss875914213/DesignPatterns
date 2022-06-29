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
			cout << sname << "�ļ�нҪ��Ϊ: " << salfigure << "Ԫ�����ž�������ͨ��" << endl;
		}

		void CTOSP(const string& sname, int salfigure)
		{
			cout << sname << "�ļ�нҪ��Ϊ: " << salfigure << "Ԫ�������ܼ�����ͨ��" << endl;
		}

		void GenManagerSP(const string& sname, int salfigure)
		{
			cout << sname << "�ļ�нҪ��Ϊ: " << salfigure << "Ԫ���ܾ�������ͨ��" << endl;
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
				cout << req.GetName() << "�ļ�нҪ��Ϊ: " << req.GetSalFigure() <<"Ԫ��������������" << endl;
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
				cout << req.GetName() << "�ļ�нҪ��Ϊ: " << req.GetSalFigure() << "Ԫ�����ž�������ͨ��!" << endl;
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
				cout << req.GetName() << "�ļ�нҪ��Ϊ: " << req.GetSalFigure() << "Ԫ�������ܼ�����ͨ��!" << endl;
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
				cout << req.GetName() << "�ļ�нҪ��Ϊ: " << req.GetSalFigure() << "Ԫ���ܾ�������ͨ��!" << endl;
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
			cout << "ͨ����ʿ�Աȣ��� strWord �в���\"��\"���дʲ���xxx������" << endl;
			strWord += "XXX";
			return SendRequestToNextHandler(strWord);
		}
	};

	class DirtyWordFilter :public ParWordFilter
	{
	public:
		string ProcessRequest(string strWord) override
		{
			cout << "ͨ����ʿ�Աȣ��� strWord �в���\"�໰\"���дʲ���YYY������" << endl;
			strWord += "YYY";
			return SendRequestToNextHandler(strWord);
		}
	};

	class PoliticsWordFilter :public ParWordFilter
	{
	public:
		string ProcessRequest(string strWord) override
		{
			cout << "ͨ����ʿ�Աȣ��� strWord �в���\"����\"���дʲ���zzz������" << endl;
			strWord += "ZZZ";
			return SendRequestToNextHandler(strWord);
		}
	};
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��19�� ְ������Chain Of Responsibility ��ģʽ
	//Ҳ����������ģʽ����Ϊ��ģʽ��----������������ǳ����ơ�

	//��1��һ��������н�����ķ���
	//��н���� <= 1000�����ž���������  1000 < ��н���� <= 5000�������ܼ�������   ��н���� > 5000���ܾ���������

	//��2������ְ������Chain Of Responsibility ��ģʽ
	//���壺ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ������Щ��������һ���������ɶ���������
	  //���������������ݸ�����ֱ����һ����������Ϊֹ��
	//3�ֽ�ɫ��
	//a)Handler(�����ߣ���ParSalApprover�ࡣ
	//b)ConcreteHandler�����崦���ߣ���depManager_SA��CTO_SA��genManager_SA�ࡣ
	//c)Client ��������/�ͻ��ˣ�.

	//ְ����ģʽ���ص㣺
	//a)һ�������Ӧ��������ߣ������ֻ��һ�������߻ᴦ������� �������ߺͽ������ǽ���ġ�
	//b)ֱ����ְ���������ܻῴ�����εĻ������νṹ��ְ���������������ڼ���Զ�̬����ӡ��޸ġ�ɾ��
		//ְ�����ϵĽ����ߣ�ʹ�������Ĵ������������ԡ�����ְ����ģʽ����Ҫ��ɫ��
	//c)�����´����߲���Ҫ�޸�ԭ�д��롣���Ͽ���ԭ��
	//d)������󴫵ݵ�ְ����ĩβ��û�еõ�������Ӧ����һ�������ȱʡ����ʽ��
	//e)���ְ�����Ƚϳ����ܹ����������Ľ�������ְ�����бȽϿ�������ܵ�����������ӳ١�
	  //����Ҫ�ǳ�����������ٶȣ���ҪȨ���Ƿ�ʹ��ְ����ģʽ��
	//f)���Էֱ�ѡ��ͬ�Ľ����߶��󴴽�������ͬ��ְ���������ӽ�������ְ����ģʽ�еĸ����ԡ�

	//��3��������ǵ�����ְ����ģʽ
	//������ְ����ģʽ��
	//�ǵ�����ְ����ģʽ --- �����������Ա����������������������һ������δ���κδ����߶�����Ҳ����
	   //һ������Ȩ�޵Ķ�ζ��У�飬���ݵĶ��ؼ��͹��˵ȳ��ϡ�
	//���������дʹ�������

	//_nmsp1::SalaryHandler sh;
	//sh.RaiseRequest("����", 15000);
	//sh.RaiseRequest("����", 3500);
	//sh.RaiseRequest("����", 800);

	/*_nmsp2::ParSalApprover* pzzlinkobj1 = new _nmsp2::DepManager_SA();
	_nmsp2::ParSalApprover* pzzlinkobj2 = new _nmsp2::CTO_SA();
	_nmsp2::ParSalApprover* pzzlinkobj3 = new _nmsp2::GenManager_SA();

	pzzlinkobj1->SetNextChain(pzzlinkobj2);
	pzzlinkobj2->SetNextChain(pzzlinkobj3);
	pzzlinkobj3->SetNextChain(nullptr);

	_nmsp2::RaiseRequest emp1Req("����", 15000);
	_nmsp2::RaiseRequest emp2Req("����", 3500);
	_nmsp2::RaiseRequest emp3Req("����", 800);

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

	string strWordFilterResult = pwflinkobj1->ProcessRequest("��ã����ǹ������дʲ��Է���");
	cout << "�����дʹ��˺���Ϊ: " << strWordFilterResult << endl;

	delete pwflinkobj1;
	delete pwflinkobj2;
	delete pwflinkobj3;
}
