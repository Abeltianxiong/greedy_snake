#include "snake.h"
#include <iostream>
//#include "point.h"
#include <conio.h>
#include "tools.h"

void Snake::InitSnake()//初始化蛇
{
	for (auto& point:snake)//访问point队列里边的元素，改变了光标位置
	{
		point.PrintCircular();
	}
}

bool Snake::OverEdge()//在边界范围内，
{
	return  snake.back().GetX() < 30 &&
			snake.back().GetY() < 30 &&
			snake.back().GetX() > 1  &&
			snake.back().GetY() > 1;
}

bool Snake::HitItself()
{
	std::deque<Point>::size_type cnt = 1;//?
	Point *head = new Point(snake.back().GetX(),snake.back().GetY());//指向蛇头坐标
	for (auto& point : snake)
	{
		if (head->GetX() == point.GetX() && head->GetY() == point.GetY())//?运算符没有重载？ !(point == *head)
			break;
		else
			++cnt;
	}
	delete head;
	if (cnt==snake.size())
		return true;//没有碰到蛇身
	else
		return false;
}

bool Snake::ChangeDirection()//改变方向
{
	char ch;
	if (_kbhit())//非阻塞的响应键盘
	{//使用方向键，改变蛇的移动过程
		ch = _getch();
		switch (ch)
		{
		case -32://?
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction!=Direction::DOWN)//如果由相反方向改变蛇身的运动方向，则会导致蛇的死亡
					direction = Direction::UP;
				break;
			case 80:
				if (direction != Direction::UP)//如果由相反方向改变蛇身的运动方向，则会导致蛇的死亡
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)//如果由相反方向改变蛇身的运动方向，则会导致蛇的死亡
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)//如果由相反方向改变蛇身的运动方向，则会导致蛇的死亡
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;

		case 27:
			return false;
		default:
			return true;
		}
	}
	return true;

}


bool Snake::GetFood(Food & cfood)//
{//双头队列尾部就是蛇头部
	if (snake.back().GetX()==cfood.x && snake.back().GetY()== cfood.y)
		return true;
	else
		return false;
}

void Snake::Move()
{//初始状态的移动方向是向下
	switch (direction)
	{
	case Direction::UP://对应的枚举类型
		snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()-1));
		break;//蛇头在下方向？转变之后，与蛇身重合
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()+1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX()-1,snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
	default:
		break;
	}
	SetColor(14);
	snake.back().PrintCircular();
}

void Snake::NormalMove()//蛇正常移动，头增长，尾缩短
{
	Move();//双头队列的尾部增加
	snake.front().Clear();//双头队列的头部，就是蛇的尾部
	snake.pop_front();
}