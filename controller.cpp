#include "controller.h"

//ͬһ������ߵķ����������໥����
void Controller::Game()
{
	Start();//��ʼ����
	while (true)
	{
		Select();//ѡ�����
		DrawGame();//������Ϸ����

		int tmp = PlayGame();
		//������Ϸ�����ѡ�����
		if (tmp==1)
		{
			system("cls");
			continue;//���¿�ʼ
		}
		else if (tmp==2)
		{//�˳���Ϸ
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
	//SetWindowSize(41,32);//����cmd���ں���tools.cpp��
	SetColor(2);

	StartInterface *start = new StartInterface();//startָ��ֻ���¿��ٵĿռ�
	start->Action();
	//start->test();//Ϊ�δ�ӡһ�¾͡��ô�ӡ��ֻ��һ��
	delete start;//�ͷŵ������ĳ�ʼ���Ŀռ�

	/*���ù��λ�ã��������ʾ��ȴ�������������*/
	SetCursorPosition(13,26);
	std::cout << "Press any key to start... ";
	//std::cout << std::endl;
	SetCursorPosition(13, 27);
	system("pause");//������գ����������Ҳ��ִ�и�����
	
//	std:: cout << std::endl;
}
//��Ϸģʽѡ��
void Controller::Select()
{
	/*��ʼ����������*/
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                         ";
	//std::cout << std::endl;
	SetCursorPosition(13, 27);
	std::cout << "                         ";

	//���֮ǰ��ӡ������
	SetCursorPosition(6,21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(6,22);
	std::cout << "(���¼�ѡ�񣬻س�ȷ��)";
	SetCursorPosition(27,22);
	SetBackColor();//����ѡ�б���
	std::cout << "��ģʽ";
	SetColor(3);//��������ǰ����ɫ
	SetCursorPosition(27, 24);
	std::cout << "��ͨģʽ";

	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";

	SetCursorPosition(27, 28);
	std::cout << "����ģʽ";

	SetCursorPosition(0,31);//���ص�������λ
	score = 0;//

	int ch;
	key = 1;
	bool flag = false;

	while ((ch=_getch()))
	{
		//std::cout << ch << std::endl;??
		switch (ch)
		{
		case 72://UP224��
			if (key>1)
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "��ģʽ";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";

					key--;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";

					key--;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "����ģʽ";

					key--;
					break;
				}
			
			}

			break;
		case 80://DOWN�·����
			if (key<4)
			{
				switch (key)
				{
				case 1://�м�ģʽ����ͨģʽ
					SetCursorPosition(27, 24);
					SetBackColor();//����ѡ�б���
					std::cout << "��ͨģʽ";
					SetCursorPosition(27,22);
					SetColor(3);
					std::cout << "��ģʽ";
					key++;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();//����ѡ�б���
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";
					key++;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();//����ѡ�б���
					std::cout << "����ģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";
					key++;
					break;
				}
			}
			break;
		case 13://����enter�� //������������
			flag = true;
			break;
		default:
			break;

		}
		if (flag)break;
		SetCursorPosition(0, 30);
	}
	//key=1,2,3,4�ֱ��ʾ��Ϸ������ģʽ
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

	/*����������*/
	SetColor(3);
	SetCursorPosition(33,1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34,2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(36, 4);
	switch (key)
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "Խ��ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31,7);
	std::cout << "�÷֣�";
	SetCursorPosition(37,7);
	std::cout << " 0";
	SetCursorPosition(33,13);
	std::cout << "������ƶ�";
	SetCursorPosition(33,15);
	std::cout << "ESC����ͣ";


}

int Controller::Menu() {
	/*���Ʋ˵�*/
	SetColor(11);
	SetCursorPosition(32,19);
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34,21);
	SetBackColor();
	std::cout << "������Ϸ";//����Ϸ��������У�����Ӱ�쵽֮ǰ�Ľ��
	Sleep(100);
	SetCursorPosition(34,23);//������������
	SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34,25);
	std::cout << "�˳���Ϸ";
	SetCursorPosition(0,31);//��ԭ���λ��

	/*ѡ�񲿷�*/
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
					std::cout << "������Ϸ";
					SetCursorPosition(34,23);
					SetColor(11);
					std::cout << "���¿�ʼ";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34,23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34,25);
					SetColor(11);
					std::cout << "�˳���Ϸ";

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
					std::cout << "���¿�ʼ";
					SetCursorPosition(34,21);
					SetColor(11);
					std::cout << "������Ϸ";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";

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

	if (tmp_key==1)//ѡ�������Ϸ���򽫲˵�����
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
{//���ˣ����Ĺ����Ѿ�ʵ�֣�ֻ��Ҫ���ƹ��ܼ���
	/*��ʼ���ߺ�ʳ��*/
	Snake *csnake = new Snake();
	Food *cfood = new Food();
	SetColor(6);//�ߵ���ɫ
	csnake->InitSnake();//��Snake����ߵ��߻�������
	srand((unsigned)time(NULL));//������������� rand()�����õ��������
	cfood->DrawFood(*csnake);//������ͨʳ�����ʱʳ�����csnake��Ҫȷ��ʳ�������Ĺ�ϵ��

	//����ִ�е��������ƶ���δ���
	while (csnake->OverEdge() && csnake->HitItself())//�ж����Ƿ�ײǽ��������
	{//�ߵ����������Ǽ���ִ��
		/*����ѡ��˵�*/
		if (!csnake->ChangeDirection())//����ESC�������Ƿ����
		{//������������ʵ�ֵ���ͣ����
			int tmp = Menu();
			switch (tmp)
			{
			case 1://������Ϸ
				break;
			case 2://���¿�ʼ
				delete csnake;
				delete cfood;
				return 1;//����ֵ
			case 3://�˳���Ϸ
				delete csnake;
				delete cfood;
				return 2;

			default:
				break;
			}


		}//���跽�����ESCû�а���

		if (csnake->GetFood(*cfood))//�Ե�ʳ��,��ͣ�ˣ�
		{//֮ǰ�����λ�ӣ������Ǹ�ȡ����
			//�Ե�ʳ��֮������ȷ��ʳ���״̬�������֮ǰ���ظ�

			//switch��ߣ��÷������ڶ���β������һ��(��ͷ)
			csnake->Move();//���������snake˫ͷ������ߣ��������ƶ���������������ͷ������β
			UpdateScore(1);//
			RewriteScore();
			cfood->DrawFood(*csnake);//�����涨�����ܹ������ظ�

		}//�Ե�ʳ��֮��û���������״̬����whileѭ����һֱ���ж�����״̬
		else {//û�гԵ�ʳ��������ƶ�
			csnake->NormalMove();//�ƶ���ʱ��û����ʱ��
		}

		if (csnake->GetBigFood(*cfood))//�Ե���ʱʳ��
		{//��ʱʳ�ﶨ�壿
			csnake->Move();
			//����������ʱ������ȷ��..��������5�ı������򷭱�
			UpdateScore(cfood->GetProgressBar()/5);//�����Ǹ�����ֵ������ʱҲ���ԡ�
			RewriteScore();//û���ҵ��������ı仯���ѽ��
		}
		//��ʱʳ����
		if (cfood->GetBigFlag())//�����ʱ����ʱʳ���˸
		{
			cfood->FlashBigFood();//��ʱʳ����˸������������
		}
		Sleep(speed);//��ʱ�����ƶ�Ч��
	}

	/*������*/
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
	score += key * 10 * tmp;//������Ϸ�Ѷ��Լ�tmpȷ������
}

void Controller::RewriteScore() {
	SetCursorPosition(37,7);//37,7 ��֤����β������
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
	/*������Ϸ��������*/
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "��������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ��               Game Over !!!              ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ��              ���ź��������              ��";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ��             ��ķ���Ϊ��                 ��";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ��   �Ƿ�����һ�֣�                         ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "��������������������������������������������";

	Sleep(100);
	SetCursorPosition(12,18);
	SetBackColor();
	std::cout << "�ţ��õ�";
	SetCursorPosition(0,31);

	/*ѡ�񲿷�*/
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
				SetBackColor();//ѡ�б���
				std::cout << "�ţ��õ�";
				SetCursorPosition(20,18);
				SetColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				--tmp_key;
			}
			break;
		case 77://RIGHT
			if (tmp_key<2)
			{
				SetCursorPosition(20,18);
				SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(12,18);
				SetColor(11);
				std::cout << "�ţ��õ�";
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