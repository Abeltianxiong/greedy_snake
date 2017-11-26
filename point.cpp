#include "point.h"
#include "tools.h"

void Point::Print()
{
	SetCursorPosition(x,y);
	std::cout << "■";//一个方框占两个字节
}

void Point::PrintCircular()
{
	SetCursorPosition(x,y);
	std::cout << "●";
}

void Point::Clear()//通过队列，得到光标
{
	SetCursorPosition(x, y);
	std::cout << "  ";//一个方框占两个字节
}

void Point::ChangePosition(const int x,const int y)
{
	this->x = x;
	this->y = y;
}