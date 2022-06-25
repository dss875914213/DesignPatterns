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
		Monster(int life, int magic, int attack) 
			:m_life(life),
			m_magic(magic),
			m_attack(attack)
		{
		}
		virtual ~Monster() {};
		virtual Monster* Clone() = 0;

	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class M_Undead :public Monster
	{
	public:
		M_Undead(int life, int magic, int attack)
			:Monster(life, magic, attack)
		{

		}

		M_Undead(const M_Undead& tmpobj) :Monster(tmpobj)
		{
			cout << "调用亡灵拷贝构造函数创建了一只亡灵" << endl;
		}

		Monster* Clone()
		{
			return new M_Undead(*this);
		}
	};

	class M_Element :public Monster
	{
	public:
		M_Element(int life, int magic, int attack)
			:Monster(life, magic, attack)
		{

		}

		M_Element(const M_Element& tmpobj) :Monster(tmpobj)
		{
			cout << "调用元素拷贝构造函数创建了一只元素" << endl;
		}

		Monster* Clone()
		{
			return new M_Element(*this);
		}
	};

	class M_Mechanic :public Monster
	{
	public:
		M_Mechanic(int life, int magic, int attack)
			:Monster(life, magic, attack)
		{

		}

		M_Mechanic(const M_Mechanic& tmpobj) :Monster(tmpobj)
		{
			cout << "调用机械拷贝构造函数创建了一只机械" << endl;
		}

		Monster* Clone()
		{
			return new M_Mechanic(*this);
		}
	};

}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	
	//第二节  原型（Prototype）模式
		//原型模式：通过一个对象（原型对象）克隆出多个一模一样的对象。
	//（1）通过工厂方法模式演变到原型模式
	  //克隆对象自身实际上是需要调用类的拷贝构造函数。《C++新经典：对象模型》:深拷贝，浅拷贝
	  //克隆对象意味着复制出一个全新的对象，所以设计到深浅拷贝时都要实现深拷贝
	//（2）引入原型（Prototype）模式
	//定义：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。简单说来就是通过克隆来创建新的对象实例。
	//原型模式的两种角色：
	//a)Prototype（抽象原型类）：Monster类。
	//b)ConcretePrototype（具体原型类）：M_Undead、M_Element、M_Mechanic类。
	//如果对象内部数据比较复杂多变并且在创建对象的时候希望保持对象的当前状态，那么用原型模式显然比用工厂方法模式更合适。

	//工厂方法模式和原型模式在创建对象时的异同点：
	//a)都不需要程序员知道所创建对象所属的类名。
	//b)工厂方法模式中的createMonster仍旧属于根据类名来生成新对象。
	//c)原型模式中的clone是根据现有对象来生成新对象。
	//可以把原型模式看成是一种特殊的工厂方法模式。

	//原型模式优缺点：
	//a)如果创建的新对象内部数据比较复杂且多变，原型模式创建对象的效率可能会高很多。
	//b)原型模式不存在额外的等级结构——原型模式不需要额外的工厂类。
	//c)clone接口的实现方法有多种。
	//d)有些情况下，产品类中存在一个克隆方法也会给开发提供一些明显便利。
	
	_nmsp1::Monster* undead = new _nmsp1::M_Undead(200, 40, 50);
	_nmsp1::Monster* undead2 = undead->Clone();
	_nmsp1::Monster* element = new _nmsp1::M_Element(200, 40, 50);
	_nmsp1::Monster* element2 = element->Clone();
	_nmsp1::Monster* mechanic = new _nmsp1::M_Mechanic(200, 40, 50);
	_nmsp1::Monster* mechanic2 = mechanic->Clone();

	delete undead;
	delete undead2;
	delete element;
	delete element2;
	delete mechanic;
	delete mechanic2;
}
