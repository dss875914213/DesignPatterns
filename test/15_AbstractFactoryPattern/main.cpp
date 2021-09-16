#include <iostream>
#include "User.h"
#include "SqlServerUser.h"

using namespace std;
int main()
{
	User* user = new User();
	Department* dept = new Department();

	IFactory* factory = new AccessFactory();

	IUser* iu = factory->CreateUser();
	iu->Insert(user);
	iu->GetUser(1);
	
	IDepartment* id = factory->CreateDepartment();
	id->Insert(dept);
	id->GetDepartment(1); 

}
