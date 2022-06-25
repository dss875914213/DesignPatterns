#include<iostream>
#include<string>
#include "Fight.h"
#include "ItemStrategy.h"

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class M_Undead
	{
	public:
		void getInfo()
		{
			cout << "这是亡灵怪物" << endl;
		}
	};

	class M_Element
	{
	public:
		void getInfo()
		{
			cout << "这是元素怪物" << endl;
		}
	};

	class M_Mechanic
	{
	public:
		void getInfo()
		{
			cout << "这是机械怪物" << endl;
		}
	};

	class F_Warrior
	{
	public:
		void attackEnemyUndead(M_Undead* pobj)
		{
			pobj->getInfo();
		}

		void attackEnemyElement(M_Element* pobj)
		{
			pobj->getInfo();
		}

		void attackEnemyMechanic(M_Mechanic* pobj)
		{
			pobj->getInfo();
		}
	};
}

namespace _nmsp2
{
	class Monster
	{
	public:
		virtual ~Monster() {}
		virtual void GetInfo() = 0;
	};

	class M_Undead :public Monster
	{
	public:
		void GetInfo() override
		{
			cout << "这是亡灵怪物" << endl;
		}
	};

	class M_Element :public Monster
	{
	public:
		void GetInfo() override
		{
			cout << "这是元素怪物" << endl;
		}
	};

	class M_Mechanic :public Monster
	{
	public:
		void GetInfo() override
		{
			cout << "这是机械怪物" << endl;
		}
	};

	class F_Warrior
	{
	public:
		void AttackEnemy(Monster* obj)
		{
			obj->GetInfo();
		}
	};
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第4章 策略（Strategy）模式
	//（1）一个具体实现范例的逐步重构
	//补血道具（药品）：
	  //a：补血丹：补充200点生命值
	  //b：大还丹：补充300点生命值
	  //c：守护丹：补充500点生命值
	//Fighter，F_Warrior，F_Mage
	//策略  设计模式的定义：定义一系列算法（策略类），将每个算法封装起来，让它们可以相互替换。换句话说，策略模式通常把一系列算法
	   // 封装到一系列具体策略类中来作为抽象策略类的子类，然后根据实际需要使用这些子类。
	//策略类中的三种角色
	//a)Context（环境类）：该类中维持着一个对抽象策略类的指针或引用。这里指Fighter类。
	//b)Stategy（抽象策略类）：定义所支持的算法的公共接口，是所有策略类的父类。这里指ItemStrategy类。
	//c)ConcreteStrategy（具体策略类）：抽象策略类的子类，实现抽象策略类中声明的接口。这里指ItemStrategy_BXD、ItemStrategy_DHD、ItemStrategy_SHD。
	//策略类的优点：
	//a)以扩展的方式支持对未来的变化，符合开闭原则。
	  //遇到大量不稳定的if条件分支 或者switch分支，就要优先考虑是否可以通过策略模式来解决。策略模式是if，switch条件分支的杀手。
	//b)算法可以被复用。
	//c)策略模式可以看成是类继承的一种替代方案。通过为环境类对象指定不同的策略，就可以改变环境类对象的行为。
	//策略类的缺点：
	//a)导致引入许多新策略类；
	//b)使用策略时，调用者（main主函数）必须熟知所有策略类的功能并根据实际需要自行决定使用哪个策略类。
	
	//（2）依赖倒置原则：Dependency Inversion Principle，简称DIP
	 //是面向独享设计的主要实现方法，同时 也是实现开闭原则的重要实现途径。
	//解释：高层组件不应该依赖于低层（具体实现类），两者都应该依赖于抽象层。
	//范例：工厂模式时，亡灵类M_Undead，元素类M_Element，机械类M_Mechanic。

	/*ItemStrategy* bxd = new ItemStrategy_BXD();
	ItemStrategy* dhd = new ItemStrategy_DHD();
	ItemStrategy* shd = new ItemStrategy_SHD();
	Fighter* warrior = new FWarrior(100,30,50);
	warrior->SetItemStrategy(bxd);
	warrior->UseItem();

	warrior->SetItemStrategy(dhd);
	warrior->UseItem();

	warrior->SetItemStrategy(shd);
	warrior->UseItem();

	delete warrior;
	delete shd;
	delete dhd;
	delete bxd;*/

	/*_nmsp1::M_Undead* undead = new _nmsp1::M_Undead();
	_nmsp1::M_Element* element = new _nmsp1::M_Element();
	_nmsp1::M_Mechanic* mechanic = new _nmsp1::M_Mechanic();

	_nmsp1::F_Warrior* warrior = new _nmsp1::F_Warrior();
	warrior->attackEnemyElement(element);
	warrior->attackEnemyMechanic(mechanic);
	warrior->attackEnemyUndead(undead);

	delete warrior;
	delete undead;
	delete element;
	delete mechanic;*/

	_nmsp2::Monster* undead = new _nmsp2::M_Undead();
	_nmsp2::Monster* element = new _nmsp2::M_Element();
	_nmsp2::Monster* mechanic = new _nmsp2::M_Mechanic();

	_nmsp2::F_Warrior* warrior = new _nmsp2::F_Warrior();
	warrior->AttackEnemy(undead);
	warrior->AttackEnemy(element);
	warrior->AttackEnemy(mechanic);

	delete warrior;
	delete undead;
	delete element;
	delete mechanic;
}
