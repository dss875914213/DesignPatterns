#include <iostream>
#include "Manager.h"
#include "Request.h"

using namespace std;
int main()
{
	Manager* jinli = new CommonManager("����");
	Manager* zongjian = new Majordomo("�ݼ�");
	Manager* zhongjiangli = new GeneralManager("�ھ���");
	jinli->SetSuperior(zongjian);
	zongjian->SetSuperior(zhongjiangli);


	Request* request = new Request();
	request->SetRequestType("��н");
	request->SetRequestContent("С�������н");
	request->SetNumber(1000);

	jinli->RequestApplications(request);

	Request* request2 = new Request();
	request2->SetRequestType("���");
	request2->SetRequestContent("С�����");
	request2->SetNumber(3);

	jinli->RequestApplications(request2);

}
