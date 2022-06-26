#include<iostream>
#include<string>
#include "Monster.h"

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{

}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第12章 状态（State）模式：行为型，有限状态机
	//状态模式的突出特点：用类来表示状态——策略模式（用类来表示策略）
	//（1）一个基本的状态转换范例
	//有限状态机（Finite State Mache，所写：FSM），简称状态机。
	  //当某个事件（转移条件）发生时，会根据当前状态决定你执行哪种动作，然后进入下一种状态。
	//约定：怪物生命 500。
	  //a) 怪物血量 > 400 ，怪物->凶悍，反击
	  //b) 怪物血量 <= 400， > 100，怪物->不安，反击并呼唤附近其他怪物支援
	  //c) 怪物血量 <= 100，怪物->恐惧，逃跑
	  //d) 怪物血量 <= 0，怪物->死亡，不能再被主角攻击
	//状态类的存在价值：使业务逻辑代码更加清晰和易于维护。

	Monster monster(500);
	monster.Attacked(20);
	monster.Attacked(100);
	monster.Attacked(200);
	monster.Attacked(50);
	monster.Attacked(100);
	monster.Attacked(100);
}
