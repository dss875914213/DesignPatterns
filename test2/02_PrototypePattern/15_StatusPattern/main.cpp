#include<iostream>
#include<string>
#include "Monster.h"

using namespace std;

#ifdef _DEBUG   //ֻ��Debug�����ԣ�ģʽ��
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //���¶���new�����
#define new DEBUG_NEW
#endif
#endif

namespace _nmsp1
{

}

namespace _nmsp2
{

}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�����˳�ʱ����ڴ�й©����ʾ�������������
	//��12�� ״̬��State��ģʽ����Ϊ�ͣ�����״̬��
	//״̬ģʽ��ͻ���ص㣺��������ʾ״̬��������ģʽ����������ʾ���ԣ�
	//��1��һ��������״̬ת������
	//����״̬����Finite State Mache����д��FSM�������״̬����
	  //��ĳ���¼���ת������������ʱ������ݵ�ǰ״̬������ִ�����ֶ�����Ȼ�������һ��״̬��
	//Լ������������ 500��
	  //a) ����Ѫ�� > 400 ������->�׺�������
	  //b) ����Ѫ�� <= 400�� > 100������->����������������������������֧Ԯ
	  //c) ����Ѫ�� <= 100������->�־壬����
	  //d) ����Ѫ�� <= 0������->�����������ٱ����ǹ���
	//״̬��Ĵ��ڼ�ֵ��ʹҵ���߼������������������ά����

	Monster monster(500);
	monster.Attacked(20);
	monster.Attacked(100);
	monster.Attacked(200);
	monster.Attacked(50);
	monster.Attacked(100);
	monster.Attacked(100);
}
