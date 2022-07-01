#include<iostream>
#include<string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
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
				return "向上";
			else if (m_direction == "down")
				return "向下";
			else if (m_direction == "left")
				return "向左";
			else if (m_direction == "right")
				return "向右";
			else
				return "运动方向错";
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
				return "行走";
			else if (m_action == "run")
				return "奔跑";
			else
				return "运动方式错";
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
			return m_distance + "米";
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
			return m_left->Interpret() + "再" + m_right->Interpret();
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第21章 解释器（Interpreter）模式：解析器模式，行为型模式。适合对一些比较简单的文法结构进行分析（语言解释器）。
	//（1）一个用解释器模式编写的范例
	//一些变量，一个字母表示，a、b、c、d，值运行时指定。希望对这些变量进行加减法运算（不涉及乘除，考虑简单性）；
	//7、9、3、2，字符串“a-b+c+d”，“7-9+3+2” = 3; 
	//将这些规则表达为一个句子（实质就是如何将计算规则表达为一颗语法树【表达式树】），然后构建解释器来解释这个句子，这就是解释器模式所做的事。
	//非终结符表达式（树枝），终结符表达式（树叶）
	//语法树中的每个节点所属的类都会有一个叫做interpret的成员函数对本节点进行解释。

	//（2）引入解释器（Interpreter）模式
	//定于（实现意图）：定义一个语言的文法（语法规则），并建立一个解释器解释该语言中的句子。
	//当一个语言需要解释执行并且可以将该语言中的句子表示为一颗语法树的时候，就可以使用解释器模式。
	//4种角色：
	//a）AbstractExpression：抽象表达式，Expression类。
	//b）TerminalExpression：终结符表达式，VarExpression类。
	//c）NonterminalExpression：非终结符表达式，AddExpression类和SubExpression类。
	//d）Context：环境类/上下文类：varmap

	//优点：良好的灵活性和可扩展性。
	//缺点：适合实现小而简单的文法；执行效率不会太高；如果语法规则多，会产生大量的类，对于跟踪调试会产生诸多的不便。

	//（3）机器人运动控制范例
	//规定机器人的行为规则：
	//a）运动方向4个：上（up）、下（down）、左（left）、右（right）；
	//b）运动方式2个：行走（walk）、奔跑（run）；
	//c）机器人能够接受的终结符表达式有   运动方向、运动方式、运动距离（单位：米）。
	   //left walk 15 ：表示向左行走15米；
	   //down run 20：向下奔跑20米；
	//d)机器人能接受的非终结符表达式是“句子”，句子由“运动方向 运动方式 运动距离”构成。
				//另一个非终结符表达式“and”，代表“和”的意思。比如
	   //left walk 15 and down run 20。

	//string strExp = "a-b+c+d";
	//map<char, int> varmap;
	//varmap.insert(make_pair('a', 7));
	//varmap.insert(make_pair('b', 9));
	//varmap.insert(make_pair('c', 3));
	//varmap.insert(make_pair('d', 2));
	//_nmsp1::Expression* expression = _nmsp1::Analyse(strExp);
	//int result = expression->Interpret(varmap);
	//cout << "结果: " << result << endl;
	//_nmsp1::Release(expression);

	string strExp = "left walk 15 and down run 20";
	_nmsp2::Expression* expression = _nmsp2::Analyse(strExp);
	cout << expression->Interpret() << endl;
	_nmsp2::Release(expression);
	return 0;
}
