#include<iostream>
#include<string>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
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
			cout << "������ͨ�б�ؼ�" << endl;
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
			cout << "���Ʊ߿�" << endl;
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
			cout << "���ƴ�ֱ������" << endl;
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
			cout << "����ˮƽ������" << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������

	//��6��  װ�Σ�Decorator��ģʽ��װ����ģʽ/��װģʽ���ṹ��ģʽ
	//��1����������
	 //UI���û��ӿڣ����档
	   //a)ListCtrl�������ͨ�б�ؼ����ṩdraw����
	   //b)BorderListCtrl�࣬�̳���ListCtrl�������˱߿���б�ؼ����ṩdraw����
	   //c)VerScBorderListCtrl��̳���BorderListCtrl����ʾ�����˱߿��������˴�ֱ���������б�ؼ����ṩdraw����
	   //d)HorScVerScBorderListCtrl�࣬�̳���VerScBorderListCtrl����ʾ�����˱߿򣬴�ֱ��ˮƽ���������б�ؼ����ṩdraw����
	//�̳� ��Ϊ ��װ��ʽ���������ֹ�෺��
	   //a)ListCtrl�������ͨ�б�ؼ����ṩdraw����
	   //b)���ӱ߿�->���߿���б�ؼ�
	   //c)���Ӵ�ֱ������->�����ʹ��������б�ؼ����ٸ��������ֱ���������б�ؼ�����һ��ˮƽ������->�ȴ���ֱ�������ִ�ˮƽ���������б�ؼ���

	//����ͨ��װ�η�ʽ��һ����Ĺ��ܲ�����ǿ��˼�루��̬�������¹��ܣ�������װ��ģʽ�ĺ������˼�롣
	// public �̳У�is -a ��ϵ����Ϲ�ϵ��ί�й�ϵ��

	//��2������װ�Σ�Decorator��ģʽ
	//��ϸ���ԭ��Composite Reuse Principle��CRP����Ҳ��Ϊ�ϳɸ���ԭ��/�ۺϸ���ԭ��
	  //������ʹ�ü̳н�����ƣ����������޸Ŀ���Ӱ���������Ϊ�����ң����ܸ����еĺܶ෽���������ò��ϵģ�����Ȼ��һ���˷ѣ� 
	   //��ʹ����Ͻ�����ƣ�����Դ�󽵵�������֮���������ϵ��Ҳ���������̳й�ϵ���µ��˷���Ϊ������
		//����̳к���϶��ܴﵽ���Ŀ�ģ����ȿ���ʹ����ϣ�������ڼ̳У���
	//��װ�Ρ����ģʽ�Ķ��壨ʵ����ͼ������̬�ĸ�һ���������һЩ�����ְ�𡣾����ӹ�����˵����ģʽ����������������
	//װ��ģʽ���������ֽ�ɫ��
	 //a��Control�����󹹼�����draw���õ�������һ�µķ�ʽ����δ�����εĶ����Լ���������֮��Ķ���ʵ�ֿͻ��˵�͸��������
	 //b��ListCtrl�����幹������ʵ�ֳ��󹹼�����Ľӿڣ��˺�װ�����Ϳ��Ը��ù������Ӷ���ķ�����ְ�𣩣�
	 //c��Decorator������װ�����ࣩ��
	 //d��BorderDec��VerScrollBarDec��HorScrollBarDesc������װ�����ࣩ��������һЩ�·�����Ȼ��ͨ����draw�ӿڵ���չ���ﵽ���յ�����Ŀ�ġ�

	//��3����һ��װ��ģʽ�ķ���:����ˮ���������ռ۸�
	//a)һ��������ˮ�����ϣ��ۼ�Ϊ10Ԫ��
	//b)���������������ɰ�ǣ������Ҫ�Ӷ�1Ԫ��
	//c)���������������ţ�̣������Ҫ�Ӷ�2Ԫ��
	//d)������������������飬�����Ҫ�Ӷ�2Ԫ��
	//e)�ּ������ּ�ɰ�ǣ�10+2+1 = 13

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
