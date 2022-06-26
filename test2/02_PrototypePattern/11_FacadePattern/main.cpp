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
			cout << "图形->是否全屏显示->" << enable << endl;
		}

		void Effect(bool enable)
		{
			cout << "图形->是否开启特效" << enable << endl;
		}

		void Resolution(int index)
		{
			cout << "图形->分辨率设置选项->" << index << endl;
		}

		void anticaliasing(bool enable)
		{
			cout << "图形->是否开启抗锯齿" << enable << endl;
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
			cout << "声音->是否开启背景音乐->" << enable << endl;
		}

		void EnvirSound(bool enable)
		{
			cout << "声音->是否开启环境音效->" << enable << endl;
		}

		void ExpSound(bool enable)
		{
			cout << "声音->是否开启表情声音->" << enable << endl;
		}

		void SetVolume(int level)
		{
			cout << "声音->音量大小为->" << level << endl;
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
			cout << "语音聊天->麦克风音量为->" << level << endl;
		}

		void MicSens(int level)
		{
			cout << "语音聊天->麦克风灵敏度为->" << level << endl;
		}

		void ChatVolume(int level)
		{
			cout << "语音聊天->聊天音量为->" << level << endl;
		}
	};

	// 扮演外观模式角色的类
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
		// 对于低配电脑，只开启一些低配置选项
		// 感觉伴侣，也需要一套这个配置。不然把所有的都暴露给用户使用，比较麻烦
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
			cout << "屏幕打开了" << endl;
		}
		void Off()
		{
			cout << "屏幕关闭了" << endl;
		}
	};

	class Light
	{
	public:
		void On()
		{
			cout << "灯光打开了" << endl;
		}
		void Off()
		{
			cout << "灯光关闭了" << endl;
		}
	};

	class Speaker
	{
	public:
		void On()
		{
			cout << "麦克风打开了" << endl;
		}
		void Off()
		{
			cout << "麦克风关闭了" << endl;
		}
	};

	class DvdPlayer
	{
	public:
		void On()
		{
			cout << "DVD打开了" << endl;
		}
		void Off()
		{
			cout << "DVD关闭了" << endl;
		}
	};

	class PlayerStation
	{
	public:
		void On()
		{
			cout << "游戏机打开了" << endl;
		}
		void Off()
		{
			cout << "游戏机关闭了" << endl;
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	//第8章 外观（facade）模式:门面模式，结构型模式。目的：隔离接口——中间层。迪米特法则
	//（1）一个配置相关的范例
	//（2）引入外观（facade）模式
	//graphic、sound、chatvoice——业务类 conffacade
	//外观模式强调的是一种程序设计思想
	//外观模式体现了面向对象程序设计的一个原则——迪米特法则（Law of Demeter，简称LoD）。
		 //得墨忒耳法则或者最小知识原则（Least Knowledge Principle，简称LKP）：
		   //一个对象应该对其他对象尽可能少的了解，从而降低各个对象之间的耦合，提高系统可维护性。
	//外观模式包含2种角色
	//a)Facade（外观角色）：conffacade
	//b)Subsystem（子系统角色）：graphic、sound、chatvoice——业务类

	//外观设计模式的定义（实现意图）：提供了一个统一的接口，用来访问子系统中的一群接口。外观定义了一个高层接口，让子系统更容易使用。
	//外观模式为客户端和子系统之间提供了一种简化的交互渠道但是 并没有为子系统增加新的行为。如果希望增加新行为，应该通过修改子系统角色来实现。
	//（3）另一个外观模式的范例
	//家庭影院外观模式类：HomeTheaterFacade,电器设备关联
	//a)屏幕Screen；b)灯光Light；c)音箱Speaker；d)DVD播放器DvdPlayer；e)游戏机PlayerStation。
	//提供两个接口：
	//a)看电影模式（WatchMovie）：屏幕打开，灯光熄灭，音箱打开，DVD播放器打开，游戏机关闭。
	//b)玩游戏模式（PlayGame）：屏幕打开，灯光打开，音箱打开，DVD播放器关闭，游戏机打开。
	
	/*_nmsp1::ConfFacade& facade = _nmsp1::ConfFacade::GetInstance();
	facade.LowConfComuter();
	facade.HightConfComputer();*/

	_nmsp2::HomeTheaterFacade* homeTheaterFacade = new _nmsp2::HomeTheaterFacade();
	homeTheaterFacade->PlayGame();
	homeTheaterFacade->WatchMovie();

	delete homeTheaterFacade;

}
