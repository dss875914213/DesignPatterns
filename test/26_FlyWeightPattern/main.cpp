#include <iostream>
#include "WebSite.h"
#include "WebSiteFactory.h"
#include "User.h"
using namespace std;
int main()
{
	WebSiteFactory* f = new WebSiteFactory();
	WebSite* fx = f->GetWebSiteCategory("产品展示");
	fx->Use(new User("小菜1"));

	WebSite* fy = f->GetWebSiteCategory("产品展示");
	fy->Use(new User("小菜2"));

	WebSite* fz = f->GetWebSiteCategory("产品展示");
	fz->Use(new User("小菜3"));

	WebSite* fl = f->GetWebSiteCategory("博客");
	fl->Use(new User("小菜4"));

	WebSite* fm = f->GetWebSiteCategory("博客");
	fm->Use(new User("小菜5"));

	WebSite* fn = f->GetWebSiteCategory("博客");
	fn->Use(new User("小菜6"));

	cout << "网站分类总数为: " << f->GetWebSiteCount() << endl;
}
