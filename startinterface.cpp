#include "startinterface.h"
#include <iostream>
#include <windows.h>

//#include "tools.h"

void StartInterface::PrintFirst()
{
	for (auto& point : startsnake)//�˲�������̫����
	{
		point.Print();//Point��߰����˵�x,y
		Sleep(speed);
	}

#if 0
	//�Ѿ�������startinterface����
	for (int i = 0; i < startsnake.size(); i++)
	{
		startsnake[i].Print();//startsnake[i]�����ʱ�����ģ�
		Sleep(speed);
	}//  
#endif // 0
}
void StartInterface::PrintSecond()
{
	for (int i=6;i!=40;i++)//i��5��ʼ��
	{//i=39��ʱ�򣬴�ӡ�����һ����ִ��������ף���ʱ����ƶ���i-5��λ��
		int j=10;
		startsnake.emplace_back(Point(i,j));//�µ���ӡ�ֱ���ߣ�jλ�ò���
		startsnake.back().Print();//��ӡ��ʱ�򣬹����ͷ��
		startsnake.front().Clear();//�����ʱ�򣬹����β����ͨ�����У��õ����
		startsnake.pop_front();
		Sleep(speed);
		//if(i==39)
			//SetCursorPosition(39*2, j);

	}
	
}

void StartInterface::PrintThird()//�ߴӽӴ��ұߵ���ʧ�Ĺ���
{
	while (!startsnake.empty()||textsnake.back().GetX()<33)//�ı��Ƿ񵽴�ָ��λ��33
	{
		if (!startsnake.empty())//�����˫ͷ���У����׵�����Ԫ��
		{
			startsnake.front().Clear();//���һֱ����β�Ͷ�ͷ֮���л�
			startsnake.pop_front();
		}//��ʼ�����ʱ��ͬʱ����Ҳ�ٿ�ʼ����
		ClearText();//��ʼ״̬textsnake��x���궼�Ǹ�ֵ
		PrintText();//���Ƹ���λ�ú������
		Sleep(speed);
	}//���򲻻����н���
}

void StartInterface::ClearText()
{
	for (auto& point:textsnake)//������ֵ�ͬʱ����������������
	{
		if (point.GetX() >= 0)
			point.Clear();
		//���1λ֮����Ҫ�õ��µ�����
		point.ChangePosition(point.GetX()+1,point.GetY());
	}

}

void StartInterface::PrintText() {//�ı�������Ҳ�ڸ��£�
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Print();
	}
}

void StartInterface::Action() {
	PrintFirst();
	PrintSecond();//�˹��̣����һֱ����β�����ܷ��ȡ�����У���֪���Ƿ������
//	std::cout << std::endl;

	PrintThird();//��ʱ����굽�ʼ��λ����
}
