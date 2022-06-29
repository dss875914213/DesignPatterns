#include<iostream>
#include<string>
#include <map>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
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
				cout << "��ť\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
			else
				cout << "��ť\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
		}


		void Changed(map<string, CtlParent*>& tmpuicullist) override
		{
			if (m_caption == "��¼")
				cout << "��ʼ��Ϸ��¼��֤" << endl;
			else if (m_caption == "�˳�")
				cout << "��Ϸ�˳����ټ�!" << endl;
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
				cout << "��ѡ��ť\"" << m_caption << "\"��ѡ��" << endl;
			else
				cout << "��ѡ��ť\"" << m_caption << "\"��ȡ��ѡ��" << endl;
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
				cout << "�༭��\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
			else
				cout << "�༭��\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
		}

		bool IsContentEmpty()
		{
			return m_content.empty();
		}

		void Changed(map<string, CtlParent*>& tmpuicullist) override
		{
			if ((static_cast<EditCtl*>(tmpuicullist["�˺�"]))->IsContentEmpty()
				|| (static_cast<EditCtl*>(tmpuicullist["����"]))->IsContentEmpty())
				tmpuicullist["��¼"]->Enable(false);
			else
				tmpuicullist["��¼"]->Enable(true);
		}
	private:
		string m_content;
	};

	void RadioBtn::Changed(map<string, CtlParent*>& tmpuicullist)
	{
		if (m_caption == "�ο͵�¼")
		{
			(static_cast<RadioBtn*>(tmpuicullist["�ο͵�¼"]))->Selected(true);
			(static_cast<RadioBtn*>(tmpuicullist["�˺ŵ�¼"]))->Selected(false);

			tmpuicullist["�˺�"]->Enable(false);
			tmpuicullist["����"]->Enable(false);

			tmpuicullist["��¼"]->Enable(true);
		}
		else if (m_caption == "�˺ŵ�¼")
		{
			(static_cast<RadioBtn*>(tmpuicullist["�ο͵�¼"]))->Selected(false);
			(static_cast<RadioBtn*>(tmpuicullist["�˺ŵ�¼"]))->Selected(true);

			tmpuicullist["�˺�"]->Enable(true);
			tmpuicullist["����"]->Enable(true);

			if ((static_cast<EditCtl*>(tmpuicullist["�˺�"]))->IsContentEmpty()
				|| (static_cast<EditCtl*>(tmpuicullist["����"]))->IsContentEmpty())
			{
				tmpuicullist["��¼"]->Enable(false);
			}
			else
				tmpuicullist["��¼"]->Enable(true);
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
				cout << "��ť\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
			else
				cout << "��ť\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
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
				cout << "��ѡ��ť\"" << m_caption << "\"��ѡ��" << endl;
			else
				cout << "��ѡ��ť\"" << m_caption << "\"��ȡ��ѡ��" << endl;
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
				cout << "�༭��\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
			else
				cout << "�༭��\"" << m_caption << "\"������Ϊ��\"����\"״̬" << endl;
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
			m_pLogin = new Button(this, "��¼");
			m_pLogout = new Button(this, "�˳�");

			m_pRbtn1 = new RadioBtn(this, "�ο͵�¼");
			m_pRbtn2 = new RadioBtn(this, "�˺ŵ�¼");

			m_pEdtctl1 = new EditCtl(this, "�˺�");
			m_pEdtctl2 = new EditCtl(this, "����");

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
				cout << "��ʼ��Ϸ��¼��֤" << endl;
			else if (pCtrl == m_pLogout)
				cout << "��Ϸ�˳�" << endl;

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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��17�� �н��ߣ�Mediator��ģʽ����ͣ��ģʽ����Ϊ��ģʽ��
	//��1���н��ߵĻ�������
	//a)����ĸ�����ɲ���������
	//b)qq���죺����ѻ���İ���˵������죨˽�ģ������뵽һ��qqȺ�С�
	//c)�ɻ��İ�ȫ�����밲ȫ��½����̨

	//��2���н���ģʽ����������:�¼���������������бȽϹ㷺��Ӧ�ã������ǳ��������ڳ����UI���������
	//��3�������н��ߣ�Mediator��ģʽ
	//���壺��һ���н�����н��ߣ�����װһϵ�еĶ��󽻻����н���ʹ����������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ��
	  //���ҿ��Զ����ظı�����֮��Ľ�����
	//4�ֽ�ɫ
	//a)Mediator(�����н����ࣩ��Mediator�ࡣ
	//b)ConcreteMediator(�����н����ࣩ��concrMediator�ࡣ
	//c)Colleague(����ͬ����)��CtlParent�ࡣ
	//d)ConcreteColleague(����ͬ���ࣩ��Button,RadioBtn,EditCtrl�ࡣ
	//�н���ģʽһ������һ������Զ������õ����ӵķ�ʽ����ͨ�ŵĳ��ϣ����н��߸�����ƺ�Э��һ�����֮��Ľ�����
	//��ȱ�㣺
	//a)���д����ӵĶ���֮��Ĺ�ͨ�Ϳ��ƣ���������Զ��Ϊ1�Զࡣ
	//b)��ͬ�¶�����н��
	//c)�����ֿ����߼����붼���У�ת�ƣ������н�������ʵ�֡����ܻ��н������ʵ�ֱ�÷ǳ�������������ά����Ҫƽ��ý������ӶȺ�ʵ�ָ��Ӷȡ�
	//����н���ʵ�ֵ�̫���ӣ����ܻ������ʹ�ø�ģʽ��������������ĺô���

	//��ʲô����¿���ʹ���н���ģʽ��
	//a)����֮�����ù�ϵ���ڸ��ӣ�ĳ������仯�ᵼ�´�����������ı仯��
	//b)ĳ�������������������������ӣ�ͨ�ŴӶ���ɸö�����ѱ����á�
	//c)ϣ��������ࣨͬ���ࣩ�е���Ϊ��װ��һ���ࣨ�н����ࣩ����ʵ�֡�

	/*map<string, _nmsp1::CtlParent*> uictllist;
	uictllist["��¼"] = new _nmsp1::Button("��¼");
	uictllist["�˳�"] = new _nmsp1::Button("�˳�");

	uictllist["�ο͵�¼"] = new _nmsp1::RadioBtn("�ο͵�¼");
	uictllist["�˺ŵ�¼"] = new _nmsp1::RadioBtn("�˺ŵ�¼");

	uictllist["�˺�"] = new _nmsp1::EditCtl("�˺�");
	uictllist["����"] = new _nmsp1::EditCtl("����");

	(static_cast<_nmsp1::RadioBtn*>(uictllist["�ο͵�¼"]))->Selected(true);
	(static_cast<_nmsp1::RadioBtn*>(uictllist["�˺ŵ�¼"]))->Selected(false);

	uictllist["�˺�"]->Enable(false);
	uictllist["����"]->Enable(false);
	uictllist["��¼"]->Enable(true);
	uictllist["�˳�"]->Enable(true);

	cout << "------------" << endl;
	uictllist["�˺ŵ�¼"]->Changed(uictllist);

	for (auto iter = uictllist.begin(); iter != uictllist.end(); iter++)
	{
		delete iter->second;
		iter->second = nullptr;
	}*/

	_nmsp2::ConcreMediator mymedia;
	mymedia.CreateCtrl();
	mymedia.m_pRbtn2->Changed();
}
