#include <graphics.h>					// ͷ�ļ����ֿ��ö��ľͿ�	
#include <time.h>							// ��Ҫ�˽�̰�����߼�����
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//-----------------------------------------------------------------------
//----------------------------------------����̰���߽ڵ��������ͣ�ÿ������x,y�����������
typedef struct node{
	int x;
	int y;
	struct node *next;					// ��һ���ڵ�
}Node;										// �����ڵ�ṹ��
enum direction							// ö�ٱ���,��ʾ�ߵ��˶�����
{
	up, down, right, left
};

int map[20][20] = { 0 };					// ��ͼ������Ϸ��

Node snake = { 1, 5, nullptr };			// ��ͷ������ȡֵΪ0~10
Node save = snake;						// ��ͷλ�õı��ݣ������ƶ���ʱ����������
Node *psn = &snake;						// ̰���������ͷָ�룬̰������Ϊһ����ͷָ��ĵ��������
Node food = { 0, 0, nullptr };			// ʳ�������
enum direction move = right;			// �����ʼ���˶�����Ϊ����

int flag = 0;								// �ж�ʳ���Ƿ���ڣ�ʳ����ڲ���������ʳ��
//-------------------------------------------------�Զ��庯��
void DrawMap();
void PlayGame();
//-------------------------------------------------�����ͼ��ʳ������ͼƬ���ͱ���
IMAGE mapImg, foodImg, snakeImg;					
//-------------------------------------------------��������
int main(void)
{
	initgraph(400, 400);								// ��������
	setbkmode(TRANSPARENT);							// ��������ͼ�������������ʱ�ı���ģʽ����Ϊ͸����ͼ�ο��ж��壩
	HWND  hwnd = GetHWnd();							// ��ȡ���ھ��
	SetWindowText(hwnd, _T("����̰����"));			// ���ñ���
	// ѭ�����ű�������
	mciSendString(L"open ./music/I_Believe.mp3 alias backmusic", 0, 0, 0);
	mciSendString(L"play backmusic repeat", 0, 0, 0);

	// ����ͼƬ��Դ
	loadimage(&mapImg, L"./image/map.bmp", 20,20);
	loadimage(&foodImg, L"./image/food.bmp", 20,20);
	loadimage(&snakeImg, L"./image/snake.bmp", 20,20);
	// ��ʼ������
	map[snake.x][snake.y] =2;						// ��ʼ���ߵ�λ��
	while (1)
	{
		DrawMap();										// ������Ϸ��
		PlayGame();									// ��ʼ��Ϸ
		Sleep(170);									// ��ʱ
	}
	_getch();
	closegraph();
	return 0;
}
// ------------------------------------------------������ơ�ˢ��������Ϸ��
void DrawMap()
{
	int i = 0, j = 0;
	BeginBatchDraw();									// ��ʼ�������ƣ�������ͼ��ȥ����
	cleardevice();									// ����
	for (i = 0; i < 20; i++)							// ��ʼ����
	{
		for (j = 0; j < 20; j++)
		{
			switch (map[i][j])
			{
			case 0:									// ������ͼ
				putimage(i * 20, j *20, &mapImg);
				break;
			case 1:									// ʳ��
				putimage(i * 20, j * 20, &foodImg);
				break;
			case 2:					 				// ��
				putimage(i * 20, j * 20, &snakeImg);
				break;
			default:
				break;
			}
		}
	}
	EndBatchDraw();						 			// ����������ͼ
}
//------------------------------------------------����Ϸ
void PlayGame()
{
	//----------------------------------------------����ʳ��,��Ϊ��ʼ��һ��ʳ��
	while (!flag)										// ����ʳ��
	{
		food.x = rand() % 20;
		food.y = rand() % 20;
		if (map[food.x][food.y] == 0)				// ��ʾ��������ʳ��
		{
			map[food.x][food.y] = 1;
			flag = 1;
		}
	}
	Sleep(5);
	char c;
	if (_kbhit())						    			// ������ͷ�ļ�#include<conio.h>������Ƿ��м�����Ϣ
	{
		c = _getch();									// ��ȡ������Ϣ
		switch (c)										// �Ի�ȡ�����ݷּ�����
		{
		case 'w':
		case 'W':
		case  72:	move = up; break;					// �����ƶ���������
		case 's':
		case 'S':
		case  80:	move = down; break;				// �����ƶ���������
		case 'a':
		case 'A':
		case  75:	move = left;  break;				// �����ƶ���������
		case 'd':
		case 'D':
		case  77:	move = right; break;				// �����ƶ���������
		}
	}
	save = snake;										// ��ͷ�ƶ�ǰ��������ͷ���ݽ���ͷ������
	// �ж��Ƿ�����Ϸ�� 0~19������Ϸ�������ƶ���ͷ
	if (snake.x >= 0 && snake.x <= 19 && snake.y >=0 && snake.y <= 19)  
	{
		switch (move)									// ��ͷ�ƶ�
		{
		case up:										// �����˶�
			if(snake.y>0)
				snake.y--;
			break;
		case down:										// �����˶�
			if (snake.y<19)
				snake.y++;
			break;
		case right:									// �����˶�
			if (snake.x<19)
				snake.x++;
			break;
		case left:										// �����˶�
			if (snake.x>0)
				snake.x--;
			break;
		default:
			break;
		}
	}
	if (snake.x >= 0 && snake.x <= 19 && snake.y >=0 && snake.y <= 19)  	// �ж��Ƿ��ڿ�������Ϸ�� 0~19
	{
		psn = (Node*)malloc(sizeof(Node));										// �����µ���������ֵΪԭ������ͷ
		psn->x = save.x;
		psn->y = save.y;
		psn->next = save.next;													// nullptr
		snake.next = psn;															// ��ͷ�������������� ����
	}
	// �ж��Ƿ�����Ϸ�� 0~19��������β�������ʳ���
	if (snake.x >= 0 && snake.x <= 19 && snake.y >= 0 && snake.y <= 19) 
	{
		switch (map[snake.x][snake.y])											// �ж�λ��
		{
			case 0:																// ˵����ͷ������Ч��ɾ��β��
			{
				Node *s;
				psn = &snake;
				map[snake.x][snake.y] = 2;										// �궨��ͷ
				while (psn->next->next != nullptr)								// �ҵ���β��ǰһ������ڵ�
					psn = psn->next;

				s = psn->next;													// �����β�ڵ�
				psn->next = nullptr;												// ��β����

				map[s->x][s->y] = 0;												// ���β��
				free(s);															// �ͷ���β�ڵ��ڴ�������Ȼ���ڴ�й¶		
				break;
			}
			case 1:																// �߳Ե�ʳ��
			{
				map[snake.x][snake.y] = 2;
				flag = 0;															// ˵����ǰʳ���Ѿ������ˣ����Բ�����ʳ��
				break;
			}
			case 2:																// ҧ���Լ�
			{	break; }
			default:	break;														// ����ʵ�������
		}
	}
	psn = &snake;																	// �ҵ���ͷ
	while (1)
	{
		map[psn->x][psn->y] = 2;													// ���ȫ������
		if (psn->next == nullptr)
			break;																	// ����Ѿ�������β���˳�ѭ��
		else
			psn = psn->next;														// ��û����β�������ƶ�
	}
}

