#ifndef POINT_H
#define POINT_H

class Point {//Point对象的方法
public:
	Point() { }
	Point(const int x, const int y) :x(x),y(y){}//通过解析构造函数，private属性的变量 x = x;y=y
	void Print();
	void Clear();
	void Point::ChangePosition(const int x, const int y);
	void PrintCircular();

	int GetX() { return this->x; }//当前光标的x轴
	int GetY() { return this->y; }

private:
	int x;//保存的是光标的坐标
	int y;

};

#endif