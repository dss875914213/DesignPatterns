#include <iostream>
#include "GameRole.h"
#include "RoleStateCaretaker.h"
using namespace std;
int main()
{
	// 大战前
	GameRole* lixiaoyao = new GameRole();
	lixiaoyao->GetInitState();
	lixiaoyao->StateDisplay();

	// 保存进度
	RoleStateCaretaker* stateAdmin = new RoleStateCaretaker();
	stateAdmin->SetMemonto(lixiaoyao->SaveState());

	// 大战
	lixiaoyao->Fight();
	lixiaoyao->StateDisplay();

	// 恢复之前状态
	lixiaoyao->RecoveryState(stateAdmin->GetMemonto());
	lixiaoyao->StateDisplay();
}
