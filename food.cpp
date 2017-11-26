#include "food.h"
#include <cstdlib>
#include "tools.h"
#include <iostream>
#include "snake.h"

void Food::DrawFood(Snake& csnake){//���������������ͣ�ֻ��������û�о����ʵ��
	/*����rand����������꣬�����䷶Χ������2-20�ڣ���ͼ�ڣ������õ������������غϣ������»��
	ͬʱÿ5��ʳ��ͳ���һ����ʱʳ�(��ʱʳ���к�����)*/
	while (true)
	{//ͨ����������������һ���������
		int tmp_x = rand() % 30;//��srandû�б�ʹ�ã���������ͬ������
		int tmp_y = rand() % 30;
		if (tmp_x < 2)tmp_x += 2;
		if (tmp_y < 2)tmp_y += 2;
		bool flag = false;
		//������Ԫ������ߵ�������⡣�궨���ʱ��ifndef��define���ƴ���
		for (auto& point: csnake.snake)//private���Ա����ⲿ����ʹ�ã�
		{//��������뵱ǰ����غ�(����(��������))��   ����˵��߿����ꣿ
			if ((point.GetX()==tmp_x&&point.GetY()==tmp_y)||(tmp_x==big_x&&tmp_y==big_y)) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		x = tmp_x;//ʳ�������
		y = tmp_y;
		SetCursorPosition(x,y);//��ò������������
		SetColor(13);
		std::cout << "��";
		++cnt;//�������ͨʳ���ʱ�򣬳�����ʱʳ��
		cnt %= 5;//��5ȡģ��5����ͨʳ��
		if (cnt == 0)
			DrawBigFood(csnake);//��ʱʳ��
		break;
	}
}

void Food::DrawBigFood(Snake& csnake)//������ʱʳ��
{
	SetCursorPosition(5,0);
	SetColor(11);
	std::cout << "------------------------------------------";//����������42
	progress_bar = 42;

	while (true)
	{
		int tmp_x = rand() % 30;//ȡģ
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snake)
		{//����������غ� ���� ����֪ʳ���غ�
			if ((point.GetX()==tmp_x && point.GetY()==tmp_y) || (tmp_x==x && tmp_y==y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;//������ڲ���Ҫ�����ʱʳ������»�ȡ

		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x,big_y);
		SetCursorPosition(big_x,big_y);
		SetColor(18);
		std::cout << "��";
		big_flag = true;
		flash_flag = true;//��˸��
		break;
	}
}