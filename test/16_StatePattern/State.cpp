#include "State.h"

void ForenoonState::WriteProgram(Work* w)
{
	if (w->GetHour()<12)
	{
		cout << "��ǰʱ�䣺 " << w->GetHour() << "�� ���繤��������ٱ�" << endl;
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
		cout << "��ǰʱ�䣺 " << w->GetHour() << "�� ���ˣ��緹����������˯" << endl;
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
		cout << "��ǰʱ�䣺 " << w->GetHour() << "�� ����״̬��������Ŭ��" << endl;
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

			cout << "��ǰʱ�䣺 " << w->GetHour() << "�� �Ӱ࣬ƣ��֮��" << endl;
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
	cout << "��ǰʱ�䣺 " << w->GetHour() << "�� �°�ؼ�" << endl;
}

void RestState::WriteProgram(Work* w)
{
	cout << "��ǰʱ�䣺 " << w->GetHour() << "�� �°�ؼ�" << endl;
}
