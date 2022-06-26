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
	class Control
	{
	public:
		virtual ~Control() {}
		virtual void Draw() = 0;
	};

	class ListCtrl :public Control
	{
	public:
		void Draw() override
		{
			cout << "绘制普通列表控件" << endl;
		}
	};

	class Decorator :public Control
	{
	public:
		Decorator(Control* control)
			:m_control(control)
		{

		}
		void Draw() override
		{
			m_control->Draw();
		}

	private:
		Control* m_control;
	};

	class BorderDec :public Decorator
	{
	public:
		BorderDec(Control* control)
			:Decorator(control)
		{

		}
		void Draw() override
		{
			Decorator::Draw();
			DrawBorder();
		}
	private:
		void DrawBorder()
		{
			cout << "绘制边框" << endl;
		}
	};

	class VerScrollBarDec : public Decorator
	{
	public:
		VerScrollBarDec(Control* control)
			:Decorator(control)
		{

		}
		void Draw() override
		{
			Decorator::Draw();
			DrawVerScroll();
		}
	private:
		void DrawVerScroll()
		{
			cout << "绘制垂直滚动条" << endl;
		}
	};

	class HorScrollBarDec: public Decorator
	{
	public:
		HorScrollBarDec(Control* control)
			:Decorator(control)
		{

		}
		void Draw() override
		{
			Decorator::Draw();
			DrawHorVerScroll();
		}
	private:
		void DrawHorVerScroll()
		{
			cout << "绘制水平滚动条" << endl;
		}
	};
}

namespace _nmsp2
{
	class Drink
	{
	public:
		virtual ~Drink() {}
		virtual int GetPrice() = 0;
	};

	class FruitDrink :public Drink
	{
	public:
		int GetPrice() override
		{
			return 10;
		}
	};

	class Decorator :public Drink
	{
	public:
		Decorator(Drink* drink)
			:m_drink(drink)
		{

		}

		int GetPrice() override
		{
			return m_drink->GetPrice();
		}

	private:
		Drink* m_drink;
	};

	class Sugar : public Decorator
	{
	public:
		Sugar(Drink* drink)
			:Decorator(drink)
		{

		}
		int GetPrice() override
		{
			return Decorator::GetPrice() + 1;
		}
	
	};

	class Milk : public Decorator
	{
	public:
		Milk(Drink* drink)
			:Decorator(drink)
		{

		}
		int GetPrice() override
		{
			return Decorator::GetPrice() + 5;
		}

	};

	class Bubble : public Decorator
	{
	public:
		Bubble(Drink* drink)
			:Decorator(drink)
		{

		}
		int GetPrice() override
		{
			return Decorator::GetPrice() + 10;
		}
	};

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

	//第6章  装饰（Decorator）模式：装饰器模式/包装模式，结构型模式
	//（1）问题的提出
	 //UI（用户接口）界面。
	   //a)ListCtrl类代表普通列表控件，提供draw方法
	   //b)BorderListCtrl类，继承自ListCtrl，增加了边框的列表控件，提供draw方法
	   //c)VerScBorderListCtrl类继承自BorderListCtrl，表示增加了边框又增加了垂直滚动条的列表控件，提供draw方法
	   //d)HorScVerScBorderListCtrl类，继承自VerScBorderListCtrl，表示增加了边框，垂直、水平滚动条的列表控件，提供draw方法
	//继承 改为 组装方式来解决，防止类泛滥
	   //a)ListCtrl类代表普通列表控件，提供draw方法
	   //b)增加边框->带边框的列表控件
	   //c)增加垂直滚动条->带纯质滚动条的列表控件，再给这个带垂直滚动条的列表控件增加一个水平滚动条->既带垂直滚动条又带水平滚动条的列表控件。

	//这种通过装饰方式将一个类的功能不断增强的思想（动态的增加新功能），就是装饰模式的核心设计思想。
	// public 继承：is -a 关系，组合关系和委托关系。

	//（2）引入装饰（Decorator）模式
	//组合复用原则（Composite Reuse Principle，CRP），也称为合成复用原则/聚合复用原则。
	  //若两个使用继承进行设计，则父类代码的修改可能影响子类的行为，而且，可能父类中的很多方法子类是用不上的，这显然是一种浪费， 
	   //若使用组合进行设计，则可以大大降低两个类之间的依赖关系，也不会存在因继承关系导致的浪费行为，所以
		//如果继承和组合都能达到设计目的，优先考虑使用组合（组合优于继承）。
	//“装饰”设计模式的定义（实现意图）：动态的给一个对象添加一些额外的职责。就增加功能来说，该模式相比生成子类更加灵活。
	//装饰模式包含的四种角色：
	 //a：Control（抽象构件）：draw，让调用者以一致的方式处理未被修饰的对象以及经过修饰之后的对象，实现客户端的透明操作。
	 //b：ListCtrl（具体构件）：实现抽象构件定义的接口，此后，装饰器就可以给该构件增加额外的方法（职责）；
	 //c：Decorator（抽象装饰器类）：
	 //d：BorderDec、VerScrollBarDec、HorScrollBarDesc（具体装饰器类）：增加了一些新方法，然后通过对draw接口的扩展，达到最终的修饰目的。

	//（3）另一个装饰模式的范例:计算水果饮料最终价格
	//a)一杯单纯的水果饮料，售价为10元。
	//b)如果向饮料中增加砂糖，则额外要加多1元。
	//c)如果向饮料中增加牛奶，则额外要加多2元。
	//d)如果向饮料中增加珍珠，则额外要加多2元。
	//e)又加珍珠又加砂糖，10+2+1 = 13

	/*_nmsp1::Control* control = new _nmsp1::ListCtrl();
	_nmsp1::Control* borderDec = new _nmsp1::BorderDec(control);
	_nmsp1::Control* verScrollBarDec = new _nmsp1::VerScrollBarDec(borderDec);
	_nmsp1::Control* horScrollBarDec = new _nmsp1::HorScrollBarDec(verScrollBarDec);

	horScrollBarDec->Draw();

	delete control;
	delete borderDec;
	delete verScrollBarDec;
	delete horScrollBarDec;*/

	_nmsp2::Drink* drink = new _nmsp2::FruitDrink();
	_nmsp2::Drink* suger = new _nmsp2::Sugar(drink);
	_nmsp2::Drink* sugerMilk = new _nmsp2::Milk(suger);
	cout << sugerMilk->GetPrice() << endl;

	delete sugerMilk;
	delete suger;
	delete drink;
	

}
