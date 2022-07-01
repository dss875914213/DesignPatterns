#include<iostream>
#include<string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class Expression
	{
	public:
		Expression(int num, char sign) :
			m_dgb_num(num),
			m_dbg_sign(sign)
		{

		}

	public:
		virtual int Interpret(map<char, int> var) = 0;


	public:
		int m_dgb_num;
		char m_dbg_sign;
	};

	class VarExpression :public Expression
	{
	public:
		VarExpression(const char& key, int num, char sign)
			:Expression(num, sign),
			m_key(key)
		{

		}

		int Interpret(map<char, int> var) override
		{
			return var[m_key];
		}

	private:
		char m_key;
	};

	class SymbolExpression :public Expression
	{
	public:
		SymbolExpression(Expression* left, Expression* right, int num, char sign)
			:Expression(num, sign),
			m_left(left),
			m_right(right)
		{

		}

		Expression* GetLeft()
		{
			return m_left;
		}

		Expression* GetRight()
		{
			return m_right;
		}

	protected:
		Expression* m_left;
		Expression* m_right;
	};

	class AddExpression :public SymbolExpression
	{
	public:
		AddExpression(Expression* left, Expression* right, int num, char sign)
			:SymbolExpression(left, right, num, sign)
		{

		}

		int Interpret(map<char, int> var) override
		{
			int value1 = m_left->Interpret(var);
			int value2 = m_right->Interpret(var);
			int result = value1 + value2;
			return result;
		}
	};

	class SubExpression : public SymbolExpression
	{
	public:
		SubExpression(Expression* left, Expression* right, int num, char sign)
			:SymbolExpression(left, right, num, sign)
		{
		}

		int Interpret(map<char, int> var) override
		{
			int value1 = m_left->Interpret(var);
			int value2 = m_right->Interpret(var);
			int result = value1 - value2;
			return result;
		}
	};

	Expression* Analyse(string strExp)
	{
		stack<Expression*> expStack;
		Expression* left = nullptr;
		Expression* right = nullptr;
		int icount = 1;
		for (size_t i = 0; i < strExp.size(); i++)
		{
			switch (strExp[i])
			{
			case '+':
				left = expStack.top();
				i++;
				right = new VarExpression(strExp[i], icount++, 'v');
				expStack.push(new AddExpression(left, right, icount++, '+'));
				break;
			case '-':
				left = expStack.top();
				i++;
				right = new VarExpression(strExp[i], icount++, 'v');
				expStack.push(new SubExpression(left, right, icount++, '-'));
				break;
			default:
				expStack.push(new VarExpression(strExp[i], icount++, 'v'));
				break;
			}
		}

		Expression* expression = expStack.top();
		return expression;
	}

	void Release(Expression* expression)
	{
		SymbolExpression* pSe = dynamic_cast<SymbolExpression*>(expression);
		if (pSe)
		{
			Release(pSe->GetLeft());
			Release(pSe->GetRight());
		}
		delete expression;
	}
}

namespace _nmsp2
{
	class Expression
	{
	public:
		~Expression()
		{

		}
	public:
		virtual string Interpret() = 0;
	};

	class DirectionExpression :public Expression
	{
	public:
		DirectionExpression(const string& direction)
			:m_direction(direction)
		{

		}

		string Interpret() override
		{
			if (m_direction == "up")
				return "����";
			else if (m_direction == "down")
				return "����";
			else if (m_direction == "left")
				return "����";
			else if (m_direction == "right")
				return "����";
			else
				return "�˶������";
		}

	private:
		string m_direction;
	};

	class ActionExpression :public Expression
	{
	public:
		ActionExpression(const string& action)
			:m_action(action)
		{

		}

		string Interpret() override
		{
			if (m_action == "walk")
				return "����";
			else if (m_action == "run")
				return "����";
			else
				return "�˶���ʽ��";
		}

	private:
		string m_action;
	};

	class DistanceExpression :public Expression
	{
	public:
		DistanceExpression(const string& distance)
			:m_distance(distance)
		{

		}

		string Interpret() override
		{
			return m_distance + "��";
		}

	private:
		string m_distance;
	};

	class SentenceExpression :public Expression
	{
	public:
		SentenceExpression(Expression* direction, Expression* action, Expression* distance)
			:m_direction(direction),
			m_action(action),
			m_distance(distance)
		{

		}

		Expression* GetDirection()
		{
			return m_direction;
		}

		Expression* GetAction()
		{
			return m_action;
		}

		Expression* GetDistance()
		{
			return m_distance;
		}

		string Interpret() override
		{
			return m_distance->Interpret() + m_action->Interpret() + m_distance->Interpret();
		}

	private:
		Expression* m_direction;
		Expression* m_action;
		Expression* m_distance;
	};

	class AndExpression :public Expression
	{
	public:
		AndExpression(Expression* left, Expression* right)
			:m_left(left),
			m_right(right)
		{

		}

		Expression* GetLeft()
		{
			return m_left;
		}

		Expression* GetRight()
		{
			return m_right;
		}

		string Interpret() override
		{
			return m_left->Interpret() + "��" + m_right->Interpret();
		}

	private:
		Expression* m_left;
		Expression* m_right;
	};

	Expression* Analyse(string strExp)
	{
		stack<Expression*> expStack;
		Expression* direction = nullptr;
		Expression* action = nullptr;
		Expression* distance = nullptr;
		Expression* left = nullptr;
		Expression* right = nullptr;

		char* strc = new char[strlen(strExp.c_str()) + 1];
		strcpy(strc, strExp.c_str());
		vector<string> resultVec;
		char* tmpStr = strtok(strc, " ");
		while (tmpStr != nullptr)
		{
			resultVec.push_back(string(tmpStr));
			tmpStr = strtok(NULL, " ");
		}
		delete[] strc;
		for (auto iter = resultVec.begin(); iter != resultVec.end(); iter++)
		{
			if ((*iter) == "and")
			{
				left = expStack.top();
				++iter;
				direction = new DirectionExpression(*iter);
				++iter;
				action = new ActionExpression(*iter);
				++iter;
				distance = new DistanceExpression(*iter);
				right = new SentenceExpression(direction, action, distance);
				expStack.push(new AndExpression(left, right));
			}
			else
			{
				direction = new DirectionExpression(*iter);
				++iter;
				action = new ActionExpression(*iter);
				++iter;
				distance = new DistanceExpression(*iter);

				expStack.push(new SentenceExpression(direction, action, distance));
			}
		}
		Expression* expression = expStack.top();
		return expression;
	}

	void Release(Expression* expression)
	{
		SentenceExpression* pSE = dynamic_cast<SentenceExpression*>(expression);
		if (pSE)
		{
			Release(pSE->GetDirection());
			Release(pSE->GetAction());
			Release(pSE->GetDistance());
		}
		else
		{
			AndExpression* pAE = dynamic_cast<AndExpression*>(expression);
			if (pAE)
			{
				Release(pAE->GetLeft());
				Release(pAE->GetRight());
			}
		}
		delete expression;
	}
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��21�� ��������Interpreter��ģʽ��������ģʽ����Ϊ��ģʽ���ʺ϶�һЩ�Ƚϼ򵥵��ķ��ṹ���з��������Խ���������
	//��1��һ���ý�����ģʽ��д�ķ���
	//һЩ������һ����ĸ��ʾ��a��b��c��d��ֵ����ʱָ����ϣ������Щ�������мӼ������㣨���漰�˳������Ǽ��ԣ���
	//7��9��3��2���ַ�����a-b+c+d������7-9+3+2�� = 3; 
	//����Щ������Ϊһ�����ӣ�ʵ�ʾ�����ν����������Ϊһ���﷨�������ʽ��������Ȼ�󹹽�������������������ӣ�����ǽ�����ģʽ�������¡�
	//���ս�����ʽ����֦�����ս�����ʽ����Ҷ��
	//�﷨���е�ÿ���ڵ��������඼����һ������interpret�ĳ�Ա�����Ա��ڵ���н��͡�

	//��2�������������Interpreter��ģʽ
	//���ڣ�ʵ����ͼ��������һ�����Ե��ķ����﷨���򣩣�������һ�����������͸������еľ��ӡ�
	//��һ��������Ҫ����ִ�в��ҿ��Խ��������еľ��ӱ�ʾΪһ���﷨����ʱ�򣬾Ϳ���ʹ�ý�����ģʽ��
	//4�ֽ�ɫ��
	//a��AbstractExpression��������ʽ��Expression�ࡣ
	//b��TerminalExpression���ս�����ʽ��VarExpression�ࡣ
	//c��NonterminalExpression�����ս�����ʽ��AddExpression���SubExpression�ࡣ
	//d��Context��������/�������ࣺvarmap

	//�ŵ㣺���õ�����ԺͿ���չ�ԡ�
	//ȱ�㣺�ʺ�ʵ��С���򵥵��ķ���ִ��Ч�ʲ���̫�ߣ�����﷨����࣬������������࣬���ڸ��ٵ��Ի�������Ĳ��㡣

	//��3���������˶����Ʒ���
	//�涨�����˵���Ϊ����
	//a���˶�����4�����ϣ�up�����£�down������left�����ң�right����
	//b���˶���ʽ2�������ߣ�walk�������ܣ�run����
	//c���������ܹ����ܵ��ս�����ʽ��   �˶������˶���ʽ���˶����루��λ���ף���
	   //left walk 15 ����ʾ��������15�ף�
	   //down run 20�����±���20�ף�
	//d)�������ܽ��ܵķ��ս�����ʽ�ǡ����ӡ��������ɡ��˶����� �˶���ʽ �˶����롱���ɡ�
				//��һ�����ս�����ʽ��and���������͡�����˼������
	   //left walk 15 and down run 20��

	//string strExp = "a-b+c+d";
	//map<char, int> varmap;
	//varmap.insert(make_pair('a', 7));
	//varmap.insert(make_pair('b', 9));
	//varmap.insert(make_pair('c', 3));
	//varmap.insert(make_pair('d', 2));
	//_nmsp1::Expression* expression = _nmsp1::Analyse(strExp);
	//int result = expression->Interpret(varmap);
	//cout << "���: " << result << endl;
	//_nmsp1::Release(expression);

	string strExp = "left walk 15 and down run 20";
	_nmsp2::Expression* expression = _nmsp2::Analyse(strExp);
	cout << expression->Interpret() << endl;
	_nmsp2::Release(expression);
	return 0;
}
