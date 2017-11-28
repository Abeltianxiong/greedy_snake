#ifndef FOOD_H
#define FOOD_H



#include "snake.h"




//û��ʹ�õ�snake.h��ߵ�ͷ�ļ���
class Snake;//����������һ�ֲ���������������

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
	bool flash_flag;//��˸���
	bool big_flag;//�Ƿ�����ʱʳ����
	int x, y;//��ͨʳ������
	int big_x, big_y;//��ʱʳ������
	int progress_bar;//��ʱʳ�������
	friend class Snake;//ͬʱҲ��snake������Ϊ����Ԫ��food��Ҳ�ܹ�����snake��private��Ԫ��
};

#endif // !FOOD_H
