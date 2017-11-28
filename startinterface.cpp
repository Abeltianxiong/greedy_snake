#include "startinterface.h"
#include <iostream>
#include <windows.h>

//#include "tools.h"

void StartInterface::PrintFirst()
{
	for (auto& point : startsnake)//此操作还不太熟练
	{
		point.Print();//Point里边包含了点x,y
		Sleep(speed);
	}

#if 0
	//已经创建过startinterface对象
	for (int i = 0; i < startsnake.size(); i++)
	{
		startsnake[i].Print();//startsnake[i]对象何时创建的？
		Sleep(speed);
	}//  
#endif // 0
}
void StartInterface::PrintSecond()
{
	for (int i=6;i!=40;i++)//i从5开始的
	{//i=39的时候，打印了最后一个，执行清除队首，此时光标移动到i-5的位置
		int j=10;
		startsnake.emplace_back(Point(i,j));//新点入队。直线走，j位置不变
		startsnake.back().Print();//打印的时候，光标在头部
		startsnake.front().Clear();//清除的时候，光标在尾部。通过队列，得到光标
		startsnake.pop_front();
		Sleep(speed);
		//if(i==39)
			//SetCursorPosition(39*2, j);

	}
	
}

void StartInterface::PrintThird()//蛇从接触右边到消失的过程
{
	while (!startsnake.empty()||textsnake.back().GetX()<33)//文本是否到达指定位置33
	{
		if (!startsnake.empty())//清空了双头队列，队首的所有元素
		{
			startsnake.front().Clear();//光标一直在蛇尾和对头之间切换
			startsnake.pop_front();
		}//开始清楚的时候，同时文字也再开始出现
		ClearText();//初始状态textsnake的x坐标都是负值
		PrintText();//绘制更新位置后的文字
		Sleep(speed);
	}//程序不会运行结束
}

void StartInterface::ClearText()
{
	for (auto& point:textsnake)//清除文字的同时，将文字整体右移
	{
		if (point.GetX() >= 0)
			point.Clear();
		//清除1位之后，需要得到新的坐标
		point.ChangePosition(point.GetX()+1,point.GetY());
	}

}

void StartInterface::PrintText() {//文本的坐标也在更新？
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Print();
	}
}

void StartInterface::Action() {
	PrintFirst();
	PrintSecond();//此过程，光标一直在蛇尾。看能否读取到队列，就知道是否被清空了
//	std::cout << std::endl;

	PrintThird();//此时，光标到最开始的位置了
}
