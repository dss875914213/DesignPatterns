#include "Action.h"
#include <string>
#include <iostream>
using namespace std;
void Success::GetManConclusion(Man* concreteElementA)
{
	cout << typeid(concreteElementA).name()<<" "<<typeid(this).name()<<"ʱ����������һ��ΰ���Ů�ˡ�" << endl;
}

void Success::GetWomanConclusion(Woman* concreateElementB)
{
	cout << typeid(concreateElementB).name() << " " << typeid(this).name() << "ʱ����������һ�����ɹ������ˡ�" << endl;
}

void Failing::GetManConclusion(Man* concreteElementA)
{
	cout << typeid(concreteElementA).name() << " " << typeid(this).name() << "ʱ����ͷ�Ⱦƣ�˭Ҳ����Ȱ��" << endl;
}

void Failing::GetWomanConclusion(Woman* concreateElementB)
{
	cout << typeid(concreateElementB).name() << " " << typeid(this).name() << "ʱ������������˭ҲȰ���ˡ�" << endl;
}

void Amativeness::GetManConclusion(Man* concreteElementA)
{
	cout << typeid(concreteElementA).name() << " " << typeid(this).name() << "ʱ�����²���ҲҪװ����" << endl;
}

void Amativeness::GetWomanConclusion(Woman* concreateElementB)
{
	cout << typeid(concreateElementB).name() << " " << typeid(this).name() << "ʱ�����¶�ҲҪװ��������" << endl;
}
