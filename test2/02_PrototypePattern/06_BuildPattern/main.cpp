#include<iostream>
#include<string>
#include <vector>
#include <sstream>

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
		virtual ~Monster() {}
		void Assemble(string strmodeInfo)
		{
			LoadTrunkModel(strmodeInfo.substr(4, 3));
			LoadHeadModel(strmodeInfo.substr(7, 3));
			LoadLimbsModel(strmodeInfo.substr(10, 3));
		}
		virtual void LoadTrunkModel(string strno) = 0;
		virtual void LoadHeadModel(string strno) = 0;
		virtual void LoadLimbsModel(string strno) = 0;
	};

	class M_Undead :public Monster
	{
	public:
		void LoadTrunkModel(string strno) override
		{
			cout << "载入亡灵类怪物的躯干部位模型，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
	};

	class M_Element :public Monster
	{
	public:
		void LoadTrunkModel(string strno) override
		{
			cout << "载入元素类怪物的躯干部位模型，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
	};

	class M_Mechanic :public Monster
	{
	public:
		void LoadTrunkModel(string strno) override
		{
			cout << "载入机械类怪物的躯干部位模型，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
	};
}

namespace _nmsp2
{
	class Monster
	{
	public:
		virtual ~Monster() {}
	};

	class M_Undead :public Monster
	{};

	class M_Element :public Monster
	{};

	class M_Mechanic :public Monster
	{};

	class MonsterBuild
	{
	public:
		virtual ~MonsterBuild() {}
		virtual void LoadTrunkModel(string strno) = 0;
		virtual void LoadHeadModel(string strno) = 0;
		virtual void LoadLimbsModel(string strno) = 0;
		Monster* GetResult()
		{
			return m_monster;
		}
	protected:
		Monster* m_monster;
	};

	class MonsterDirector
	{
	public:
		MonsterDirector(MonsterBuild* pBuild)
			:m_pMosterBuild(pBuild)
		{

		}
		void SetMonsterBuild(MonsterBuild* pBuild)
		{
			m_pMosterBuild = pBuild;
		}

		Monster* Construct(string strmodeInfo)
		{
			m_pMosterBuild->LoadTrunkModel(strmodeInfo.substr(4, 3));
			m_pMosterBuild->LoadHeadModel(strmodeInfo.substr(7, 3));
			m_pMosterBuild->LoadLimbsModel(strmodeInfo.substr(10, 3));
			return m_pMosterBuild->GetResult();
		}

	private:
		MonsterBuild* m_pMosterBuild;
	};

	class M_UndeadBuild : public MonsterBuild
	{
	public:
		M_UndeadBuild()
		{
			m_monster = new M_Undead();
		}

		void LoadTrunkModel(string strno) override
		{
			cout << "载入亡灵类怪物的躯干部位模型，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
	};

	class M_ElementBuild : public MonsterBuild
	{
	public:
		M_ElementBuild()
		{
			m_monster = new M_Element();
		}

		void LoadTrunkModel(string strno) override
		{
			cout << "载入元素类怪物的躯干部位模型，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
	};

	class M_MechanicBuild : public MonsterBuild
	{
	public:
		M_MechanicBuild()
		{
			m_monster = new M_Mechanic();
		}

		void LoadTrunkModel(string strno) override
		{
			cout << "载入机械类怪物的躯干部位模型，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
	};
}

namespace _nmsp3
{
	class DailyHeaderData
	{
	public:
		DailyHeaderData(string strDepName, string strGenData)
			:m_strDepName(strDepName),
			m_strGenData(strGenData)
		{

		}

		string GetDepName()
		{
			return m_strDepName;
		}

		string GetGenData()
		{
			return m_strGenData;
		}

	private:
		string m_strDepName;
		string m_strGenData;
	};

	class DailyContentData
	{
	public:
		DailyContentData(string strContent, double costTime)
			:m_strContent(strContent),
			m_costTime(costTime)
		{

		}

		string GetContent()
		{
			return m_strContent;
		}

		double GetCostTime()
		{
			return m_costTime;
		}
	private:
		string m_strContent;
		double m_costTime;
	};

	class DailyTailData
	{
	public:
		DailyTailData(string name)
			:m_name(name)
		{
		}

		string GetUseName()
		{
			return m_name;
		}


	private:
		string m_name;
	};

	class ExportToTxtFile
	{
	public:
		void DoExport(DailyHeaderData& dailyHeadObj, vector<DailyContentData*>& vectorDailyContextObj, DailyTailData& dailyTailObj)
		{
			string strtmp;
			strtmp += dailyHeadObj.GetDepName() + "," + dailyHeadObj.GetGenData() + "\n";
			for (auto iter = vectorDailyContextObj.begin(); iter != vectorDailyContextObj.end(); iter++)
			{
				ostringstream oss;
				oss << (*iter)->GetCostTime();
				strtmp += (*iter)->GetContent() + ": （花费的时间: " + oss.str() + "小时）" + "\n";
			}
			strtmp += "报告人: " + dailyTailObj.GetUseName() + "\n";
			cout << strtmp;
		}
	};

	class ExportToXmlFile
	{
	public:
		void DoExport(DailyHeaderData& dailyHeadObj, vector<DailyContentData*>& vectorDailyContextObj, DailyTailData& dailyTailObj)
		{
			string strtmp;
			strtmp += "<?xml version =\"1.0\" encoding=\"UTF-8\" ?>\n";
			strtmp += "<DailyReport>\n";
			strtmp += "		<Header>\n";
			strtmp += "			<DepName>" + dailyHeadObj.GetDepName() + "</DepName>\n";
			strtmp += "			<GenData>" + dailyHeadObj.GetGenData() = "</GenData>\n";

			strtmp += "		<Body>\n";
			for (auto iter = vectorDailyContextObj.begin(); iter != vectorDailyContextObj.end(); iter++)
			{
				ostringstream oss;
				oss << (*iter)->GetCostTime();
				strtmp += "			<Content>" + (*iter)->GetContent() + "</Content>\n";
				strtmp += "			<SpendTime>花费的时间: " + oss.str() + "小时" + "</SpendTime>\n";
			}
			strtmp += "			</Body>\n";

			strtmp += "		<Footer>\n";
			strtmp += "			<UserName>报告人: " + dailyTailObj.GetUseName() + "</UserName>\n";
			strtmp += "		</Footer>\n";
			strtmp += "</DailyReport>\n";

			cout << strtmp;
		}
	};
}

namespace _nmsp4
{
	class DailyHeaderData
	{
	public:
		DailyHeaderData(string strDepName, string strGenData)
			:m_strDepName(strDepName),
			m_strGenData(strGenData)
		{

		}

		string GetDepName()
		{
			return m_strDepName;
		}

		string GetGenData()
		{
			return m_strGenData;
		}

	private:
		string m_strDepName;
		string m_strGenData;
	};

	class DailyContentData
	{
	public:
		DailyContentData(string strContent, double costTime)
			:m_strContent(strContent),
			m_costTime(costTime)
		{

		}

		string GetContent()
		{
			return m_strContent;
		}

		double GetCostTime()
		{
			return m_costTime;
		}
	private:
		string m_strContent;
		double m_costTime;
	};

	class DailyTailData
	{
	public:
		DailyTailData(string name)
			:m_name(name)
		{
		}

		string GetUseName()
		{
			return m_name;
		}

	private:
		string m_name;
	};

	class FileBuild
	{
	public:
		string GetResult()
		{
			return m_strResult;
		}
		virtual void BuildHeader(DailyHeaderData& dailyHeadObj) = 0;
		virtual void BuildBody(vector<DailyContentData*>& vectorDailyContextObj) = 0;
		virtual void BuildFooter(DailyTailData& dailyTailObj) = 0;
	protected:
		string m_strResult;
	};

	class TxtFileBuilder : public FileBuild
	{
	public:
		void BuildHeader(DailyHeaderData& dailyHeadObj)
		{
			m_strResult += dailyHeadObj.GetDepName() + "," + dailyHeadObj.GetGenData() + "\n";
		}

		void BuildBody(vector<DailyContentData*>& vectorDailyContextObj)
		{
			for (auto iter = vectorDailyContextObj.begin(); iter != vectorDailyContextObj.end(); iter++)
			{
				ostringstream oss;
				oss << (*iter)->GetCostTime();
				m_strResult += (*iter)->GetContent() + ": （花费的时间: " + oss.str() + "小时）" + "\n";
			}
		}

		void BuildFooter(DailyTailData& dailyTailObj)
		{
			m_strResult += "报告人: " + dailyTailObj.GetUseName() + "\n";
		}
	};

	class XmlFileBuilder : public FileBuild
	{
	public:
		void BuildHeader(DailyHeaderData& dailyHeadObj)
		{
			m_strResult += "<?xml version =\"1.0\" encoding=\"UTF-8\" ?>\n";
			m_strResult += "<DailyReport>\n";
			m_strResult += "		<Header>\n";
			m_strResult += "			<DepName>" + dailyHeadObj.GetDepName() + "</DepName>\n";
			m_strResult += "			<GenData>" + dailyHeadObj.GetGenData() = "</GenData>\n";
		}

		void BuildBody(vector<DailyContentData*>& vectorDailyContextObj)
		{
			m_strResult += "		<Body>\n";

			for (auto iter = vectorDailyContextObj.begin(); iter != vectorDailyContextObj.end(); iter++)
			{
				ostringstream oss;
				oss << (*iter)->GetCostTime();
				m_strResult += "			<Content>" + (*iter)->GetContent() + "</Content>\n";
				m_strResult += "			<SpendTime>花费的时间: " + oss.str() + "小时" + "</SpendTime>\n";
			}
			m_strResult += "			</Body>\n";
		}

		void BuildFooter(DailyTailData& dailyTailObj)
		{
			m_strResult += "		<Footer>\n";
			m_strResult += "			<UserName>报告人: " + dailyTailObj.GetUseName() + "</UserName>\n";
			m_strResult += "		</Footer>\n";
			m_strResult += "</DailyReport>\n";
		}
	};

	class FileDirector
	{
	public:
		FileDirector(FileBuild* build)
			:m_build(build)
		{

		}

		string Construct(DailyHeaderData& headerData, vector<DailyContentData*>& vecContentData, DailyTailData& tailData)
		{
			m_build->BuildHeader(headerData);
			m_build->BuildBody(vecContentData);
			m_build->BuildFooter(tailData);
			return m_build->GetResult();
		}
	private:
		FileBuild* m_build;
	};
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第三节 建造者（Builder）模式
	//也称：构建器/构建者/生成器模式-创建型模式。
	//通常用于创建比较复杂的对象
	//（1）一个具体实现范例的逐步重构
	//怪物：亡灵类，元素类，机械类
	//怪物组成：头部、躯干（颈部、尾巴）、肢体 三个部位组成。
	//编码步骤：将怪物躯干部模型信息读入内存。将怪物的头部和四肢模型信息读入内存。将头部和四肢模型以正确的位置和方向挂接到躯干部位。  最终装配出完整的怪物模型。
	//Assemble、LoadTrunkModel、LoadHeadModel、LoadLimbsModel称为构建过程相关的函数。
	//引入与怪物类同层次的相关构建器类，把怪物类中代码搬到相关的构建器类中。
	//（2）引入建造者（Builder）模式
	//引入建造者（Builder）模式定义：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
	//MonsterBuilder类就是对象的构建，Monster类是对象的表示。
	//建造者模式包含四种角色：
	//a)Builder（抽象构建器）：这里指MonsterBuilder。
	//b)ConcreteBuilder（具体构建器）：这里指M_UndeadBuilder、M_ElementBuilder、M_MechanicBuilder类。
	//c)Product(产品）：这里指M_Undead、M_Element、M_Mechanic类。
	//d)Director（指挥者）：MonsterDirector类。
	//复杂的东西就考虑拆解，简单的东西就考虑合并。

	//（3）另一个建造者模式的范例
	//各部门员工 工作日报：标题、内容主体、结尾 三部分。
	 //a)标题部分：部门名称、日报生成日期等信息
	 //b)内容主体：具体描述可能有多条（一天可能做了多项工作）
	 //c)结尾：姓名
	//将日报导出成多种格式的文件，比如纯文本，XML格式，JSON格式。
	//（3.1）不用设计模式时程序应该如何书写
	//导出到文件的三个步骤不变：a)拼接标题； b)拼接内容主体；c)拼接结尾
	//考虑把这三个步骤（复杂对象的构建过程）提炼（抽象）出来，形成一个通用的处理过程。
	//建造者模式的初衷：将构建不同格式数据的细节实现代码与具体的构建步骤 分离 达到复用 构建步骤的目的。
	//（3.2）采用设计模式时程序应该如何改写

	/*_nmsp1::Monster* pMonster = new _nmsp1::M_Element();
	pMonster->Assemble("12323424534534");
	delete pMonster;*/

	/*_nmsp2::MonsterBuild* pMonsterBuild = new _nmsp2::M_UndeadBuild();
	_nmsp2::MonsterDirector* pMonsterDirector = new _nmsp2::MonsterDirector(pMonsterBuild);
	_nmsp2::Monster * undead = pMonsterDirector->Construct("12324234234");

	delete pMonsterDirector;
	delete pMonsterBuild;
	delete undead;*/

	/*_nmsp3::DailyHeaderData* pdhd = new _nmsp3::DailyHeaderData("研发一部", "6月25日");
	_nmsp3::DailyContentData* pdcd1 = new _nmsp3::DailyContentData("完成项目A需求分析工作", 3.5);
	_nmsp3::DailyContentData* pdcd2 = new _nmsp3::DailyContentData("确定A所使用的工具", 1.5);

	vector<_nmsp3::DailyContentData*> vecDcd;
	vecDcd.push_back(pdcd1);
	vecDcd.push_back(pdcd2);

	_nmsp3::DailyTailData* pdtd = new _nmsp3::DailyTailData("小李");

	_nmsp3::ExportToTxtFile txtFile;
	txtFile.DoExport(*pdhd, vecDcd, *pdtd);

	_nmsp3::ExportToXmlFile xmlFile;
	xmlFile.DoExport(*pdhd, vecDcd, *pdtd);

	delete pdhd;
	for (auto iter = vecDcd.begin(); iter != vecDcd.end(); iter++)
	{
		delete (*iter);
	}
	delete pdtd;*/

	_nmsp4::DailyHeaderData* pdhd = new _nmsp4::DailyHeaderData("研发一部", "6月25日");
	_nmsp4::DailyContentData* pdcd1 = new _nmsp4::DailyContentData("完成项目A需求分析工作", 3.5);
	_nmsp4::DailyContentData* pdcd2 = new _nmsp4::DailyContentData("确定A所使用的工具", 1.5);

	vector<_nmsp4::DailyContentData*> vecDcd;
	vecDcd.push_back(pdcd1);
	vecDcd.push_back(pdcd2);

	_nmsp4::DailyTailData* pdtd = new _nmsp4::DailyTailData("小李");

	_nmsp4::FileBuild* txtBuild = new _nmsp4::TxtFileBuilder();
	_nmsp4::FileBuild* xmlBuild = new _nmsp4::XmlFileBuilder();
	_nmsp4::FileDirector* director = new _nmsp4::FileDirector(txtBuild);
	string str1 = director->Construct(*pdhd, vecDcd, *pdtd);
	cout << str1<<endl;
	delete director;

	director = new _nmsp4::FileDirector(xmlBuild);
	string str2 = director->Construct(*pdhd, vecDcd, *pdtd);
	cout << str2 << endl;

	delete director;
	delete txtBuild;
	delete xmlBuild;
	delete pdhd;
	for (auto iter = vecDcd.begin(); iter != vecDcd.end(); iter++)
	{
		delete (*iter);
	}
	delete pdtd;
}
