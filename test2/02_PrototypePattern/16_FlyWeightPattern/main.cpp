#include<iostream>
#include<string>
#include <list>
#include <map>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	enum EnumColor
	{
		Black,
		White
	};
	struct Position
	{
		int m_x;
		int m_y;
		Position(int tmpX, int tmpY)
			:m_x(tmpX),
			m_y(tmpY)
		{

		}
	};

	class Piece
	{
	public:
		Piece(EnumColor tmpColor, Position tmpPos)
			:m_color(tmpColor),
			m_pos(tmpPos)
		{

		}

		void Draw()
		{
			if (m_color == Black)
			{
				cout << "在位置:( " << m_pos.m_x << ", " << m_pos.m_y << ") 处绘制了一个黑色棋子！" << endl;
			}
			else
			{
				cout << "在位置:( " << m_pos.m_x << ", " << m_pos.m_y << ") 处绘制了一个白色棋子！" << endl;
			}
		}

	private:
		EnumColor m_color;
		Position m_pos;
	};
}

namespace _nmsp2
{
	enum EnumColor
	{
		Black,
		White
	};
	struct Position
	{
		int m_x;
		int m_y;
		Position(int tmpX, int tmpY)
			:m_x(tmpX),
			m_y(tmpY)
		{

		}
	};

	class Piece
	{
	public:
		virtual ~Piece() {}
		virtual void Draw(Position tmppos) = 0;
	};

	class BlackPiece : public Piece
	{
	public:
		void Draw(Position temppos) override
		{
			cout << "在位置:( " << temppos.m_x << ", " << temppos.m_y << ") 处绘制了一个黑色棋子！" << endl;
		}
	};

	class WhitePiece : public Piece
	{
	public:
		void Draw(Position temppos) override
		{
			cout << "在位置:( " << temppos.m_x << ", " << temppos.m_y << ") 处绘制了一个白色棋子！" << endl;
		}
	};

	class PieceFactory
	{
	public:
		virtual ~PieceFactory()
		{
			for (auto iter = m_flyWeightMap.begin(); iter != m_flyWeightMap.end(); iter++)
			{
				Piece* tmpfw = iter->second;
				delete tmpfw;
			}
		}

		Piece* GetFlyWeight(EnumColor tmpColor)
		{
			auto iter = m_flyWeightMap.find(tmpColor);
			if (iter == m_flyWeightMap.end())
			{
				Piece* tmpfw = nullptr;
				if (tmpColor == Black)
				{
					tmpfw = new BlackPiece();
				}
				else
				{
					tmpfw = new WhitePiece();
				}
				m_flyWeightMap.insert(make_pair(tmpColor, tmpfw));
				return tmpfw;
			}
			else
				return iter->second;

		}

	private:
		map<EnumColor, Piece*> m_flyWeightMap;
	};



}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第13章 享元（Flyweight）模式:蝇量模式，结构型模式，解决的是面向对象程序设计的性能问题
	//享元：被共享的单元或者被共享的对象。Flyweight——轻量级（占用的内存更少）。
	//设计思想：当需要某个对象时，尽量共用已经创建出的同类对象从而避免频繁使用new创建同类或者相似的对象。
	//（1）从一个典型的范例开始
	//享元对象（被共享的对象）：黑棋，白棋
	//（2）引入享元（Flyweight）模式
	//该模式避免了程序中出现大量相同或者相似的对象，通过共享对象的方式实现相似对象的重用。
	//定义：运用共享技术有效地支持大量细粒度的对象（的复用）。

	//内部状态：存储在享元对象内部，一直不会发生改变的状态。这种状态可以被共享。
	//外部状态：随着外部环境和各种动作因素的改变而发生改变的状态，这种状态不可以被共享。
	// 
	//享元模式的目的：减少对象数量，节省内存，提高程序运行效率。

	//三种角色：
	//a)Flyweight(抽象享元类）：Piece类
	//b)ConcreteFlyweight（具体享元类）：BlackPiece、WhitePiece。
	//c)FlyWeightFactory（享元工厂类）：pieceFactory

	//使用情形：
	//a)程序中有大量相同或者相似对象造成内存大量消耗。
	//b)对象的大部分状态都是或者都可以转变成外部状态，通过参数传入到对象中。
	//c)享元池的引入增加了程序实现的复杂性，当然也有一定内存开销，使用享元模式要衡量性价比。

	//不要将享元模式  对象池，连接池，线程池等混为一谈。

	/*std::list<_nmsp1::Piece*> piecelist;
	_nmsp1::Piece* p_piece1 = new _nmsp1::Piece(_nmsp1::Black, _nmsp1::Position(3, 3));
	p_piece1->Draw();

	_nmsp1::Piece* p_piece2 = new _nmsp1::Piece(_nmsp1::White, _nmsp1::Position(5, 5));
	p_piece2->Draw();

	_nmsp1::Piece* p_piece3 = new _nmsp1::Piece(_nmsp1::Black, _nmsp1::Position(4, 6));
	p_piece3->Draw();

	_nmsp1::Piece* p_piece4 = new _nmsp1::Piece(_nmsp1::White, _nmsp1::Position(5, 7));
	p_piece4->Draw();

	piecelist.push_back(p_piece1);
	piecelist.push_back(p_piece2);
	piecelist.push_back(p_piece3);
	piecelist.push_back(p_piece4);

	delete p_piece1;
	delete p_piece2;
	delete p_piece3;
	delete p_piece4;*/

	_nmsp2::PieceFactory* factory = new _nmsp2::PieceFactory();
	_nmsp2::Piece* p_piece1 = factory->GetFlyWeight(_nmsp2::Black);
	p_piece1->Draw(_nmsp2::Position(3, 3));

	_nmsp2::Piece* p_piece2 = factory->GetFlyWeight(_nmsp2::White);
	p_piece2->Draw(_nmsp2::Position(5, 5));

	_nmsp2::Piece* p_piece3 = factory->GetFlyWeight(_nmsp2::Black);
	p_piece3->Draw(_nmsp2::Position(4, 6));

	_nmsp2::Piece* p_piece4 = factory->GetFlyWeight(_nmsp2::White);
	p_piece4->Draw(_nmsp2::Position(5, 7));

	delete factory;
}
