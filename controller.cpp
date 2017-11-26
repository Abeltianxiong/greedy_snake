#include "controller.h"

//同一个类里边的方法，可以相互调用
void Controller::Game()
{
	Start();//开始界面
	while (true)
	{
		Select();//选择界面
		DrawGame();//绘制游戏界面

		int tmp = PlayGame();
		//根据游戏结果，选择操作
		if (tmp==1)
		{
			system("cls");
			continue;
		}
		else if (tmp==2)
		{
			break;
		}
		else 
		{
			break;
		}
		
	}
}
void Controller::Start()
{
	//SetWindowSize(41,32);//设置cmd窗口函数tools.cpp中
	SetColor(2);

	StartInterface *start = new StartInterface();//start指针只想新开辟的空间
	start->Action();
	//start->test();//为何打印一下就。该打印是只有一个
	delete start;//释放掉创建的初始化的空间

	/*设置光标位置，并输出提示语，等待任意键输入结束*/
	SetCursorPosition(13,26);
	std::cout << "Press any key to start... ";
	//std::cout << std::endl;
	SetCursorPosition(13, 27);
	system("pause");//正常清空，程序结束，也会执行该命令
	
//	std:: cout << std::endl;
}
//游戏模式选择
void Controller::Select()
{
	/*初始化操作界面*/
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                         ";
	//std::cout << std::endl;
	SetCursorPosition(13, 27);
	std::cout << "                         ";

	//清空之前打印的文字
	SetCursorPosition(6,21);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(6,22);
	std::cout << "(上下键选择，回车确认)";
	SetCursorPosition(27,22);
	SetBackColor();//设置选中背景
	std::cout << "简单模式";
	SetColor(3);//重新设置前景颜色
	SetCursorPosition(27, 24);
	std::cout << "普通模式";

	SetCursorPosition(27, 26);
	std::cout << "困难模式";

	SetCursorPosition(27, 28);
	std::cout << "炼狱模式";

	SetCursorPosition(0,31);//光标回到后行首位
	score = 0;//

	int ch;
	key = 1;
	bool flag = false;

	while ((ch=_getch()))
	{
		//std::cout << ch << std::endl;??
		switch (ch)
		{
		case 72://UP224？
			if (key>1)
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "简单模式";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";

					key--;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";

					key--;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "炼狱模式";

					key--;
					break;
				}
			
			}

			break;
		case 80://DOWN下方向键
			if (key<4)
			{
				switch (key)
				{
				case 1://有简单模式到普通模式
					SetCursorPosition(27, 24);
					SetBackColor();//设置选中背景
					std::cout << "普通模式";
					SetCursorPosition(27,22);
					SetColor(3);
					std::cout << "简单模式";
					key++;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();//设置选中背景
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";
					key++;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();//设置选中背景
					std::cout << "炼狱模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";
					key++;
					break;
				}
			}
			break;
		case 13://按下enter键 //结束键盘输入
			flag = true;
			break;
		default:
			break;

		}
		if (flag)break;
		SetCursorPosition(0, 30);
	}
	//key=1,2,3,4分别表示游戏的四种模式
	switch (key)
	{
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 100;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 40;
		break;
	default:
		break;
	}
}

void Controller::DrawGame()
{
	system("cls");
	//
	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	/*绘制左侧边栏*/
	SetColor(3);
	SetCursorPosition(33,1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34,2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度：";
	SetCursorPosition(36, 4);
	switch (key)
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "越狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31,7);
	std::cout << "得分：";
	SetCursorPosition(37,7);
	std::cout << " 0";
	SetCursorPosition(33,13);
	std::cout << "方向键移动";
	SetCursorPosition(33,15);
	std::cout << "ESC键暂停";


}

int Controller::PlayGame()
{//至此，核心功能已经实现，只需要完善功能即可
	/*初始化蛇和食物*/
	Snake *csnake = new Snake();
	Food *cfood = new Food();
	SetColor(6);//蛇的颜色
	csnake->InitSnake();//将Snake类里边的蛇画出来了
	srand((unsigned)time(NULL));//设置随机数种子 rand()函数得到的随机数
	cfood->DrawFood(*csnake);//包括普通食物和限时食物（参数csnake是要确定食物和蛇身的关系）

	//最先执行的是正常移动这段代码
	while (csnake->OverEdge() && csnake->HitItself())//判断蛇是否撞墙或者自身
	{//蛇的生命存在是继续执行
		/*调出选择菜单*/
		if (!csnake->ChangeDirection())//按下ESC键或者是方向键
		{//该条件语句里边实现的暂停功能

		}//假设方向键和ESC没有按下

		if (csnake->GetFood(*cfood))//吃到食物,暂停了？
		{//之前蛇身的位子，被星星给取代了
			//吃到食物之后，重新确定食物的状态，避免跟之前的重复
			cfood->DrawFood(*csnake);//参数规定，不能够与蛇重复

		}//吃到食物之后没有清空这种状态。该while循环中一直在判断这种状态
		else {//没有吃到食物，蛇正常移动
			csnake->NormalMove();//移动的时候没有延时？
		}


		Sleep(speed);//延时，蛇移动效果

	}



	return 0;
}