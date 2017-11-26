#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include "point.h"
#include <vector>
#include <deque>

class StartInterface {
public:
	StartInterface() {
		speed=50;
		startsnake.emplace_back(Point(0,10));//与push_back()功能一样，应该是emplace_back效率更高
		startsnake.emplace_back(Point(1, 10));
		startsnake.emplace_back(Point(2, 10));
		startsnake.emplace_back(Point(3, 10));
		startsnake.emplace_back(Point(4, 10));
		startsnake.emplace_back(Point(5, 10));

		textsnake.emplace_back(Point(-26, 14));//S
		textsnake.emplace_back(Point(-25, 14));
		textsnake.emplace_back(Point(-27, 15));
		textsnake.emplace_back(Point(-26, 16));
		textsnake.emplace_back(Point(-25, 17));
		textsnake.emplace_back(Point(-27, 18));
		textsnake.emplace_back(Point(-26, 18));

		textsnake.emplace_back(Point(-23, 14));//N
		textsnake.emplace_back(Point(-23, 15));
		textsnake.emplace_back(Point(-23, 16));
		textsnake.emplace_back(Point(-23, 17));
		textsnake.emplace_back(Point(-23, 18));
		textsnake.emplace_back(Point(-22, 15));
		textsnake.emplace_back(Point(-21, 16));
		textsnake.emplace_back(Point(-20, 17));
		textsnake.emplace_back(Point(-19, 14));
		textsnake.emplace_back(Point(-19, 15));
		textsnake.emplace_back(Point(-19, 16));
		textsnake.emplace_back(Point(-19, 17));
		textsnake.emplace_back(Point(-19, 18));

		textsnake.emplace_back(Point(-17, 18));//A
		textsnake.emplace_back(Point(-16, 17));
		textsnake.emplace_back(Point(-15, 16));
		textsnake.emplace_back(Point(-14, 15));
		textsnake.emplace_back(Point(-14, 16));
		textsnake.emplace_back(Point(-13, 14));
		textsnake.emplace_back(Point(-13, 16));
		textsnake.emplace_back(Point(-12, 15));
		textsnake.emplace_back(Point(-12, 16));
		textsnake.emplace_back(Point(-11, 16));
		textsnake.emplace_back(Point(-10, 17));
		textsnake.emplace_back(Point(-9, 18));

		textsnake.emplace_back(Point(-7, 14));//K
		textsnake.emplace_back(Point(-7, 15));
		textsnake.emplace_back(Point(-7, 16));
		textsnake.emplace_back(Point(-7, 17));
		textsnake.emplace_back(Point(-7, 18));
		textsnake.emplace_back(Point(-6, 16));
		textsnake.emplace_back(Point(-5, 15));
		textsnake.emplace_back(Point(-5, 17));
		textsnake.emplace_back(Point(-4, 14));
		textsnake.emplace_back(Point(-4, 18));

		textsnake.emplace_back(Point(-2, 14));//E
		textsnake.emplace_back(Point(-2, 15));
		textsnake.emplace_back(Point(-2, 16));
		textsnake.emplace_back(Point(-2, 17));
		textsnake.emplace_back(Point(-2, 18));
		textsnake.emplace_back(Point(-1, 14));
		textsnake.emplace_back(Point(-1, 16));
		textsnake.emplace_back(Point(-1, 18));
		textsnake.emplace_back(Point(0, 14));
		textsnake.emplace_back(Point(0, 16));
		textsnake.emplace_back(Point(0, 18));

	}
	void Action();
	void PrintFirst();
	void PrintSecond();
	void PrintThird();
	void ClearText();
	void PrintText();

	void test() { startsnake.back().Print(); };
private:
	std::deque<Point> startsnake;//创建StartInterface对象就创建Point对象？
	std::vector<Point> textsnake;
	int speed;
//该对象是类私有，只能怪通过该类的方法得到

};








#endif