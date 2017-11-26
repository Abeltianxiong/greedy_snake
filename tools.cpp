#include "tools.h"

void SetWindowSize(int cols,int lines)
{
	system("title 贪吃蛇");
	char cmd[30];
	sprintf(cmd,"mode con cols=%d lines=%d",cols*2,lines);
	system(cmd);//窗口调整命令发生错误了
}
void SetColor(int colorID) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorID);
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
							FOREGROUND_BLUE |
							BACKGROUND_BLUE |
							BACKGROUND_GREEN |
							BACKGROUND_RED);//第一个参数是文本颜色，后边三个参数是背景颜色
}

//设置光标位置
void SetCursorPosition(const int x,const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}


