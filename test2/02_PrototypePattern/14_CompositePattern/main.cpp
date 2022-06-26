#include<iostream>
#include<string>
#include <list>

using namespace std;

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{
	class File
	{
	public:
		File(string name)
			:m_sName(name)
		{

		}

		void ShowName(string lvlstr)
		{
			cout << lvlstr << "-" << m_sName << endl;
		}
	private:
		string m_sName;
	};

	class Dir
	{
	public:
		Dir(string name)
			:m_sname(name)
		{

		}
	public:
		void AddFile(File* pfile)
		{
			m_childFile.push_back(pfile);
		}

		void AddDir(Dir* pdir)
		{
			m_childDir.push_back(pdir);
		}

		void ShowName(string lvlstr)
		{
			cout << lvlstr << "+" << m_sname << endl;

			lvlstr += "    ";
			for (auto iter = m_childFile.begin(); iter != m_childFile.end(); iter++)
				(*iter)->ShowName(lvlstr);

			for (auto iter = m_childDir.begin(); iter != m_childDir.end(); iter++)
			{
				(*iter)->ShowName(lvlstr);
			}
		}

	private:
		string m_sname;
		list<File*> m_childFile;
		list<Dir*> m_childDir;
	};
}

namespace _nmsp2
{
	class FileSystem
	{
	public:
		virtual void ShowName(int level) = 0;
		virtual int Add(FileSystem* pfilesys) = 0;
		virtual int Remove(FileSystem* pfilesys) = 0;

		virtual ~FileSystem() {}
	};

	class File :public FileSystem
	{
	public:
		File(string name)
			:m_sname(name)
		{

		}

		void ShowName(int level) override
		{
			for (int i = 0; i < level; i++)
			{
				cout << "    ";
			}
			cout << "-" << m_sname << endl;
		}

		int Add(FileSystem* pfilesys) override
		{
			return -1;
		}

		int Remove(FileSystem* pfilesys) override
		{
			return -1;
		}

	private:
		string m_sname;
	};

	class Dir :public FileSystem
	{
	public:
		Dir(string name)
			: m_sname(name)
		{

		}

		void ShowName(int level) override
		{
			for (int i = 0; i < level; i++)
				cout << "    ";
			cout << m_sname << endl;
			level++;
			for (auto iter = m_child.begin(); iter != m_child.end(); iter++)
			{
				(*iter)->ShowName(level);
			}
		}

		int Add(FileSystem* pfilesys) override
		{
			m_child.push_back(pfilesys);
			return 0;
		}

		int Remove(FileSystem* pfilesys) override
		{
			m_child.push_back(pfilesys);
			return 0;
		}
	private:
		string m_sname;
		list<FileSystem*> m_child;
	};
}

namespace _nmsp3
{
	class Dir;
	class FileSystem
	{
	public:
		virtual void ShowName(int level) = 0;
		virtual int CountNumOfFiles() = 0;
		virtual Dir* ifCompositeObj() { return nullptr; }
		virtual ~FileSystem() {}
	};

	class File:public FileSystem
	{
	public:
		File(string name)
			:m_sname(name)
		{

		}

		void ShowName(int level) override
		{
			for (int i = 0; i < level; i++)
				cout << "    ";
			cout << m_sname << endl;
		}

		int CountNumOfFiles() override
		{
			return 1;
		}
	private:
		string m_sname;
	};

	class Dir :public FileSystem
	{
	public:
		Dir(string name)
			:m_sname(name)
		{

		}

		int Add(FileSystem* pfilesys)
		{
			m_child.push_back(pfilesys);
			return 0;
		}

		int Remove(FileSystem* pfilesys)
		{
			m_child.remove(pfilesys);
			return 0;
		}

		Dir* ifCompositeObj() override
		{
			return this;
		}

		int CountNumOfFiles() override
		{
			int iNumOfFiles = 0;
			for (auto iter = m_child.begin(); iter != m_child.end(); iter++)
				iNumOfFiles += (*iter)->CountNumOfFiles();
			return iNumOfFiles;
		}

		void ShowName(int level) override
		{
			for (int i = 0; i < level; i++)
				cout << "    ";
			cout << m_sname << endl;
			level++;
			for (auto iter = m_child.begin(); iter != m_child.end(); iter++)
			{
				(*iter)->ShowName(level);
			}
		}

	private:
		string m_sname;
		list<FileSystem*> m_child;
	};
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第11章 组合（Composite）模式：结构型模式，用来处理树形结构的数据
	//（1）一个基本的目录内容遍历范例：用来表达和处理树形结构数据
	//（2）使用组合模式改造目录内容遍历范例

	// (1) 创建各种目录，文件对象
	//_nmsp1::Dir* pdir1 = new _nmsp1::Dir("root");
	//_nmsp1::File* pFile1 = new _nmsp1::File("common.mk");
	//_nmsp1::File* pFile2 = new _nmsp1::File("config.mk");
	//_nmsp1::File* pFile3 = new _nmsp1::File("makefile");

	//_nmsp1::Dir* pdir2 = new _nmsp1::Dir("app");
	//_nmsp1::File* pFile4 = new _nmsp1::File("nginx.c");
	//_nmsp1::File* pFile5 = new _nmsp1::File("ngx_conf.c");

	//_nmsp1::Dir* pdir3 = new _nmsp1::Dir("signal");
	//_nmsp1::File* pFile6 = new _nmsp1::File("ngx_signal.c");

	//_nmsp1::Dir* pdir4 = new _nmsp1::Dir("_include");
	//_nmsp1::File* pFile7 = new _nmsp1::File("ngx_func.h");
	//_nmsp1::File* pFile8 = new _nmsp1::File("ngx_signal.h");

	//// 构建树形目录结构
	//pdir1->AddFile(pFile1);
	//pdir1->AddFile(pFile2);
	//pdir1->AddFile(pFile3);

	//pdir1->AddDir(pdir2);
	//pdir2->AddFile(pFile4);
	//pdir2->AddFile(pFile5);

	//pdir1->AddDir(pdir3);
	//pdir3->AddFile(pFile6);

	//pdir1->AddDir(pdir4);
	//pdir4->AddFile(pFile7);
	//pdir4->AddFile(pFile8);

	//pdir1->ShowName("");

	//delete pdir1;
	//delete pdir2;
	//delete pdir3;
	//delete pdir4;

	//delete pFile1;
	//delete pFile2;
	//delete pFile3;
	//delete pFile4;
	//delete pFile5;
	//delete pFile6;
	//delete pFile7;
	//delete pFile8;

	//_nmsp2::FileSystem* pdir1 = new _nmsp2::Dir("root");
	//_nmsp2::FileSystem* pFile1 = new _nmsp2::File("common.mk");
	//_nmsp2::FileSystem* pFile2 = new _nmsp2::File("config.mk");
	//_nmsp2::FileSystem* pFile3 = new _nmsp2::File("makefile");
	//_nmsp2::FileSystem* pdir2 = new _nmsp2::Dir("app");
	//_nmsp2::FileSystem* pFile4 = new _nmsp2::File("nginx.c");
	//_nmsp2::FileSystem* pFile5 = new _nmsp2::File("ngx_conf.c");
	//_nmsp2::FileSystem* pdir3 = new _nmsp2::Dir("signal");
	//_nmsp2::FileSystem* pFile6 = new _nmsp2::File("ngx_signal.c");
	//_nmsp2::FileSystem* pdir4 = new _nmsp2::Dir("_include");
	//_nmsp2::FileSystem* pFile7 = new _nmsp2::File("ngx_func.h");
	//_nmsp2::FileSystem* pFile8 = new _nmsp2::File("ngx_signal.h");

	//// 构建树形目录结构
	//pdir1->Add(pFile1);
	//pdir1->Add(pFile2);
	//pdir1->Add(pFile3);

	//pdir1->Add(pdir2);
	//pdir2->Add(pFile4);
	//pdir2->Add(pFile5);

	//pdir1->Add(pdir3);
	//pdir3->Add(pFile6);

	//pdir1->Add(pdir4);
	//pdir4->Add(pFile7);
	//pdir4->Add(pFile8);

	//pdir1->ShowName(0);
	//
	//delete pFile1;
	//delete pFile2;
	//delete pFile3;
	//delete pFile4;
	//delete pFile5;
	//delete pFile6;
	//delete pFile7;
	//delete pFile8;

	_nmsp3::Dir* pdir1 = new _nmsp3::Dir("root");
	_nmsp3::FileSystem* pFile1 = new _nmsp3::File("common.mk");
	_nmsp3::FileSystem* pFile2 = new _nmsp3::File("config.mk");
	_nmsp3::FileSystem* pFile3 = new _nmsp3::File("makefile");
	_nmsp3::Dir* pdir2 = new _nmsp3::Dir("app");
	_nmsp3::FileSystem* pFile4 = new _nmsp3::File("nginx.c");
	_nmsp3::FileSystem* pFile5 = new _nmsp3::File("ngx_conf.c");
	_nmsp3::Dir* pdir3 = new _nmsp3::Dir("signal");
	_nmsp3::FileSystem* pFile6 = new _nmsp3::File("ngx_signal.c");
	_nmsp3::Dir* pdir4 = new _nmsp3::Dir("_include");
	_nmsp3::FileSystem* pFile7 = new _nmsp3::File("ngx_func.h");
	_nmsp3::FileSystem* pFile8 = new _nmsp3::File("ngx_signal.h");

	// 构建树形目录结构
	pdir1->Add(pFile1);
	pdir1->Add(pFile2);
	pdir1->Add(pFile3);

	pdir1->Add(pdir2);
	pdir2->Add(pFile4);
	pdir2->Add(pFile5);

	pdir1->Add(pdir3);
	pdir3->Add(pFile6);

	pdir1->Add(pdir4);
	pdir4->Add(pFile7);
	pdir4->Add(pFile8);

	pdir1->ShowName(0);

	delete pFile1;
	delete pFile2;
	delete pFile3;
	delete pFile4;
	delete pFile5;
	delete pFile6;
	delete pFile7;
	delete pFile8;
}
