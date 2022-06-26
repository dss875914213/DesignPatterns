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
	template<typename T>
	class MyIter
	{
	public:
		virtual void First() = 0; // ָ�������е�һ��Ԫ��
		virtual void Next() = 0;	// ָ����һ��Ԫ��
		virtual bool IsDone() = 0;	// �Ƿ������
		virtual T& CurrentItem() = 0;	// ��ȡ��ǰ��Ԫ��
		virtual ~MyIter() {}	//	������ʱ��������Ӧ��Ϊ�麯��
	};

	template<typename T>
	class MyContainter
	{
	public:
		virtual MyIter<T>* CreateIterator() = 0;	// ����������
		virtual T& GetItem(int index) = 0;		// ��ȡ��ǰԪ��
		virtual int GetSize() = 0;			// ����Ԫ������
		virtual ~MyContainter() {}
	};

	template<typename T>
	class MyVectorIter :public MyIter<T>
	{
	public:
		MyVectorIter(MyContainter<T>* tmpc)
			:m_myvector(tmpc),
			m_current(0)
		{
		}
		void First() override
		{
			m_current = 0;
		}

		void Next() override
		{
			m_current++;
		}

		bool IsDone() override
		{
			if (m_current >= m_myvector->GetSize())
				return true;
			return false;
		}

		T& CurrentItem()
		{
			return m_myvector->GetItem(m_current);
		}


	private:
		MyContainter<T>* m_myvector;
		int m_current;
	};

	template<typename T>
	class MyVector :public MyContainter<T>
	{
	public:
		MyVector()
		{
			for (int i = 0; i < 10; i++)
			{
				m_elem[i] = i;
			}
		}

		MyIter<T>* CreateIterator() override
		{
			return new MyVectorIter<T>(this);
		}

		T& GetItem(int index) override
		{
			return m_elem[index];
		}

		int GetSize() override
		{
			return 10;
		}

	private:
		T m_elem[10];
	};
}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��10�� ��������Iterator��ģʽ����Ϊ��ģʽ
	//��1�������͵������ļ򵥷���: vector��list
	//������ģʽ��ʽ������ƺ���д������ ��
	//������������ʵ��Ϊһ����ģ�塣

	//��2����һְ��ԭ��(Single Responsibility Principle�����SRP)
	//��2.1����һְ��ԭ��Ķ��壺һ����Ӧ��ֻ��һ������仯��ԭ��ͨ�׵�˵����һ�����ְ��Ӧ�õ�һ��Ӧ��ֻ��һ��������߶���ֻ�ṩһ�ֹ��ܡ�
	//��2.2���ھ������
	//�ھ��ԣ����ں���һ��ģ�飨�ࣩ���ܵĴﵽ��һĿ�����ԣ�ָ���Ǵӹ��ܽǶ�������ģ���ڵ���ϵ��ģ��ֻ֧��һ�鹦�ܡ������ھۡ�
	  //���֧��һ�鲻��صĹ��ܡ������ھۡ�
	//����ԣ�ģ��֮���໥�����ĳ̶ȡ�ȡ�������߼�Ľӿڵĸ��ӳ̶ȣ��໥��ĵ��÷�ʽ�Լ�����ʱ��Щ��Ϣ��Ҫ������
	//����Լ������ͣ��Ӹߵ��ͣ��� 
	   //a)������ϣ���ϳ̶���ߣ�Ӧ�ñ���ʹ��
	   //b)������ϣ�
	   //c)�ⲿ��ϣ�
	   //d)������ϣ�
	   //e)�����ϣ�
	   //f)������ϣ���ϳ̶���� 
	//����ʹ��������ϣ����ÿ�����ϣ����ƹ�����ϵķ�Χ����������ʹ��������ϡ�
	//������ƣ����ھ� �����
	//һ�����ְ��Խ��һ���ھ۶Ⱦ�Խ�ߣ���Ҫ�ﵽ����ϵ�Ŀ�ģ�ҲҪ������ѭ��������ԭ�򡪡��߲�����͵ײ�����������ڳ�������˵����ʹ�ó�����������������ϡ�

	//��3��������ģʽ�ķ������ִ�C++�еĵ�����
	//��3.1��������ģʽ����
	//���������ģʽ�Ķ��壺�ṩһ�ַ���˳�����һ���ۺ϶����������и���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��ʵ�ִ��룩��
	//4�ֽ�ɫ��
	//a)Iterator(�������������MyIter��ģ�塣
	//b)ConcreteIterator(�������������MyVector��ģ�塣
	//c)Aggregate������ۺϣ���MyContainer��ģ�塣
	//d)ConcreteAggregate(����ۺ�)��MyVector��ģ�塣
	//��3.2���ִ�C++�еĵ�����

	_nmsp1::MyContainter<int>* vec = new _nmsp1::MyVector<int>();
	_nmsp1::MyIter<int>* iter = new _nmsp1::MyVectorIter<int>(vec);
	for (iter->First(); !iter->IsDone(); iter->Next())
	{
		cout << iter->CurrentItem() << endl;
	}
	delete iter;
	delete vec;
}
