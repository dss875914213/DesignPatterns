#include<iostream>
#include<string>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class Monster
	{
	public:
		Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {};	// 做父类时，析构函数为虚函数

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class M_Undead :public Monster
	{
	public:
		M_Undead(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "亡灵来到世界" << endl;
		}
		~M_Undead() {};
	};

	class M_Element :public Monster
	{
	public:
		M_Element(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "元素来到世界" << endl;
		}
		~M_Element() {};
	};

	class M_Mechanic :public Monster
	{
	public:
		M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "机械来到世界" << endl;
		}
		~M_Mechanic() {};
	};

	class MonsterFactory
	{
	public:
		Monster* CreateMonster(string name)
		{
			Monster* monster = NULL;
			if (name == "undead")
				monster = new M_Undead(2000, 300, 100);
			else if (name == "element")
				monster = new M_Element(4000, 100, 200);
			else if (name == "mechanic")
				monster = new M_Mechanic(3000, 200, 100);
			return monster;
		}
	};
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第三章 工厂模式、原型（Prototype）模式、建造者（Builder）模式
	//第一节  工厂模式:创建型模式
	//new，堆对象，可以实现多态。
	//工厂模式：通过把创建对象的代码包装起来，做到创建对象的代码与具体的业务逻辑代码相隔离的目的。
	//A *pobja = new A();
	//工厂模式细分：a)简单工厂模式；b)工厂方法模式；c)抽象工厂模式。
	//面向对象程序设计一个重要原则：开闭原则。

	//（1）简单工厂（Simple Factory）模式
	//策划：亡灵类怪物，元素类怪物，机械类怪物：都有生命值，魔法值，攻击力三个属性。
	//Monster作为父类，M_Undead（亡灵类），M_Element（元素类怪物），M_Mechanic（机械类怪物）。
	//使用new +具体类名来创建对象是一种 依赖具体类型的紧耦合关系。
	//简单工厂模式的实现思路：使用工厂类可以实现创建怪物的代码  与  各个 具体怪物类对象要实现的逻辑代码隔离。
	//封装变化：把依赖范围尽可能缩小，把容易变化的代码段限制在一个小范围内，就可以在很大程度上提高代码的可维护性和可扩展性。
	//通过增加新的if else分支来达到支持新怪物增加的目的——违背了面向对象程序设计的原则：开闭原则（Open Close Principle :OCP）；
	//开闭原则：说的是代码扩展性问题——对扩展开放，对修改关闭（封闭）；
	//开闭原则详细的解释：当增加新功能，不应该通过修改已经存在的代码来进行，而是应该通过扩展代码(比如增加新类，增加新成员函数）来进行。
	//如果if,else分支不多（没有数十上百个），则适当违反开闭原则，是完全可以接受的。
	//大家要在代码的可读性和可扩展ing之间做出权衡。
	//引入“简单工厂”设计模式的定义（实现意图）：定义一个工厂类(MonsterFactory)，该类的成员函数(createMonster)可以根据不同参数
	  //创建并返回不同的类对象，被创建的对象所属的类（M_Undead，M_Element，M_Mechanic）一般都具有相同的父类（Monster），
	  //调用者（这里指main函数）无需关心创建对象的细节。
	//简单工厂方法模式：实现了创建怪物类代码（createMonster），与具体怪物类（M_Undead，M_Element，M_Mechanic）解耦合的效果。
	
	/*_nmsp1::Monster* undead = new _nmsp1::M_Undead(2000, 300, 100);
	_nmsp1::Monster* element = new _nmsp1::M_Element(4000, 100, 200);
	_nmsp1::Monster* mechanic = new _nmsp1::M_Mechanic(3000, 200, 100);

	delete undead;
	delete element;
	delete mechanic;*/

	_nmsp1::MonsterFactory* factory = new _nmsp1::MonsterFactory();
	_nmsp1::Monster *undead = factory->CreateMonster("undead");
	_nmsp1::Monster *element = factory->CreateMonster("element");
	_nmsp1::Monster *mechanic = factory->CreateMonster("mechanic");

	delete undead;
	delete element;
	delete mechanic;
	delete factory;
}
