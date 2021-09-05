#include "State.h"

void ForenoonState::WriteProgram(Work* w)
{
	if (w->GetHour()<12)
	{
		cout << "当前时间： " << w->GetHour() << "点 上午工作，精神百倍" << endl;
	}
	else
	{
		w->SetState(new NoonState());
		w->WriteProgram();
	}
}

void NoonState::WriteProgram(Work* w)
{
	if (w->GetHour() < 13)
	{
		cout << "当前时间： " << w->GetHour() << "点 饿了，午饭；犯困，午睡" << endl;
	}
	else
	{
		w->SetState(new AfternoonState());
		w->WriteProgram();
	}
}

void AfternoonState::WriteProgram(Work* w)
{
	if (w->GetHour() < 17)
	{
		cout << "当前时间： " << w->GetHour() << "点 下午状态不错，继续努力" << endl;
	}
	else
	{
		w->SetState(new EveningState());
		w->WriteProgram();
	}
}

void EveningState::WriteProgram(Work* w)
{
	if (w->GetWorkFinished())
	{
		w->SetState(new RestState());
		w->WriteProgram();
	}
	else
	{
		if (w->GetHour() < 21)
		{

			cout << "当前时间： " << w->GetHour() << "点 加班，疲惫之极" << endl;
		}
		else
		{
			w->SetState(new SleepingState());
			w->WriteProgram();
		}
	}
}

void SleepingState::WriteProgram(Work* w)
{
	cout << "当前时间： " << w->GetHour() << "点 下班回家" << endl;
}

void RestState::WriteProgram(Work* w)
{
	cout << "当前时间： " << w->GetHour() << "点 下班回家" << endl;
}
