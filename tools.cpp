#include "tools.h"

void SetWindowSize(int cols,int lines)
{
	system("title ̰����");
	char cmd[30];
	sprintf(cmd,"mode con cols=%d lines=%d",cols*2,lines);
	system(cmd);//���ڵ��������������
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
							BACKGROUND_RED);//��һ���������ı���ɫ��������������Ǳ�����ɫ
}

//���ù��λ��
void SetCursorPosition(const int x,const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}


