#ifndef SNAKE_H
#define SNAKE_H


#include <deque>
#include "point.h"
#include "food.h"
class Food;//声明。可以在以下类中使用

class Snake {
public:
	enum Direction {UP,DOWN,LEFT,RIGHT};//枚举数据类型
	Snake() {//构造函数
		snake.emplace_back(14,8);//Point数据类型保存的就是光标的位置
		snake.emplace_back(15,8);
		snake.emplace_back(16,8);
		direction = Direction::DOWN;//命名空间？使用类里边的方法的时候？
	}
	void InitSnake();
	bool OverEdge();
	bool HitItself();
	bool ChangeDirection();
	bool GetFood(Food &);
	void NormalMove();
	void Move();
private:
	std::deque<Point> snake;//双端队列尾部是蛇头
	Direction direction;
	friend class Food;//将Food类设置为友元，以便访问其私有元素
};


#endif // !SNAKE_H
