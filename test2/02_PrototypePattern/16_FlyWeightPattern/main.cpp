#include<iostream>
#include<string>
#include <list>
#include <map>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
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
				cout << "��λ��:( " << m_pos.m_x << ", " << m_pos.m_y << ") ��������һ����ɫ���ӣ�" << endl;
			}
			else
			{
				cout << "��λ��:( " << m_pos.m_x << ", " << m_pos.m_y << ") ��������һ����ɫ���ӣ�" << endl;
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
			cout << "��λ��:( " << temppos.m_x << ", " << temppos.m_y << ") ��������һ����ɫ���ӣ�" << endl;
		}
	};

	class WhitePiece : public Piece
	{
	public:
		void Draw(Position temppos) override
		{
			cout << "��λ��:( " << temppos.m_x << ", " << temppos.m_y << ") ��������һ����ɫ���ӣ�" << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��13�� ��Ԫ��Flyweight��ģʽ:Ӭ��ģʽ���ṹ��ģʽ���������������������Ƶ���������
	//��Ԫ��������ĵ�Ԫ���߱�����Ķ���Flyweight������������ռ�õ��ڴ���٣���
	//���˼�룺����Ҫĳ������ʱ�����������Ѿ���������ͬ�����Ӷ�����Ƶ��ʹ��new����ͬ��������ƵĶ���
	//��1����һ�����͵ķ�����ʼ
	//��Ԫ���󣨱�����Ķ��󣩣����壬����
	//��2��������Ԫ��Flyweight��ģʽ
	//��ģʽ�����˳����г��ִ�����ͬ�������ƵĶ���ͨ���������ķ�ʽʵ�����ƶ�������á�
	//���壺���ù�������Ч��֧�ִ���ϸ���ȵĶ��󣨵ĸ��ã���

	//�ڲ�״̬���洢����Ԫ�����ڲ���һֱ���ᷢ���ı��״̬������״̬���Ա�����
	//�ⲿ״̬�������ⲿ�����͸��ֶ������صĸı�������ı��״̬������״̬�����Ա�����
	// 
	//��Ԫģʽ��Ŀ�ģ����ٶ�����������ʡ�ڴ棬��߳�������Ч�ʡ�

	//���ֽ�ɫ��
	//a)Flyweight(������Ԫ�ࣩ��Piece��
	//b)ConcreteFlyweight��������Ԫ�ࣩ��BlackPiece��WhitePiece��
	//c)FlyWeightFactory����Ԫ�����ࣩ��pieceFactory

	//ʹ�����Σ�
	//a)�������д�����ͬ�������ƶ�������ڴ�������ġ�
	//b)����Ĵ󲿷�״̬���ǻ��߶�����ת����ⲿ״̬��ͨ���������뵽�����С�
	//c)��Ԫ�ص����������˳���ʵ�ֵĸ����ԣ���ȻҲ��һ���ڴ濪����ʹ����ԪģʽҪ�����Լ۱ȡ�

	//��Ҫ����Ԫģʽ  ����أ����ӳأ��̳߳صȻ�Ϊһ̸��

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
