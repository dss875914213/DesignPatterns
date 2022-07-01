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
			return "��˾ƥ�ֳ���Ƭ";
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
			return "������͡�ƻ���Ƭ";
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
			return "������";
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
			if (strvisitor == "�շ���Ա")
			{
				float totalcost = 0.0f;
				for (auto iter = m_mdclist.begin(); iter != m_mdclist.end(); iter++)
				{
					float tmpprice = (*iter)->GetPrice();
					cout << "�շ���Ա�ۼ�ҩƷ\"" << (*iter)->GetMdcName() << "\"�ļ۸�: " << tmpprice << endl;
					totalcost += tmpprice;
				}
				cout << "����ҩƷ���ܼ�Ϊ: " << totalcost << ",�շ���Ա��ȡ���ҵķ���!" << endl;
			}
			else if (strvisitor == "ȡҩ��Ա")
			{
				for (auto iter = m_mdclist.begin(); iter != m_mdclist.end(); iter++)
				{
					cout << "ȡҩ��Ա��ҩƷ\"" << (*iter)->GetMdcName() << "\"�ø�����!" << endl;
				}
			}
			else if (strvisitor == "Ӫ��ʦ")
			{
				cout << "Ӫ��ʦ�Ľ���: ��ʳ�ж����������ʵ�ʹ����ʳ! " << endl;
			}
			else if (strvisitor == "�������")
				cout << "�����������: ���������˶�������(35���Ӽ���),����ǰ��Ҫ�����ɽ��ǣ��ɰ�ҹ����22:30֮ǰ�Դ���ϢΪ��!" << endl;

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
			cout << "�շ���Ա�ۼ�ҩƷ\"" << pelem->GetMdcName() << "\"�ļ۸�:" << tmpprice << endl;
			m_totalcost += tmpprice;
		}
		void Visit_elm_fftdnhsp(M_fftdnhsp* pelem) override
		{
			float tmpprice = pelem->GetPrice();
			cout << "�շ���Ա�ۼ�ҩƷ\"" << pelem->GetMdcName() << "\"�ļ۸�:" << tmpprice << endl;
			m_totalcost += tmpprice;
		}
		void Visit_elm_dlx(M_dlx* pelem) override
		{
			float tmpprice = pelem->GetPrice();
			cout << "�շ���Ա�ۼ�ҩƷ\"" << pelem->GetMdcName() << "\"�ļ۸�:" << tmpprice << endl;
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
			cout << "ȡҩ��Ա��ҩƷ\"" << pelem->GetMdcName() << "\"�ø�����!" << endl;
		}
		void Visit_elm_fftdnhsp(M_fftdnhsp* pelem) override
		{
			cout << "ȡҩ��Ա��ҩƷ\"" << pelem->GetMdcName() << "\"�ø�����!" << endl;
		}
		void Visit_elm_dlx(M_dlx* pelem) override
		{
			cout << "ȡҩ��Ա��ҩƷ\"" << pelem->GetMdcName() << "\"�ø�����!" << endl;
		}
	};

	class Visitor_YYS :public Visitor
	{
	public:
		void Visit_elm_asplcrp(M_asplcrp* pelem) override
		{
			cout << "Ӫ��ʦ����:��Դ����ٳ��ͣ�������ЧԤ��Ѫ˨" << endl;
		}
		void Visit_elm_fftdnhsp(M_fftdnhsp* pelem) override
		{
			cout << "Ӫ��ʦ����:���xx" << endl;
		}
		void Visit_elm_dlx(M_dlx* pelem) override
		{
			cout << "Ӫ��ʦ����:���ȥ����" << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��20�� �����ߣ�Visitor��ģʽ��������ģʽ����Ϊ��ģʽ��
	//��1��һ�����巶�������ݻ�
	//��˾ƥ�ֳ���Ƭ������ѪҺ��ͨ��Ԥ��Ѫ˨�γɣ�Ѫ˨�γɾͲ����������˾ͻ�ֱ������Σ�գ�
	//������͡�ƻ���Ƭ����Ѫ֬����ΪѪ֬����ζ��Ѫ������Ӫ���޷����䵽�������λ�����ܿ�����������Ѫ�ܼ�����
	//�����£�ҽ��˵�ҵ�����û�������Բ��䣬���񾭳��������ң����ֵ�֢״����Ϊ�񾭵��󱨣���˿���ҩ����ֲ���񾭹��������Լ����ļ������еĽ���֢״��
	//�ɷѣ�ȡҩ��

	//������ģʽ������ �����ߣ��շ���Ա��ȡҩ��Ա��Ӫ��ʦ��������������������ߣ�Ԫ�أ���ҩƷ���е�����ҩƷ�� ������Ҫ��ɫ
	//���ʣ�a)���š�b)�鿴һ������

	/*_nmsp1::Medicine* pm1 = new _nmsp1::M_asplcrp();
	_nmsp1::Medicine* pm2 = new _nmsp1::M_fftdnhsp();
	_nmsp1::Medicine* pm3 = new _nmsp1::M_dlx();

	_nmsp1::MedicineProc mdcprocobj;
	mdcprocobj.AddMedicine(pm1);
	mdcprocobj.AddMedicine(pm2);
	mdcprocobj.AddMedicine(pm3);

	mdcprocobj.ProcAction("�շ���Ա");
	mdcprocobj.ProcAction("ȡҩ��Ա");

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
	cout << "����ҩƷ���ܼ�Ϊ: " << visitor_sf.GetTotalCost() << ",�շ���Ա��ȡ���ҵķ���!" << endl;

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
