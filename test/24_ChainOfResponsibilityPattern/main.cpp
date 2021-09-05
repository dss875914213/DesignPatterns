#include <iostream>
#include "Manager.h"
#include "Request.h"

using namespace std;
int main()
{
	Manager* jinli = new CommonManager("金利");
	Manager* zongjian = new Majordomo("纵剪");
	Manager* zhongjiangli = new GeneralManager("宗经理");
	jinli->SetSuperior(zongjian);
	zongjian->SetSuperior(zhongjiangli);


	Request* request = new Request();
	request->SetRequestType("加薪");
	request->SetRequestContent("小菜请求加薪");
	request->SetNumber(1000);

	jinli->RequestApplications(request);

	Request* request2 = new Request();
	request2->SetRequestType("请假");
	request2->SetRequestContent("小菜请假");
	request2->SetNumber(3);

	jinli->RequestApplications(request2);

}
