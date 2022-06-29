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
	class Image
	{
	public:
		void Draw(const char* pFileName)
		{
			int iLen = 0;
			char* pData = ParseFile(pFileName, iLen);
			if (iLen > 0)
			{
				cout << "��ʾpData��ָ��Ļ������е�ͼ������" << endl;
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
			cout << "��ʼ���� png �ļ��е����ݲ��������ṹ�ŵ� pData �С�";
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
			cout << "��ʼ���� jpg �ļ��е����ݲ��������ṹ�ŵ� pData �С�";
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
			cout << "��ʼ���� bmp �ļ��е����ݲ��������ṹ�ŵ� pData �С�";
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
			cout << "�� Windows ����ϵͳ����ʾ pData ��ָ��Ļ������е�ͼ����" << endl;
		}
	};

	class ImageOSLinux :public ImageOS
	{
	public:
		void Draw(char* pData, int iLen)
		{
			cout << "�� Linux ����ϵͳ����ʾ pData ��ָ��Ļ������е�ͼ����" << endl;
		}
	};

	class ImageOSMac :public ImageOS
	{
	public:
		void Draw(char* pData, int iLen)
		{
			cout << "�� Mac ����ϵͳ����ʾ pData ��ָ��Ļ������е�ͼ����" << endl;
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
			cout << "��ʼ���� png �ļ��е����ݲ�������ŵ� pData ��" << endl;
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
			cout << "��ʼ���� jpg �ļ��е����ݲ�������ŵ� pData ��" << endl;
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
			cout << "��ʼ���� bmp �ļ��е����ݲ�������ŵ� pData ��" << endl;
			int iLen = 100;
			char* presult = new char[iLen];
			m_pImage->Draw(presult, iLen);
			delete presult;
		}
	};
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��16�� �Žӣ�Bridge��ģʽ������ģʽ����ģʽ�����ṹ��ģʽ��
	//��������⣺���ݵ�һְ��ԭ����һ�����У���Ҫ��̫�����飬�������ܶ࣬������ֵ��������ȥ��Ȼ����
	  //һ�����а���ָ������һ��������ָ�룬����Ҫִ������һ�����еĶ���ʱ����ָ��ֱ��ȥ��������һ����ĳ�Ա������
	  // 
	//��1��һ����ͳ�ļ̳з�����������������ըʽ����
	//ͼ���ļ���ʽ��png,jpg,bmp��

	//��2����������֮��ļ̳й�ϵ��Ϊί�й�ϵ
	//������֮�䣺�̳С���ϣ�ί�У���
	//�ļ���ʽ��png��jpg��bmp�� ����ϵͳ���ͣ�Windows��Linux��Mac��
	//˵����a)parsefile()��ʵ�ִ�����������ϵͳ�����޹ء�  b)��draw()����ͬ�Ĳ���ϵͳ��������ʾpData��ʵ�ִ��벻ͬ��

	//��3�������Žӣ�Bridge��ģʽ
	//��ͬά�ȵĶ����仯�������ܹ�˳��ʹ���Ž�ģʽ��ǰ�ᡣ
	//���壺�����󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ر仯����չ��
	//a)���󲿷֣�һ��ָҵ���ܣ�����ImageFormat�ࡣ
	//b)ʵ�ֲ��֣�һ��ָ����ƽ̨ʵ�֣�����ImageOS�ࡣ
	//��ɫ
	//(a)Abstraction�����󲿷���ؽӿڣ���ImageFormat��
	//(b)RefinedAbstraction��������󲿷ֽӿڣ���Image_png��Image_jpg��Image_bmp�ࡣ
	//(c)Implementor��ʵ�ֲ�����ؽӿڣ���ImageOS��
	//(d)ConcreteImplementor��ʵ�ֲ��־����ࣩ��ImageOS_Windows��ImageOS_Linux��ImageOS_Mac�ࡣ
	//��һְ��ԭ�򣬿���ԭ����ϸ���ԭ����������ԭ��

	//_nmsp1::Image* pImg = new _nmsp1::ImagePng();
	//pImg->Draw("c:\\filename.png");
	//delete pImg;

	_nmsp2::ImageOS* imageOSWindows = new _nmsp2::ImageOSWindows();
	_nmsp2::ImageFormat* imagePng = new _nmsp2::ImagePng(imageOSWindows);
	imagePng->ParseFile("c://test.png");
	delete imagePng;
	delete imageOSWindows;
}
