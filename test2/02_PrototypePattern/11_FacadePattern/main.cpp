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
	class Graphic
	{
	private:
		Graphic() {};
		Graphic(const Graphic& tmpobj);
		Graphic& operator=(const Graphic& tmpobj);
		~Graphic() {}
	public:
		static Graphic& GetInstance()
		{
			static Graphic instance;
			return instance;
		}

	public:
		void Display(bool enable)
		{
			cout << "ͼ��->�Ƿ�ȫ����ʾ->" << enable << endl;
		}

		void Effect(bool enable)
		{
			cout << "ͼ��->�Ƿ�����Ч" << enable << endl;
		}

		void Resolution(int index)
		{
			cout << "ͼ��->�ֱ�������ѡ��->" << index << endl;
		}

		void anticaliasing(bool enable)
		{
			cout << "ͼ��->�Ƿ��������" << enable << endl;
		}
	};

	class Sound
	{
	private:
		Sound() {};
		Sound(const Sound& tmpObj);
		Sound& operator=(const Sound& tmpobj);
		~Sound() {};
	public:
		static Sound& GetInstance()
		{
			static Sound instance;
			return instance;
		}

	public:
		void BgSound(bool enable)
		{
			cout << "����->�Ƿ�����������->" << enable << endl;
		}

		void EnvirSound(bool enable)
		{
			cout << "����->�Ƿ���������Ч->" << enable << endl;
		}

		void ExpSound(bool enable)
		{
			cout << "����->�Ƿ�����������->" << enable << endl;
		}

		void SetVolume(int level)
		{
			cout << "����->������СΪ->" << level << endl;
		}
	};

	class ChatVoice
	{
	private:
		ChatVoice() {};
		ChatVoice(const ChatVoice& tmpobj);
		ChatVoice& operator=(const ChatVoice& tmpobj);
		~ChatVoice() {};
	public:
		static ChatVoice& GetInstance()
		{
			static ChatVoice instance;
			return instance;
		}

		void MicVolume(int level)
		{
			cout << "��������->��˷�����Ϊ->" << level << endl;
		}

		void MicSens(int level)
		{
			cout << "��������->��˷�������Ϊ->" << level << endl;
		}

		void ChatVolume(int level)
		{
			cout << "��������->��������Ϊ->" << level << endl;
		}
	};

	// �������ģʽ��ɫ����
	class ConfFacade
	{
	private:
		ConfFacade() {}
		ConfFacade(const ConfFacade& tempobj);
		ConfFacade& operator=(const ConfFacade& tempobj);
		~ConfFacade() {}
	public:
		static ConfFacade& GetInstance()
		{
			static ConfFacade instance;
			return instance;
		}

	public:
		// ���ڵ�����ԣ�ֻ����һЩ������ѡ��
		// �о����£�Ҳ��Ҫһ��������á���Ȼ�����еĶ���¶���û�ʹ�ã��Ƚ��鷳
		void LowConfComuter()
		{
			Graphic& g_pg = Graphic::GetInstance();
			g_pg.Display(true);
			g_pg.Effect(false);
			g_pg.Resolution(2);
			g_pg.anticaliasing(false);

			Sound& g_snd = Sound::GetInstance();
			g_snd.BgSound(false);
			g_snd.EnvirSound(false);
			g_snd.ExpSound(false);
			g_snd.SetVolume(15);

			ChatVoice& g_cv = ChatVoice::GetInstance();
			g_cv.MicVolume(20);
			g_cv.MicSens(50);
			g_cv.ChatVolume(60);
		}

		void HightConfComputer()
		{
			Graphic& g_pg = Graphic::GetInstance();
			g_pg.Display(false);
			g_pg.Effect(true);
			g_pg.Resolution(0);
			g_pg.anticaliasing(true);

			Sound& g_snd = Sound::GetInstance();
			g_snd.BgSound(true);
			g_snd.EnvirSound(true);
			g_snd.ExpSound(true);
			g_snd.SetVolume(50);

			ChatVoice& g_cv = ChatVoice::GetInstance();
			g_cv.MicVolume(100);
			g_cv.MicSens(100);
			g_cv.ChatVolume(100);
		}
	};

}

namespace _nmsp2
{
	class Screen
	{
	public:
		void On()
		{
			cout << "��Ļ����" << endl;
		}
		void Off()
		{
			cout << "��Ļ�ر���" << endl;
		}
	};

	class Light
	{
	public:
		void On()
		{
			cout << "�ƹ����" << endl;
		}
		void Off()
		{
			cout << "�ƹ�ر���" << endl;
		}
	};

	class Speaker
	{
	public:
		void On()
		{
			cout << "��˷����" << endl;
		}
		void Off()
		{
			cout << "��˷�ر���" << endl;
		}
	};

	class DvdPlayer
	{
	public:
		void On()
		{
			cout << "DVD����" << endl;
		}
		void Off()
		{
			cout << "DVD�ر���" << endl;
		}
	};

	class PlayerStation
	{
	public:
		void On()
		{
			cout << "��Ϸ������" << endl;
		}
		void Off()
		{
			cout << "��Ϸ���ر���" << endl;
		}
	};

	class HomeTheaterFacade
	{
	public:
		void WatchMovie()
		{
			m_screen.On();
			m_light.Off();
			m_speaker.On();
			m_dvdPlayer.On();
			m_playerStation.Off();
		}

		void PlayGame()
		{
			m_screen.On();
			m_light.On();
			m_speaker.On();
			m_dvdPlayer.Off();
			m_playerStation.On();
		}

	private:
		Screen				m_screen;
		Light				m_light;
		Speaker				m_speaker;
		DvdPlayer			m_dvdPlayer;
		PlayerStation		m_playerStation;

	};
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��8�� ��ۣ�facade��ģʽ:����ģʽ���ṹ��ģʽ��Ŀ�ģ�����ӿڡ����м�㡣�����ط���
	//��1��һ��������صķ���
	//��2��������ۣ�facade��ģʽ
	//graphic��sound��chatvoice����ҵ���� conffacade
	//���ģʽǿ������һ�ֳ������˼��
	//���ģʽ������������������Ƶ�һ��ԭ�򡪡������ط���Law of Demeter�����LoD����
		 //��ī߯�����������С֪ʶԭ��Least Knowledge Principle�����LKP����
		   //һ������Ӧ�ö��������󾡿����ٵ��˽⣬�Ӷ����͸�������֮�����ϣ����ϵͳ��ά���ԡ�
	//���ģʽ����2�ֽ�ɫ
	//a)Facade����۽�ɫ����conffacade
	//b)Subsystem����ϵͳ��ɫ����graphic��sound��chatvoice����ҵ����

	//������ģʽ�Ķ��壨ʵ����ͼ�����ṩ��һ��ͳһ�Ľӿڣ�����������ϵͳ�е�һȺ�ӿڡ���۶�����һ���߲�ӿڣ�����ϵͳ������ʹ�á�
	//���ģʽΪ�ͻ��˺���ϵͳ֮���ṩ��һ�ּ򻯵Ľ����������� ��û��Ϊ��ϵͳ�����µ���Ϊ�����ϣ����������Ϊ��Ӧ��ͨ���޸���ϵͳ��ɫ��ʵ�֡�
	//��3����һ�����ģʽ�ķ���
	//��ͥӰԺ���ģʽ�ࣺHomeTheaterFacade,�����豸����
	//a)��ĻScreen��b)�ƹ�Light��c)����Speaker��d)DVD������DvdPlayer��e)��Ϸ��PlayerStation��
	//�ṩ�����ӿڣ�
	//a)����Ӱģʽ��WatchMovie������Ļ�򿪣��ƹ�Ϩ������򿪣�DVD�������򿪣���Ϸ���رա�
	//b)����Ϸģʽ��PlayGame������Ļ�򿪣��ƹ�򿪣�����򿪣�DVD�������رգ���Ϸ���򿪡�
	
	/*_nmsp1::ConfFacade& facade = _nmsp1::ConfFacade::GetInstance();
	facade.LowConfComuter();
	facade.HightConfComputer();*/

	_nmsp2::HomeTheaterFacade* homeTheaterFacade = new _nmsp2::HomeTheaterFacade();
	homeTheaterFacade->PlayGame();
	homeTheaterFacade->WatchMovie();

	delete homeTheaterFacade;

}
