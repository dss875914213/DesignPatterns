#include<iostream>
#include<string>
#include <vector>
#include <sstream>

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
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
			cout << "�����������������ɲ�λģ�ͣ���Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "��������������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "����������������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
		}
	};

	class M_Element :public Monster
	{
	public:
		void LoadTrunkModel(string strno) override
		{
			cout << "����Ԫ�����������ɲ�λģ�ͣ���Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "����Ԫ��������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "����Ԫ����������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
		}
	};

	class M_Mechanic :public Monster
	{
	public:
		void LoadTrunkModel(string strno) override
		{
			cout << "�����е���������ɲ�λģ�ͣ���Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "�����е������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "�����е��������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
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
			cout << "�����������������ɲ�λģ�ͣ���Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "��������������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "����������������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Undead����丸������������Ա�������߼�������......" << endl;
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
			cout << "����Ԫ�����������ɲ�λģ�ͣ���Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "����Ԫ��������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "����Ԫ����������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Element����丸������������Ա�������߼�������......" << endl;
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
			cout << "�����е���������ɲ�λģ�ͣ���Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
		}

		void LoadHeadModel(string strno) override
		{
			cout << "�����е������ͷ��ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
		}

		void LoadLimbsModel(string strno) override
		{
			cout << "�����е��������֫ģ�Ͳ��ҽӵ����ɲ�λ����Ҫ����M_Mechanic����丸������������Ա�������߼�������......" << endl;
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
				strtmp += (*iter)->GetContent() + ": �����ѵ�ʱ��: " + oss.str() + "Сʱ��" + "\n";
			}
			strtmp += "������: " + dailyTailObj.GetUseName() + "\n";
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
				strtmp += "			<SpendTime>���ѵ�ʱ��: " + oss.str() + "Сʱ" + "</SpendTime>\n";
			}
			strtmp += "			</Body>\n";

			strtmp += "		<Footer>\n";
			strtmp += "			<UserName>������: " + dailyTailObj.GetUseName() + "</UserName>\n";
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
				m_strResult += (*iter)->GetContent() + ": �����ѵ�ʱ��: " + oss.str() + "Сʱ��" + "\n";
			}
		}

		void BuildFooter(DailyTailData& dailyTailObj)
		{
			m_strResult += "������: " + dailyTailObj.GetUseName() + "\n";
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
				m_strResult += "			<SpendTime>���ѵ�ʱ��: " + oss.str() + "Сʱ" + "</SpendTime>\n";
			}
			m_strResult += "			</Body>\n";
		}

		void BuildFooter(DailyTailData& dailyTailObj)
		{
			m_strResult += "		<Footer>\n";
			m_strResult += "			<UserName>������: " + dailyTailObj.GetUseName() + "</UserName>\n";
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//������ �����ߣ�Builder��ģʽ
	//Ҳ�ƣ�������/������/������ģʽ-������ģʽ��
	//ͨ�����ڴ����Ƚϸ��ӵĶ���
	//��1��һ������ʵ�ַ��������ع�
	//��������࣬Ԫ���࣬��е��
	//������ɣ�ͷ�������ɣ�������β�ͣ���֫�� ������λ��ɡ�
	//���벽�裺���������ɲ�ģ����Ϣ�����ڴ档�������ͷ������֫ģ����Ϣ�����ڴ档��ͷ������֫ģ������ȷ��λ�úͷ���ҽӵ����ɲ�λ��  ����װ��������Ĺ���ģ�͡�
	//Assemble��LoadTrunkModel��LoadHeadModel��LoadLimbsModel��Ϊ����������صĺ�����
	//�����������ͬ��ε���ع������࣬�ѹ������д���ᵽ��صĹ��������С�
	//��2�����뽨���ߣ�Builder��ģʽ
	//���뽨���ߣ�Builder��ģʽ���壺��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
	//MonsterBuilder����Ƕ���Ĺ�����Monster���Ƕ���ı�ʾ��
	//������ģʽ�������ֽ�ɫ��
	//a)Builder�����󹹽�����������ָMonsterBuilder��
	//b)ConcreteBuilder�����幹������������ָM_UndeadBuilder��M_ElementBuilder��M_MechanicBuilder�ࡣ
	//c)Product(��Ʒ��������ָM_Undead��M_Element��M_Mechanic�ࡣ
	//d)Director��ָ���ߣ���MonsterDirector�ࡣ
	//���ӵĶ����Ϳ��ǲ�⣬�򵥵Ķ����Ϳ��Ǻϲ���

	//��3����һ��������ģʽ�ķ���
	//������Ա�� �����ձ������⡢�������塢��β �����֡�
	 //a)���ⲿ�֣��������ơ��ձ��������ڵ���Ϣ
	 //b)�������壺�������������ж�����һ��������˶������
	 //c)��β������
	//���ձ������ɶ��ָ�ʽ���ļ������紿�ı���XML��ʽ��JSON��ʽ��
	//��3.1���������ģʽʱ����Ӧ�������д
	//�������ļ����������費�䣺a)ƴ�ӱ��⣻ b)ƴ���������壻c)ƴ�ӽ�β
	//���ǰ����������裨���Ӷ���Ĺ������̣����������󣩳������γ�һ��ͨ�õĴ�����̡�
	//������ģʽ�ĳ��ԣ���������ͬ��ʽ���ݵ�ϸ��ʵ�ִ��������Ĺ������� ���� �ﵽ���� ���������Ŀ�ġ�
	//��3.2���������ģʽʱ����Ӧ����θ�д

	/*_nmsp1::Monster* pMonster = new _nmsp1::M_Element();
	pMonster->Assemble("12323424534534");
	delete pMonster;*/

	/*_nmsp2::MonsterBuild* pMonsterBuild = new _nmsp2::M_UndeadBuild();
	_nmsp2::MonsterDirector* pMonsterDirector = new _nmsp2::MonsterDirector(pMonsterBuild);
	_nmsp2::Monster * undead = pMonsterDirector->Construct("12324234234");

	delete pMonsterDirector;
	delete pMonsterBuild;
	delete undead;*/

	/*_nmsp3::DailyHeaderData* pdhd = new _nmsp3::DailyHeaderData("�з�һ��", "6��25��");
	_nmsp3::DailyContentData* pdcd1 = new _nmsp3::DailyContentData("�����ĿA�����������", 3.5);
	_nmsp3::DailyContentData* pdcd2 = new _nmsp3::DailyContentData("ȷ��A��ʹ�õĹ���", 1.5);

	vector<_nmsp3::DailyContentData*> vecDcd;
	vecDcd.push_back(pdcd1);
	vecDcd.push_back(pdcd2);

	_nmsp3::DailyTailData* pdtd = new _nmsp3::DailyTailData("С��");

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

	_nmsp4::DailyHeaderData* pdhd = new _nmsp4::DailyHeaderData("�з�һ��", "6��25��");
	_nmsp4::DailyContentData* pdcd1 = new _nmsp4::DailyContentData("�����ĿA�����������", 3.5);
	_nmsp4::DailyContentData* pdcd2 = new _nmsp4::DailyContentData("ȷ��A��ʹ�õĹ���", 1.5);

	vector<_nmsp4::DailyContentData*> vecDcd;
	vecDcd.push_back(pdcd1);
	vecDcd.push_back(pdcd2);

	_nmsp4::DailyTailData* pdtd = new _nmsp4::DailyTailData("С��");

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
