#include <iostream>
#include "WebSite.h"
#include "WebSiteFactory.h"
#include "User.h"
using namespace std;
int main()
{
	WebSiteFactory* f = new WebSiteFactory();
	WebSite* fx = f->GetWebSiteCategory("��Ʒչʾ");
	fx->Use(new User("С��1"));

	WebSite* fy = f->GetWebSiteCategory("��Ʒչʾ");
	fy->Use(new User("С��2"));

	WebSite* fz = f->GetWebSiteCategory("��Ʒչʾ");
	fz->Use(new User("С��3"));

	WebSite* fl = f->GetWebSiteCategory("����");
	fl->Use(new User("С��4"));

	WebSite* fm = f->GetWebSiteCategory("����");
	fm->Use(new User("С��5"));

	WebSite* fn = f->GetWebSiteCategory("����");
	fn->Use(new User("С��6"));

	cout << "��վ��������Ϊ: " << f->GetWebSiteCount() << endl;
}
