#include "food.h"
#include <cstdlib>
#include "tools.h"
#include <iostream>
#include "snake.h"

void Food::DrawFood(Snake& csnake){//不完整的数据类型，只有声明，没有具体的实现
	/*利用rand函数获得坐标，并将其范围限制在2-20内，地图内，如果获得的坐标与蛇身重合，则重新获得
	同时每5颗食物就出现一颗限时食物，(限时食物有何作用)*/
	while (true)
	{//通过两个随机数，获得一个随机坐标
		int tmp_x = rand() % 30;//若srand没有被使用，则会出现相同的种子
		int tmp_y = rand() % 30;
		if (tmp_x < 2)tmp_x += 2;
		if (tmp_y < 2)tmp_y += 2;
		bool flag = false;
		//访问友元函数里边的类的问题。宏定义的时候ifndef和define名称错误
		for (auto& point: csnake.snake)//private可以被类外部方法使用？
		{//随机坐标与当前光标重合(蛇身(整个队列))或   者是说与边框坐标？
			if ((point.GetX()==tmp_x&&point.GetY()==tmp_y)||(tmp_x==big_x&&tmp_y==big_y)) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		x = tmp_x;//食物的坐标
		y = tmp_y;
		SetCursorPosition(x,y);//获得产生的随机坐标
		SetColor(13);
		std::cout << "★";
		++cnt;//第五次普通食物的时候，出现限时食物
		cnt %= 5;//对5取模，5次普通食物
		if (cnt == 0)
			DrawBigFood(csnake);//限时食物
		break;
	}
}

void Food::DrawBigFood(Snake& csnake)//绘制限时食物
{
	SetCursorPosition(5,0);
	SetColor(11);
	std::cout << "------------------------------------------";//进度条长度42
	progress_bar = 42;

	while (true)
	{
		int tmp_x = rand() % 30;//取模
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snake)
		{//如果与蛇身重合 或者 与已知食物重合
			if ((point.GetX()==tmp_x && point.GetY()==tmp_y) || (tmp_x==x && tmp_y==y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;//如果存在不合要求的限时食物，则重新获取

		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x,big_y);
		SetCursorPosition(big_x,big_y);
		SetColor(18);
		std::cout << "■";
		big_flag = true;
		flash_flag = true;//闪烁？
		break;
	}
}