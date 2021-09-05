#include <iostream>
#include "Company.h"
using namespace std;
int main()
{
	ConcreateCompany* root = new ConcreateCompany("北京总公司");
	root->Add(new HRDepartment("总公司人力资源部"));
	root->Add(new FinanceDepartment("总公司财务部"));

	ConcreateCompany* comp = new ConcreateCompany("上海华东分公司");
	comp->Add(new HRDepartment("华东分公司人力资源部"));
	comp->Add(new FinanceDepartment("华东分公司财务部"));
	root->Add(comp);

	cout << "结构图" << endl;
	root->Display(1);

	cout << "职责" << endl;
	root->LineOfDuty();


}
