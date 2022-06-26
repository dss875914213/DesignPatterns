#include<iostream>
#include<string>
#include <vector>
#include <fstream>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
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
			cout << "���� WebAddr_Shopping������վ" << endl;
		}
	};

	class WebAddrVideo :public WebAddr
	{
	public:
		void Visit() override
		{
			cout << "���� WebAddr_Video������վ" << endl;
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
				cout << "�ļ���ʧ��" << endl;
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
				cout << "���ļ��ж�ȡ��������--------" << endl;
				ReadInfoFromFile* rf = new ReadInfoFromFile();
				rf->Read();
				delete rf;
			}
			else
			{
				cout << "�ӻ����ж�ȡ��������--------" << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��14�� ����Proxy��ģʽ���ṹ��ģʽ
	//Ŀ�ģ�Ϊ�ͻ������Ӷ���Ĺ��ܡ�Լ������Կͻ��˵ĵ�������һЩ���ӵ�ϸ�����⡣
	//��1����������ͷ���
	//ͨ�������������Ϊԭʼ�ࣨ�������ࣩ���Ӷ�������������¹��ܡ��·���Լ���������ơ�
	//ʹ�ô�����ĳ���Ա�뿪�����������ĳ���Ա������ͬһ������Ա����������������ͬ��˾�ĳ���Ա��

	//��2���������Proxy��ģʽ��
	//���壨ʵ����ͼ����Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�
	//���ֽ�ɫ��
	//a)Subject���������⣩��WebAddr�ࡣ
	//b)Proxy���������⣩��WebAddr_Shopping_Proxy�ࡣ
	//c)RealSubject����ʵ���⣩��WebAddr_Shopping

	//����ģʽ��װ��ģʽ�Աȣ�
	//����ģʽ��������ʵ���Ⲣ����ʵ��������һЩ�������������Σ���Щ��������ʵ����Ҫʵ�ֵĹ��ܿ���û������ԣ���Ҫ�ǿ��ƶ���ʵ����ķ��ʡ�
	//װ��ģʽ���¹�����ԭ�й���������������ԣ��Ƕ�ԭ�й�������������Ϊ����չ����ǿ����

	//��3������ģʽ��Ӧ�ó���̽��
	//�� 3.1 ������ģʽ����Ӧ�ó���
	//�����Ĵ��������������������Щ���ͣ�
	//a)Զ�̴���Remote Proxy��
	//b)�������Virtual Proxy)
	//c)��������Protect Proxy��
	//d)����/�������Cache Proxy��
	//e)�������ô���Smart Reference Proxy����shared_ptr
	//f)дʱ���ƣ�copy-on-write)�Ż�����string
	//g)����ǽ����ͬ�������������ش���ȡ�

	//�� 3.2 ������ / �������Cache Proxy��һ��

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
