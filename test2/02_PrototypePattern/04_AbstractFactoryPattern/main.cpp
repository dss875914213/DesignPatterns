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

	class M_Undead_Swamp :public Monster
	{
	public:
		M_Undead_Swamp(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "沼泽亡灵来到世界" << endl;
		}
		~M_Undead_Swamp() {};
	};

	class M_Element_Swamp :public Monster
	{
	public:
		M_Element_Swamp(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "沼泽元素来到世界" << endl;
		}
		~M_Element_Swamp() {};
	};

	class M_Mechanic_Swamp :public Monster
	{
	public:
		M_Mechanic_Swamp(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "沼泽机械来到世界" << endl;
		}
		~M_Mechanic_Swamp() {};
	};

	class M_Undead_Mountain :public Monster
	{
	public:
		M_Undead_Mountain(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "山地亡灵来到世界" << endl;
		}
		~M_Undead_Mountain() {};
	};

	class M_Element_Mountain :public Monster
	{
	public:
		M_Element_Mountain(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "山地元素来到世界" << endl;
		}
		~M_Element_Mountain() {};
	};

	class M_Mechanic_Mountain :public Monster
	{
	public:
		M_Mechanic_Mountain(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "山地机械来到世界" << endl;
		}
		~M_Mechanic_Mountain() {};
	};

	class M_Undead_Town :public Monster
	{
	public:
		M_Undead_Town(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "城市亡灵来到世界" << endl;
		}
		~M_Undead_Town() {};
	};

	class M_Element_Town :public Monster
	{
	public:
		M_Element_Town(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "城市元素来到世界" << endl;
		}
		~M_Element_Town() {};
	};

	class M_Mechanic_Town :public Monster
	{
	public:
		M_Mechanic_Town(int life, int magic, int attack) : Monster(life, magic, attack)
		{
			cout << "城市机械来到世界" << endl;
		}
		~M_Mechanic_Town() {};
	};

	class M_ParFactory
	{
	public:
		M_ParFactory()
		{

		}
		virtual ~M_ParFactory() {}
		virtual Monster* CreateMonster_Undead() = 0;
		virtual Monster* CreateMonster_Element() = 0;
		virtual Monster* CreateMonster_Mechanic() = 0;
	private:
		int m_life;
		int m_magic;
		int m_attack;
	};

	class M_Factory_Swamp :public M_ParFactory
	{
	public:
		Monster* CreateMonster_Undead() override
		{
			return new M_Undead_Swamp(100, 20, 4);
		}
		Monster* CreateMonster_Element() override
		{
			return new M_Element_Swamp(100, 20, 5);
		}
		Monster* CreateMonster_Mechanic() override
		{
			return new M_Mechanic_Swamp(100, 20, 6);
		}
	};

	class M_Factory_Mountain :public M_ParFactory
	{
	public:
		Monster* CreateMonster_Undead() override
		{
			return new M_Undead_Mountain(100, 20, 4);
		}
		Monster* CreateMonster_Element() override
		{
			return new M_Element_Mountain(100, 20, 5);
		}
		Monster* CreateMonster_Mechanic() override
		{
			return new M_Mechanic_Mountain(100, 20, 6);
		}
	};

	class M_Factory_Town :public M_ParFactory
	{
	public:
		Monster* CreateMonster_Undead() override
		{
			return new M_Undead_Town(100, 20, 4);
		}
		Monster* CreateMonster_Element() override
		{
			return new M_Element_Town(100, 20, 5);
		}
		Monster* CreateMonster_Mechanic() override
		{
			return new M_Mechanic_Town(100, 20, 6);
		}
	};

}

namespace _nmsp2
{
	class Body
	{
	public:
		virtual ~Body() {};
		virtual void GetName() = 0;
	};

	class Shoes
	{
	public:
		virtual ~Shoes() {};
		virtual void GetName() = 0;
	};

	class Clothes
	{
	public:
		virtual ~Clothes() {};
		virtual void GetName() = 0;
	};

	class ChinaBody :public Body
	{
	public:
		void GetName() override
		{
			cout << "来自中国的身体" << endl;
		}
	};

	class JapanBody :public Body
	{
	public:
		void GetName() override
		{
			cout << "来自日本的身体" << endl;
		}
	};

	class AmericaBody :public Body
	{
	public:
		void GetName() override
		{
			cout << "来自美国的身体" << endl;
		}
	};

	class ChinaShoes :public Shoes
	{
	public:
		void GetName() override
		{
			cout << "来自中国的鞋子" << endl;
		}
	};

	class JapanShoes :public Shoes
	{
	public:
		void GetName() override
		{
			cout << "来自日本的鞋子" << endl;
		}
	};

	class AmericaShoes :public Shoes
	{
	public:
		void GetName() override
		{
			cout << "来自美国的鞋子" << endl;
		}
	};

	class ChinaClothes :public Clothes
	{
	public:
		void GetName() override
		{
			cout << "来自中国的衣服" << endl;
		}
	};

	class JapanClothes :public Clothes
	{
	public:
		void GetName() override
		{
			cout << "来自日本的衣服" << endl;
		}
	};

	class AmericaClothes :public Clothes
	{
	public:
		void GetName() override
		{
			cout << "来自美国的衣服" << endl;
		}
	};

	class AbstractFactory
	{
	public:
		virtual ~AbstractFactory() {}
		virtual Body* CreateBody() = 0;
		virtual Shoes* CreateShoes() = 0;
		virtual Clothes* CreateClothes() = 0;
	};

	class ChinaFactory :public AbstractFactory
	{
	public:
		Body* CreateBody() override
		{
			return new ChinaBody();
		}

		Shoes* CreateShoes() override
		{
			return new ChinaShoes();
		}

		Clothes* CreateClothes() override
		{
			return new ChinaClothes();
		}
	};

	class JapanFactory :public AbstractFactory
	{
	public:
		Body* CreateBody() override
		{
			return new JapanBody();
		}

		Shoes* CreateShoes() override
		{
			return new JapanShoes();
		}

		Clothes* CreateClothes() override
		{
			return new JapanClothes();
		}
	};

	class AmericaFactory :public AbstractFactory
	{
	public:
		Body* CreateBody() override
		{
			return new AmericaBody();
		}

		Shoes* CreateShoes() override
		{
			return new AmericaShoes();
		}

		Clothes* CreateClothes() override
		{
			return new AmericaClothes();
		}
	};

	class BarbieDoll
	{
	public:
		BarbieDoll(Body* body, Shoes* shoes, Clothes* clothes)
			:m_body(body),
			m_shoes(shoes),
			m_clothes(clothes)
		{

		}

		void Assemble()
		{
			cout << "成功组装娃娃" << endl;
			m_body->GetName();
			m_shoes->GetName();
			m_clothes->GetName();
		}

	private:
		Shoes* m_shoes;
		Clothes* m_clothes;
		Body* m_body;
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

	//（2）工厂方法（Factory Method）模式:简称工厂模式或者多态工厂模式。
	//与简单工厂模式比，灵活性更强，实现也更加复杂，引入更多的新类。
	//M_UndeadFactory，M_ElementFactory，M_MechanicFactory类，有一个共同的父类M_ParFactory（工厂抽象类）:
	  //符合开闭原则，付出的代价是需要新增加多个新的工厂类。
	//定义（实现意图）：定义一个用于创建对象的接口（M_ParFactory类中的createMonster成员函数，这其实就是个工厂方法，工厂方法模式的名字也是由此而来）,
	  //但由子类（M_UndeadFactory、M_ElementFactory、M_MechanicFactory）决定要实例化的类是哪一个。
	  //该模式使得某个类（M_Undead、M_Element、M_Mechanic）的实例化延迟到子类（M_UndeadFactory、M_ElementFactory、M_MechanicFactory）。
	//出现新怪物类型：M_Beast（野兽类）。
	//一般可以认为，将简单工厂模式的代码经过把工厂类进行抽象改造成符合开闭原则后的代码，就变成了工厂方法模式的代码。

	//把用new创建对象集中到某个或者某些工厂类的成员函数中去做，的好处：
	//a)封装变化。 prtnobj = new M_Element(200,80,100); ->new M_Element(200,80,100,300);
	//b)创建对象前需要一些额外的业务代码，可以将这些代码增加到具体的工厂类的createMonster成员函数中。

	//简单工厂模式把创建对象这件事放到了一个统一的地方来处理，弹性比较差。而工厂方法模式相当于建立了一个程序实现框架，从而让子类来决定对象如何创建。
	//工厂方法模式往往需要创建一个与产品等级结构（层次）相同的工厂等级结构，这也增加了新类的层次结构和数目。

	//（3）抽象工厂（Abstract Factory）模式
	//（3.1）战斗场景分类范例
	//怪物分类：亡灵类，元素类，机械类
	//战斗场景分类：沼泽地区，山脉地区，城镇。
	//9类怪物====>沼泽地亡灵类、元素类、机械类，山脉地区亡灵类、元素类、机械类，城镇中的亡灵类、元素类、机械类
	//工厂方法模式：一个工厂创建一种类怪物。
	//但如果一个工厂子类能够创建不止一种而是多种具有相同规则的怪物对象，那么就可以有效的减少所创建的工厂子类数量，这就是抽象工厂模式的核心思想。

	//两个概念：a)产品等级结构   b)产品族
	//抽象工厂模式是按照产品族来生产产品（产地相同的用一个工厂来生产）——一个地点有一个工厂，该工厂负责生产本产地的所有产品。

	//抽象工厂模式优缺点：
	//a)增加森林类新场景，怪物种类不变。则只需要增加一个新子工厂比如M_Factory_Forest，符合开闭原则。
	//b)增加新怪物种类比如龙类，不但要增加三个继承自Monster的子类，还要针对M_ParFactory增加新的虚函数接口比如createMonster_Dragon，
	   //同时各个子工厂类都需要实现createMonster_Dragon，这种修改代码的方式来增加新怪物种类，不符合开闭原则，所以增加新怪物的情形不适合抽象工厂模式。
	//c)只增加一个产品族则符合开闭原则，只需要增加新工厂子类，这是该模式的优点。
		  //但若增加新产品等级结构，需要修改抽象层代码，这是抽象工厂模式的缺点，所以，应避免在产品等级结构不稳定的情况下使用该模式。
		  //也就是说，如果游戏中怪物种类（亡灵类，元素类，机械类）比较固定的情况下，更适合使用抽象工厂模式。
	
	//（3.2） 不同厂商生产不同部件范例
	//芭比娃娃：身体（包括头、颈部、躯干、四肢）、衣服、鞋子
	//中国，日本，美国 厂商
	//要求：制作两个芭比娃娃，第一个：身体，衣服，鞋子，全部采用中国厂商制造的部件。
							//第二个：身体采用中国厂商，衣服部件采用日本厂商，鞋子部件采用美国厂商。
	//类的设计思路：
	//a)将身体，衣服，鞋子 这三个部件实现为抽象类。
	//b)实现一个抽象工厂，分别用来生产身体、衣服、鞋子这三个部件。
	//c)针对不同厂商的每个部件实现具体的类以及每个厂商所代表的具体工厂。

	//工厂方法模式和抽象工厂模式区别：
	//a)工厂方法模式:一个工厂生产一个产品
	//b)抽象工厂模式:一个工厂生产多个产品（产品族）

	//抽象工厂模式的定义（实现意图）：提供一个接口（AbstractFactory），
		   //让该接口负责创建一系列相关或者相互依赖的对象(Body,Clothes,Shoes)，而无需指定他们具体的类。

	//三种工厂模式的总结：
	//a)从代码实现复杂度：
	//b)从需要的工厂数量上：
	//c)从实际应用上：

	/*_nmsp1::M_ParFactory* factorySwamp = new _nmsp1::M_Factory_Swamp();
	_nmsp1::M_ParFactory* factoryMountain = new _nmsp1::M_Factory_Mountain();
	_nmsp1::M_ParFactory* factoryTown = new _nmsp1::M_Factory_Town();

	_nmsp1::Monster* swampUndead = factorySwamp->CreateMonster_Undead();
	_nmsp1::Monster* swampElement = factorySwamp->CreateMonster_Element();
	_nmsp1::Monster* swampMechanic = factorySwamp->CreateMonster_Mechanic();

	_nmsp1::Monster* mountainUndead = factoryMountain->CreateMonster_Undead();
	_nmsp1::Monster* mountainElement = factoryMountain->CreateMonster_Element();
	_nmsp1::Monster* mountainMechanic = factoryMountain->CreateMonster_Mechanic();

	_nmsp1::Monster* townUndead = factoryTown->CreateMonster_Undead();
	_nmsp1::Monster* townElement = factoryTown->CreateMonster_Element();
	_nmsp1::Monster* townMechanic = factoryTown->CreateMonster_Mechanic();

	delete factorySwamp;
	delete factoryMountain;
	delete factoryTown;

	delete swampUndead;
	delete swampElement;
	delete swampMechanic;

	delete mountainUndead;
	delete mountainElement;
	delete mountainMechanic;

	delete townUndead;
	delete townElement;
	delete townMechanic;*/

	_nmsp2::AbstractFactory* chinaFactory = new _nmsp2::ChinaFactory();
	_nmsp2::AbstractFactory* japanFactory = new _nmsp2::JapanFactory();
	_nmsp2::AbstractFactory* americaFactory = new _nmsp2::AmericaFactory();

	_nmsp2::Body* chinaBody = chinaFactory->CreateBody();
	_nmsp2::Shoes* chinaShoes = chinaFactory->CreateShoes();
	_nmsp2::Clothes* chinaClothes = chinaFactory->CreateClothes();

	_nmsp2::Body* japanBody = japanFactory->CreateBody();
	_nmsp2::Shoes* japanShoes = japanFactory->CreateShoes();
	_nmsp2::Clothes* japanClothes = japanFactory->CreateClothes();

	_nmsp2::Body* americaBody = americaFactory->CreateBody();
	_nmsp2::Shoes* americaShoes = americaFactory->CreateShoes();
	_nmsp2::Clothes* americaClothes = americaFactory->CreateClothes();

	_nmsp2::BarbieDoll* chinaDoll = new _nmsp2::BarbieDoll(chinaBody, chinaShoes, chinaClothes);
	chinaDoll->Assemble();
	_nmsp2::BarbieDoll* japanDoll = new _nmsp2::BarbieDoll(japanBody, japanShoes, japanClothes);
	japanDoll->Assemble();
	_nmsp2::BarbieDoll* americaDoll = new _nmsp2::BarbieDoll(americaBody, americaShoes, americaClothes);
	americaDoll->Assemble();

	delete chinaFactory;
	delete chinaBody;
	delete chinaShoes;
	delete chinaClothes;
	delete chinaDoll;

	delete japanFactory;
	delete japanBody;
	delete japanShoes;
	delete japanClothes;
	delete japanDoll;

	delete americaFactory;
	delete americaBody;
	delete americaShoes;
	delete americaClothes;
	delete americaDoll;
}
