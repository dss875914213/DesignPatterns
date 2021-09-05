#include <iostream>
#include <string>
#include "Work.h"
using namespace std;


int main()
{
	Work* work = new Work();
	work->SetHour(9);
	work->WriteProgram();

	work->SetHour(10);
	work->WriteProgram();


	work->SetHour(14);
	work->WriteProgram();

	work->SetHour(17);
	work->SetWorkFinished(true);
	work->WriteProgram();


	work->SetHour(19);
	work->WriteProgram();

}
