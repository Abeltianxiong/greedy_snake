#ifndef POINT_H
#define POINT_H

class Point {//Point����ķ���
public:
	Point() { }
	Point(const int x, const int y) :x(x),y(y){}//ͨ���������캯����private���Եı��� x = x;y=y
	void Print();
	void Clear();
	void Point::ChangePosition(const int x, const int y);
	void PrintCircular();

	int GetX() { return this->x; }//��ǰ����x��
	int GetY() { return this->y; }

private:
	int x;//������ǹ�������
	int y;

};

#endif