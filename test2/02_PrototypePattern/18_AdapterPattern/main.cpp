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
			cout << "�� LogAdapter::InitDB ������ LogToFile::InitFile()" << endl;
			m_pFile->InitFile();
		}

		void WriteToDB(const char* pContent) override
		{
			cout << "�� LogAdapter::WriteToDB ������ LogToFile::WriteToFile()" << endl;
			m_pFile->WriteToFile(pContent);
		}

		void ReadFromDB() override
		{
			cout << "�� LogAdapter::ReadFromDB() ������ LogToFile::ReadFromFile()" << endl;
			m_pFile->ReadFromFile();
		}

		void CloseDB() override
		{
			cout << "�� LogAdapter::CloseDB() ������ LogToFile::CloseFile()" << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��15�� ��������Adapter��ģʽ���ṹ��ģʽ
	//��1��һ���򵥵ķ���
	//��һ�죬�������/��������
	//a)�����ϵ絼�����ݿ��е����ݷ��������޷���ȷ��д��������������⵽�ƻ��������ݿ��޷��ɹ����ӡ�
	//b)Ҫ������ʹ��LogToFile�������ɵ���־�ļ��ж�ȡһЩ��־��Ϣ��
	//��Լ���أ�
	//a)LogToFile��ʵ��Դ��ܸ���,Ǩ�ƹ��ܵ�LogToDatabase����Ҫ�ܾ�ʱ�䣬Ӱ��ҵ��
	//b)LogToFile���ṩ����Ŀʹ�á�Դ���ò�����ֻ��ʹ�ã������޸ģ���
	//��һ�ֽӿڵĵ���ת���ɶ�����һ�ֽӿڵĵ��ã�˵����
	//a)����ת���Ŀ���
	//b)ת���ܿ��ܲ���һ��һ������һ�Զࡣ����ת�������ܸ���

	//��2��������������Adapter��ģʽ
	//���壨ʵ����ͼ������һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ���ģʽʹ��ԭ���ӿڲ����ݶ�����һ�����������һ������
	  //������ģʽ ���� ��װ����Wrapper��
	//���ֽ�ɫ��
	//a)Target(Ŀ������ࣩ��LogToDatabase��
	//b)Adaptee���������ࣩ��LogToFile ��
	//c)Adapter���������ࣩ��LogAdapter�ࡣ

	//������ģʽ-װ��ģʽ��


	//��3����������
	//a)����������(LogToAdapter��)  b)��������

	//��4��������ģʽ����չ����
	//c++��׼��:�������������㷨��������������������������������һ�����еĶ��������ʵ�����������ӻ��߼���һ�㶫���ͳ�Ϊ��һ����������
	//������������deque��stack,queue
	//�㷨��������std::bind(����)
	//��������������reverse_iterator�����������������iterator��һ��򵥷�װ��
	/*_nmsp1::LogToFile* plog = new _nmsp1::LogToFile();
	plog->InitFile();
	plog->WriteToFile("����־�ļ���д��һ����־");
	plog->ReadFromFile();
	plog->CloseFile();
	delete plog;

	_nmsp1::LogToDataBase* plogDB = new _nmsp1::LogToDataBase();
	plogDB->InitDB();
	plogDB->WriteToDB("�����ݿ�д��һ����־");
	plogDB->ReadFromDB();
	plogDB->CloseDB();
	delete plogDB;*/

	_nmsp1::LogToFile* plog2 = new _nmsp1::LogToFile();
	_nmsp1::LogToDataBase* plogdb2 = new _nmsp1::LogAdapter(plog2);
	plogdb2->InitDB();
	plogdb2->WriteToDB("�����ݿ���д��һ�����ʣ�ʵ��������־�ļ�д��һ����־");
	plogdb2->ReadFromDB();
	plogdb2->CloseDB();
	delete plogdb2;
	delete plog2;
}
