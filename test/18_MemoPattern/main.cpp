#include <iostream>
#include "GameRole.h"
#include "RoleStateCaretaker.h"
using namespace std;
int main()
{
	// ��սǰ
	GameRole* lixiaoyao = new GameRole();
	lixiaoyao->GetInitState();
	lixiaoyao->StateDisplay();

	// �������
	RoleStateCaretaker* stateAdmin = new RoleStateCaretaker();
	stateAdmin->SetMemonto(lixiaoyao->SaveState());

	// ��ս
	lixiaoyao->Fight();
	lixiaoyao->StateDisplay();

	// �ָ�֮ǰ״̬
	lixiaoyao->RecoveryState(stateAdmin->GetMemonto());
	lixiaoyao->StateDisplay();
}
