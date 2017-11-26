#ifndef SNAKE_H
#define SNAKE_H


#include <deque>
#include "point.h"
#include "food.h"
class Food;//��������������������ʹ��

class Snake {
public:
	enum Direction {UP,DOWN,LEFT,RIGHT};//ö����������
	Snake() {//���캯��
		snake.emplace_back(14,8);//Point�������ͱ���ľ��ǹ���λ��
		snake.emplace_back(15,8);
		snake.emplace_back(16,8);
		direction = Direction::DOWN;//�����ռ䣿ʹ������ߵķ�����ʱ��
	}
	void InitSnake();
	bool OverEdge();
	bool HitItself();
	bool ChangeDirection();
	bool GetFood(Food &);
	void NormalMove();
	void Move();
private:
	std::deque<Point> snake;//˫�˶���β������ͷ
	Direction direction;
	friend class Food;//��Food������Ϊ��Ԫ���Ա������˽��Ԫ��
};


#endif // !SNAKE_H
