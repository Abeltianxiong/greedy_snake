#include "snake.h"
#include <iostream>
//#include "point.h"
#include <conio.h>
#include "tools.h"

void Snake::InitSnake()//��ʼ����
{
	for (auto& point:snake)//����point������ߵ�Ԫ�أ��ı��˹��λ��
	{
		point.PrintCircular();
	}
}

bool Snake::OverEdge()//�ڱ߽緶Χ�ڣ�
{
	return  snake.back().GetX() < 30 &&
			snake.back().GetY() < 30 &&
			snake.back().GetX() > 1  &&
			snake.back().GetY() > 1;
}

bool Snake::HitItself()
{
	std::deque<Point>::size_type cnt = 1;//?
	Point *head = new Point(snake.back().GetX(),snake.back().GetY());//ָ����ͷ����
	for (auto& point : snake)
	{
		if (head->GetX() == point.GetX() && head->GetY() == point.GetY())//?�����û�����أ� !(point == *head)
			break;
		else
			++cnt;
	}
	delete head;
	if (cnt==snake.size())
		return true;//û����������
	else
		return false;
}

bool Snake::ChangeDirection()//�ı䷽��
{
	char ch;
	if (_kbhit())//����������Ӧ����
	{//ʹ�÷�������ı��ߵ��ƶ�����
		ch = _getch();
		switch (ch)
		{
		case -32://?
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction!=Direction::DOWN)//������෴����ı�������˶�������ᵼ���ߵ�����
					direction = Direction::UP;
				break;
			case 80:
				if (direction != Direction::UP)//������෴����ı�������˶�������ᵼ���ߵ�����
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)//������෴����ı�������˶�������ᵼ���ߵ�����
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)//������෴����ı�������˶�������ᵼ���ߵ�����
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
{//˫ͷ����β��������ͷ��
	if (snake.back().GetX()==cfood.x && snake.back().GetY()== cfood.y)
		return true;
	else
		return false;
}

void Snake::Move()
{//��ʼ״̬���ƶ�����������
	switch (direction)
	{
	case Direction::UP://��Ӧ��ö������
		snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()-1));
		break;//��ͷ���·���ת��֮���������غ�
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

void Snake::NormalMove()//�������ƶ���ͷ������β����
{
	Move();//˫ͷ���е�β������
	snake.front().Clear();//˫ͷ���е�ͷ���������ߵ�β��
	snake.pop_front();
}