#include "point.h"
#include "tools.h"

void Point::Print()
{
	SetCursorPosition(x,y);
	std::cout << "��";//һ������ռ�����ֽ�
}

void Point::PrintCircular()
{
	SetCursorPosition(x,y);
	std::cout << "��";
}

void Point::Clear()//ͨ�����У��õ����
{
	SetCursorPosition(x, y);
	std::cout << "  ";//һ������ռ�����ֽ�
}

void Point::ChangePosition(const int x,const int y)
{
	this->x = x;
	this->y = y;
}