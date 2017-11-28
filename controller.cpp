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
			continue;//重新开始
		}
		else if (tmp==2)
		{//退出游戏
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

int Controller::Menu() {
	/*绘制菜单*/
	SetColor(11);
	SetCursorPosition(32,19);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34,21);
	SetBackColor();
	std::cout << "继续游戏";//在游戏界面外进行，不会影响到之前的结果
	Sleep(100);
	SetCursorPosition(34,23);//纵坐标是行数
	SetColor(11);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34,25);
	std::cout << "退出游戏";
	SetCursorPosition(0,31);//还原光标位置

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key>1) 
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34,21);
					SetBackColor();
					std::cout << "继续游戏";
					SetCursorPosition(34,23);
					SetColor(11);
					std::cout << "重新开始";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34,23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34,25);
					SetColor(11);
					std::cout << "退出游戏";

					--tmp_key;
					break;
				}
			
			}
			break;
		case 80://DOWN
			if (tmp_key<3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34,23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34,21);
					SetColor(11);
					std::cout << "继续游戏";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";

					++tmp_key;
					break;

				}
			}
			break;
		case 13://ENTER
			flag = true;
			break;

		default:
			break;
		}
		if (flag)
			break;
		SetCursorPosition(0,31);
	}

	if (tmp_key==1)//选择继续游戏，则将菜单擦除
	{
		SetCursorPosition(32,19);
		std::cout << "        ";
		SetCursorPosition(34,21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";

	}
	return tmp_key;

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
			int tmp = Menu();
			switch (tmp)
			{
			case 1://继续游戏
				break;
			case 2://重新开始
				delete csnake;
				delete cfood;
				return 1;//返回值
			case 3://退出游戏
				delete csnake;
				delete cfood;
				return 2;

			default:
				break;
			}


		}//假设方向键和ESC没有按下

		if (csnake->GetFood(*cfood))//吃到食物,暂停了？
		{//之前蛇身的位子，被星星给取代了
			//吃到食物之后，重新确定食物的状态，避免跟之前的重复

			//switch里边，该方向上在队列尾部增加一个(蛇头)
			csnake->Move();//坐标加入了snake双头队列里边？，正常移动里边有清除过队列头部，蛇尾
			UpdateScore(1);//
			RewriteScore();
			cfood->DrawFood(*csnake);//参数规定，不能够与蛇重复

		}//吃到食物之后没有清空这种状态。该while循环中一直在判断这种状态
		else {//没有吃到食物，蛇正常移动
			csnake->NormalMove();//移动的时候没有延时？
		}

		if (csnake->GetBigFood(*cfood))//吃到限时食物
		{//限时食物定义？
			csnake->Move();
			//分数根据限时进度条确定..进度条是5的倍数，则翻倍
			UpdateScore(cfood->GetProgressBar()/5);//或者是根据数值，倒计时也可以。
			RewriteScore();//没有找到进度条的变化情况呀？
		}
		//限时食物标记
		if (cfood->GetBigFlag())//如果此时有限时食物，闪烁
		{
			cfood->FlashBigFood();//限时食物闪烁，进度条缩减
		}
		Sleep(speed);//延时，蛇移动效果
	}

	/*蛇死亡*/
	delete csnake;
	delete cfood;
	int tmp = GameOver();
	switch (tmp)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default:
		return 2;
	}



	return 0;
}

void Controller::UpdateScore(const int& tmp)
{
	score += key * 10 * tmp;//根据游戏难度以及tmp确定分数
}

void Controller::RewriteScore() {
	SetCursorPosition(37,7);//37,7 保证分数尾部对齐
	SetColor(11);
	int bit = 0;//???
	int tmp = score;//??
#if 0//??
	while (tmp != 0)
	{
		bit++;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); i++)
	{
		std::cout << " ";
	}
#endif // 0//??

	std::cout << score;

}

int Controller::GameOver() {
	/*绘制游戏结束界面*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ┃              很遗憾！你挂了              ┃";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ┃   是否再来一局？                         ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(12,18);
	SetBackColor();
	std::cout << "嗯，好的";
	SetCursorPosition(0,31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch=_getch())) {
		switch (ch)
		{
		case 75://LEFT
			if (tmp_key>1)
			{
				SetCursorPosition(12,18);
				SetBackColor();//选中背景
				std::cout << "嗯，好的";
				SetCursorPosition(20,18);
				SetColor(11);
				std::cout << "不了，还是学习有意思";
				--tmp_key;
			}
			break;
		case 77://RIGHT
			if (tmp_key<2)
			{
				SetCursorPosition(20,18);
				SetBackColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(12,18);
				SetColor(11);
				std::cout << "嗯，好的";
				++tmp_key;
			}
			break;
		case 13:
			flag = true;
			break;
		default:
			break;
		}

		SetCursorPosition(0,31);
		if (flag)
			break;

	}

	SetColor(11);
	switch (tmp_key)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default:
		return 1;
	}


	
}