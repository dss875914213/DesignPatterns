#include <iostream>
#include "Company.h"
using namespace std;
int main()
{
	ConcreateCompany* root = new ConcreateCompany("�����ܹ�˾");
	root->Add(new HRDepartment("�ܹ�˾������Դ��"));
	root->Add(new FinanceDepartment("�ܹ�˾����"));

	ConcreateCompany* comp = new ConcreateCompany("�Ϻ������ֹ�˾");
	comp->Add(new HRDepartment("�����ֹ�˾������Դ��"));
	comp->Add(new FinanceDepartment("�����ֹ�˾����"));
	root->Add(comp);

	cout << "�ṹͼ" << endl;
	root->Display(1);

	cout << "ְ��" << endl;
	root->LineOfDuty();


}
