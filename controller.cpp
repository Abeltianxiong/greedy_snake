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

		}//���跽�����ESCû�а���

		if (csnake->GetFood(*cfood))//�Ե�ʳ��,��ͣ�ˣ�
		{//֮ǰ�����λ�ӣ������Ǹ�ȡ����
			//�Ե�ʳ��֮������ȷ��ʳ���״̬�������֮ǰ���ظ�
			cfood->DrawFood(*csnake);//�����涨�����ܹ������ظ�

		}//�Ե�ʳ��֮��û���������״̬����whileѭ����һֱ���ж�����״̬
		else {//û�гԵ�ʳ��������ƶ�
			csnake->NormalMove();//�ƶ���ʱ��û����ʱ��
		}


		Sleep(speed);//��ʱ�����ƶ�Ч��

	}



	return 0;
}