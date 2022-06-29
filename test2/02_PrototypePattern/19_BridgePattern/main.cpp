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
	class Image
	{
	public:
		void Draw(const char* pFileName)
		{
			int iLen = 0;
			char* pData = ParseFile(pFileName, iLen);
			if (iLen > 0)
			{
				cout << "显示pData所指向的缓冲区中的图像数据" << endl;
				delete pData;
			}
		}

		virtual ~Image() {}
	private:
		virtual char* ParseFile(const char* pfileName, int& iLen) = 0;
	};

	class ImagePng :public Image
	{
	private:
		char* ParseFile(const char* pFileName, int& iLen) override
		{
			cout << "开始分析 png 文件中的数据并将分析结构放到 pData 中。";
			iLen = 100;
			char* presult = new char[iLen];
			return presult;
		}
	};

	class ImageJpg :public Image
	{
	private:
		char* ParseFile(const char* pFileName, int& iLen) override
		{
			cout << "开始分析 jpg 文件中的数据并将分析结构放到 pData 中。";
			iLen = 100;
			char* presult = new char[iLen];
			return presult;
		}
	};

	class ImageBmp :public Image
	{
	private:
		char* ParseFile(const char* pFileName, int& iLen) override
		{
			cout << "开始分析 bmp 文件中的数据并将分析结构放到 pData 中。";
			iLen = 100;
			char* presult = new char[iLen];
			return presult;
		}
	};
}

namespace _nmsp2
{
	class ImageOS
	{
	public:
		virtual void Draw(char* pData, int iLen) = 0;
		virtual ~ImageOS() {}
	};

	class ImageOSWindows :public ImageOS
	{
	public:
		void Draw(char* pData, int iLen)
		{
			cout << "在 Windows 操作系统上显示 pData 所指向的缓存区中的图像类" << endl;
		}
	};

	class ImageOSLinux :public ImageOS
	{
	public:
		void Draw(char* pData, int iLen)
		{
			cout << "在 Linux 操作系统上显示 pData 所指向的缓存区中的图像类" << endl;
		}
	};

	class ImageOSMac :public ImageOS
	{
	public:
		void Draw(char* pData, int iLen)
		{
			cout << "在 Mac 操作系统上显示 pData 所指向的缓存区中的图像类" << endl;
		}
	};

	class ImageFormat
	{
	public:
		ImageFormat(ImageOS* pimgos) :
			m_pImage(pimgos)
		{

		}

		virtual void ParseFile(const char* pfilename) = 0;
		virtual ~ImageFormat() {}

	protected:
		ImageOS* m_pImage;
	};

	class ImagePng :public ImageFormat
	{
	public:
		ImagePng(ImageOS* pimgos)
			:ImageFormat(pimgos)
		{

		}

		void ParseFile(const char* pfilename) override
		{
			cout << "开始分析 png 文件中的数据并将结果放到 pData 中" << endl;
			int iLen = 100;
			char* presult = new char[iLen];
			m_pImage->Draw(presult, iLen);
			delete presult;
		}
	};

	class ImageJpg :public ImageFormat
	{
	public:
		ImageJpg(ImageOS* pimgos)
			:ImageFormat(pimgos)
		{

		}
		void ParseFile(const char* pfilename) override
		{
			cout << "开始分析 jpg 文件中的数据并将结果放到 pData 中" << endl;
			int iLen = 100;
			char* presult = new char[iLen];
			m_pImage->Draw(presult, iLen);
			delete presult;
		}
	};

	class ImageBmp :public ImageFormat
	{
	public:
		ImageBmp(ImageOS* pimgos)
			:ImageFormat(pimgos)
		{

		}
		void ParseFile(const char* pfilename) override
		{
			cout << "开始分析 bmp 文件中的数据并将结果放到 pData 中" << endl;
			int iLen = 100;
			char* presult = new char[iLen];
			m_pImage->Draw(presult, iLen);
			delete presult;
		}
	};
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第16章 桥接（Bridge）模式：桥梁模式（桥模式），结构型模式。
	//解决的问题：根据单一职责原则，在一个类中，不要做太多事情，如果事情很多，尽量拆分到多个类中去，然后在
	  //一个类中包含指向另外一个类对象的指针，当需要执行另外一个类中的动作时，用指针直接去调用另外一个类的成员函数。
	  // 
	//（1）一个传统的继承范例导致子类数量爆炸式增长
	//图像文件格式：png,jpg,bmp等

	//（2）将类与类之间的继承关系改为委托关系
	//类与类之间：继承、组合（委托）；
	//文件格式：png、jpg、bmp。 操作系统类型：Windows、Linux、Mac。
	//说明：a)parsefile()其实现代码与具体操作系统类型无关。  b)：draw()：不同的操作系统，用于显示pData的实现代码不同。

	//（3）引入桥接（Bridge）模式
	//不同维度的独立变化，才是能够顺利使用桥接模式的前提。
	//定义：将抽象部分与它的实现部分分离，使他们都可以独立地变化和扩展。
	//a)抽象部分：一般指业务功能，比如ImageFormat类。
	//b)实现部分：一般指具体平台实现，比如ImageOS类。
	//角色
	//(a)Abstraction（抽象部分相关接口）：ImageFormat类
	//(b)RefinedAbstraction（扩充抽象部分接口）：Image_png、Image_jpg、Image_bmp类。
	//(c)Implementor（实现部分相关接口）：ImageOS类
	//(d)ConcreteImplementor（实现部分具体类）：ImageOS_Windows、ImageOS_Linux、ImageOS_Mac类。
	//单一职责原则，开闭原则，组合复用原则，依赖倒置原则。

	//_nmsp1::Image* pImg = new _nmsp1::ImagePng();
	//pImg->Draw("c:\\filename.png");
	//delete pImg;

	_nmsp2::ImageOS* imageOSWindows = new _nmsp2::ImageOSWindows();
	_nmsp2::ImageFormat* imagePng = new _nmsp2::ImagePng(imageOSWindows);
	imagePng->ParseFile("c://test.png");
	delete imagePng;
	delete imageOSWindows;
}
