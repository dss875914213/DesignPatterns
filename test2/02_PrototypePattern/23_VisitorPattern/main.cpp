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
	class Visitor;
	class Medicine
	{
	public:
		virtual string GetMdcName() = 0;
		virtual float GetPrice() = 0;
		virtual void Accept(Visitor* pvisitor) = 0;

		virtual ~Medicine() {}
	};

	class M_asplcrp :public Medicine
	{
	public:
		string GetMdcName() override
		{
			return "阿司匹林肠溶片";
		}

		float GetPrice() override
		{
			return 46.8f;
		}

		void Accept(Visitor* pvisitor) override;
	};

	class M_fftdnhsp :public Medicine
	{
	public:
		string GetMdcName() override
		{
			return "氟伐他汀钠缓释片";
		}

		float GetPrice() override
		{
			return 111.3f;
		}
		void Accept(Visitor* pvisitor) override;
	};

	class M_dlx :public Medicine
	{
	public:
		string GetMdcName() override
		{
			return "黛力新";
		}

		float GetPrice() override
		{
			return 122.0f;
		}
		void Accept(Visitor* pvisitor) override;
	};

	class MedicineProc
	{
	public:
		void AddMedicine(Medicine* p_mdc)
		{
			m_mdclist.push_back(p_mdc);
		}

		void ProcAction(string strvisitor)
		{
			if (strvisitor == "收费人员")
			{
				float totalcost = 0.0f;
				for (auto iter = m_mdclist.begin(); iter != m_mdclist.end(); iter++)
				{
					float tmpprice = (*iter)->GetPrice();
					cout << "收费人员累计药品\"" << (*iter)->GetMdcName() << "\"的价格: " << tmpprice << endl;
					totalcost += tmpprice;
				}
				cout << "所有药品的总价为: " << totalcost << ",收费人员收取了我的费用!" << endl;
			}
			else if (strvisitor == "取药人员")
			{
				for (auto iter = m_mdclist.begin(); iter != m_mdclist.end(); iter++)
				{
					cout << "取药人员将药品\"" << (*iter)->GetMdcName() << "\"拿给了我!" << endl;
				}
			}
			else if (strvisitor == "营养师")
			{
				cout << "营养师的建议: 主食中多搭配粗粮，适当使用肉食! " << endl;
			}
			else if (strvisitor == "健身教练")
				cout << "健身教练建议: 多做有氧运动如慢跑(35分钟即可),慢跑前后要热身，忌焦虑，忌熬夜，以22:30之前卧床休息为佳!" << endl;

		}

	private:
		list<Medicine*>	m_mdclist;
	};

	class Visitor
	{
	public:
		virtual ~Visitor() {}

		virtual void Visit_elm_asplcrp(M_asplcrp* pelem) = 0;
		virtual void Visit_elm_fftdnhsp(M_fftdnhsp* pelem) = 0;
		virtual void Visit_elm_dlx(M_dlx* pelem) = 0;
	};

	class Visitor_SFRY :public Visitor
	{
	public:
		void Visit_elm_asplcrp(M_asplcrp* pelem) override
		{
			float tmpprice = pelem->GetPrice();
			cout << "收费人员累计药品\"" << pelem->GetMdcName() << "\"的价格:" << tmpprice << endl;
			m_totalcost += tmpprice;
		}
		void Visit_elm_fftdnhsp(M_fftdnhsp* pelem) override
		{
			float tmpprice = pelem->GetPrice();
			cout << "收费人员累计药品\"" << pelem->GetMdcName() << "\"的价格:" << tmpprice << endl;
			m_totalcost += tmpprice;
		}
		void Visit_elm_dlx(M_dlx* pelem) override
		{
			float tmpprice = pelem->GetPrice();
			cout << "收费人员累计药品\"" << pelem->GetMdcName() << "\"的价格:" << tmpprice << endl;
			m_totalcost += tmpprice;
		}

		float GetTotalCost()
		{
			return m_totalcost;
		}

	private:
		float m_totalcost =0;
	};

	class Visitor_QYRY :public Visitor 
	{
	public:
		void Visit_elm_asplcrp(M_asplcrp* pelem) override
		{
			cout << "取药人员将药品\"" << pelem->GetMdcName() << "\"拿给了我!" << endl;
		}
		void Visit_elm_fftdnhsp(M_fftdnhsp* pelem) override
		{
			cout << "取药人员将药品\"" << pelem->GetMdcName() << "\"拿给了我!" << endl;
		}
		void Visit_elm_dlx(M_dlx* pelem) override
		{
			cout << "取药人员将药品\"" << pelem->GetMdcName() << "\"拿给了我!" << endl;
		}
	};

	class Visitor_YYS :public Visitor
	{
	public:
		void Visit_elm_asplcrp(M_asplcrp* pelem) override
		{
			cout << "营养师建议:多吃粗粮少吃油，可以有效预防血栓" << endl;
		}
		void Visit_elm_fftdnhsp(M_fftdnhsp* pelem) override
		{
			cout << "营养师建议:多吃xx" << endl;
		}
		void Visit_elm_dlx(M_dlx* pelem) override
		{
			cout << "营养师建议:多出去走走" << endl;
		}
	};

	void M_asplcrp::Accept(Visitor* pvisitor)
	{
		pvisitor->Visit_elm_asplcrp(this);
	}

	void M_fftdnhsp::Accept(Visitor* pvisitor)
	{
		pvisitor->Visit_elm_fftdnhsp(this);

	}

	void M_dlx::Accept(Visitor* pvisitor)
	{
		pvisitor->Visit_elm_dlx(this);
	}

	class ObjectStructor
	{
	public:
		void AddMedicine(Medicine* p_mdc)
		{
			m_mdclist.push_back(p_mdc);
		}

		void ProcAction(Visitor* pvisitor)
		{
			for (auto iter = m_mdclist.begin(); iter != m_mdclist.end(); iter++)
				(*iter)->Accept(pvisitor);
		}

	private:
		list<Medicine*> m_mdclist;
	};
}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第20章 访问者（Visitor）模式：访问器模式，行为型模式。
	//（1）一个具体范例的逐渐演化
	//阿司匹林肠溶片：改善血液流通，预防血栓形成，血栓形成就产生阻塞，人就会直接面临危险；
	//氟伐他汀钠缓释片：降血脂。因为血脂高意味着血流慢，营养无法运输到身体各部位，还很可能引发心脑血管疾病；
	//黛力新：医生说我的心脏没有器质性病变，是神经出现了紊乱，出现的症状是因为神经的误报，因此开此药治疗植物神经功能紊乱以及身心疾病伴有的焦虑症状；
	//缴费，取药。

	//访问者模式：包含 访问者（收费人员、取药人员、营养师、健身教练），被访问者（元素）（药品单中的三种药品） 两个重要角色
	//访问：a)串门。b)查看一个东西

	/*_nmsp1::Medicine* pm1 = new _nmsp1::M_asplcrp();
	_nmsp1::Medicine* pm2 = new _nmsp1::M_fftdnhsp();
	_nmsp1::Medicine* pm3 = new _nmsp1::M_dlx();

	_nmsp1::MedicineProc mdcprocobj;
	mdcprocobj.AddMedicine(pm1);
	mdcprocobj.AddMedicine(pm2);
	mdcprocobj.AddMedicine(pm3);

	mdcprocobj.ProcAction("收费人员");
	mdcprocobj.ProcAction("取药人员");

	delete pm1;
	delete pm2;
	delete pm3;*/

	_nmsp1::Visitor_SFRY visitor_sf;
	_nmsp1::M_asplcrp mdc_asplcrp;
	_nmsp1::M_fftdnhsp mdc_fftdnhsp;
	_nmsp1::M_dlx mdc_dlx;

	mdc_asplcrp.Accept(&visitor_sf);
	mdc_fftdnhsp.Accept(&visitor_sf);
	mdc_dlx.Accept(&visitor_sf);
	cout << "所有药品的总价为: " << visitor_sf.GetTotalCost() << ",收费人员收取了我的费用!" << endl;

	_nmsp1::Visitor_QYRY visitor_qy;
	mdc_asplcrp.Accept(&visitor_qy);
	mdc_fftdnhsp.Accept(&visitor_qy);
	mdc_dlx.Accept(&visitor_qy);

	_nmsp1::Visitor_YYS visitor_yys;
	mdc_asplcrp.Accept(&visitor_yys);
	mdc_fftdnhsp.Accept(&visitor_yys);
	mdc_dlx.Accept(&visitor_yys);

	_nmsp1::ObjectStructor objstruc;
	objstruc.AddMedicine(&mdc_asplcrp);
	objstruc.AddMedicine(&mdc_fftdnhsp);
	objstruc.AddMedicine(&mdc_dlx);
	objstruc.ProcAction(&visitor_yys);
}
