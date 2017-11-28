#ifndef FOOD_H
#define FOOD_H



#include "snake.h"




//没有使用到snake.h里边的头文件？
class Snake;//声明，就是一种不完整的数据类型

class Food {
public:
	Food() :cnt(0),flash_flag(false),big_flag(false),x(0),y(0),big_x(0),big_y(0),progress_bar(0) {}
	void DrawFood(Snake& csnake);//csnake
	void DrawBigFood(Snake& csnake);
	int GetProgressBar();
	bool GetBigFlag();
	void FlashBigFood();
private:
	int cnt;
	bool flash_flag;//闪烁标记
	bool big_flag;//是否有限时食物标记
	int x, y;//普通食物坐标
	int big_x, big_y;//限时食物坐标
	int progress_bar;//限时食物进度条
	friend class Snake;//同时也将snake类设置为了友元，food类也能够访问snake中private的元素
};

#endif // !FOOD_H
