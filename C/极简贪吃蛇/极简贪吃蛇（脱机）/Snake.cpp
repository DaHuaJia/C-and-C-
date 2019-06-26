#include <graphics.h>					// 头文件部分看得懂的就看	
#include <time.h>							// 主要了解贪吃蛇逻辑代码
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//-----------------------------------------------------------------------
//----------------------------------------定义贪吃蛇节点数据类型，每个点有x,y两个坐标参数
typedef struct node{
	int x;
	int y;
	struct node *next;					// 下一个节点
}Node;										// 建立节点结构体
enum direction							// 枚举变量,表示蛇的运动方向
{
	up, down, right, left
};

int map[20][20] = { 0 };					// 地图就是游戏区

Node snake = { 1, 5, nullptr };			// 蛇头的坐标取值为0~10
Node save = snake;						// 蛇头位置的备份，在蛇移动的时候连入蛇身
Node *psn = &snake;						// 贪吃蛇链表的头指针，贪吃蛇作为一个带头指针的单链表存在
Node food = { 0, 0, nullptr };			// 食物的坐标
enum direction move = right;			// 定义初始化运动方向，为向左

int flag = 0;								// 判断食物是否存在，食物存在不能生成新食物
//-------------------------------------------------自定义函数
void DrawMap();
void PlayGame();
//-------------------------------------------------定义地图、食物、蛇身的图片类型变量
IMAGE mapImg, foodImg, snakeImg;					
//-------------------------------------------------主函数区
int main(void)
{
	initgraph(400, 400);								// 创建窗口
	setbkmode(TRANSPARENT);							// 设置设置图案填充和文字输出时的背景模式，设为透明（图形库中定义）
	HWND  hwnd = GetHWnd();							// 获取窗口句柄
	SetWindowText(hwnd, _T("极简贪吃蛇"));			// 设置标题
	// 循环播放背景音乐
	mciSendString(L"open ./music/I_Believe.mp3 alias backmusic", 0, 0, 0);
	mciSendString(L"play backmusic repeat", 0, 0, 0);

	// 加载图片资源
	loadimage(&mapImg, L"./image/map.bmp", 20,20);
	loadimage(&foodImg, L"./image/food.bmp", 20,20);
	loadimage(&snakeImg, L"./image/snake.bmp", 20,20);
	// 初始化设置
	map[snake.x][snake.y] =2;						// 初始化蛇的位置
	while (1)
	{
		DrawMap();										// 绘制游戏区
		PlayGame();									// 开始游戏
		Sleep(170);									// 延时
	}
	_getch();
	closegraph();
	return 0;
}
// ------------------------------------------------负责绘制、刷新整个游戏区
void DrawMap()
{
	int i = 0, j = 0;
	BeginBatchDraw();									// 开始批量绘制，批量绘图，去闪屏
	cleardevice();									// 清屏
	for (i = 0; i < 20; i++)							// 开始绘制
	{
		for (j = 0; j < 20; j++)
		{
			switch (map[i][j])
			{
			case 0:									// 背景地图
				putimage(i * 20, j *20, &mapImg);
				break;
			case 1:									// 食物
				putimage(i * 20, j * 20, &foodImg);
				break;
			case 2:					 				// 蛇
				putimage(i * 20, j * 20, &snakeImg);
				break;
			default:
				break;
			}
		}
	}
	EndBatchDraw();						 			// 结束批量绘图
}
//------------------------------------------------玩游戏
void PlayGame()
{
	//----------------------------------------------生成食物,因为初始有一个食物
	while (!flag)										// 生成食物
	{
		food.x = rand() % 20;
		food.y = rand() % 20;
		if (map[food.x][food.y] == 0)				// 表示可以生成食物
		{
			map[food.x][food.y] = 1;
			flag = 1;
		}
	}
	Sleep(5);
	char c;
	if (_kbhit())						    			// 包含于头文件#include<conio.h>，检测是否有键盘信息
	{
		c = _getch();									// 获取键盘信息
		switch (c)										// 对获取的数据分级处理
		{
		case 'w':
		case 'W':
		case  72:	move = up; break;					// 设置移动方向，向上
		case 's':
		case 'S':
		case  80:	move = down; break;				// 设置移动方向，向下
		case 'a':
		case 'A':
		case  75:	move = left;  break;				// 设置移动方向，向左
		case 'd':
		case 'D':
		case  77:	move = right; break;				// 设置移动方向，向右
		}
	}
	save = snake;										// 蛇头移动前，保存蛇头数据进蛇头备份区
	// 判断是否在游戏区 0~19，在游戏区域则移动蛇头
	if (snake.x >= 0 && snake.x <= 19 && snake.y >=0 && snake.y <= 19)  
	{
		switch (move)									// 蛇头移动
		{
		case up:										// 向上运动
			if(snake.y>0)
				snake.y--;
			break;
		case down:										// 向下运动
			if (snake.y<19)
				snake.y++;
			break;
		case right:									// 向左运动
			if (snake.x<19)
				snake.x++;
			break;
		case left:										// 向右运动
			if (snake.x>0)
				snake.x--;
			break;
		default:
			break;
		}
	}
	if (snake.x >= 0 && snake.x <= 19 && snake.y >=0 && snake.y <= 19)  	// 判断是否在可生成游戏区 0~19
	{
		psn = (Node*)malloc(sizeof(Node));										// 产生新的蛇身，并赋值为原来的蛇头
		psn->x = save.x;
		psn->y = save.y;
		psn->next = save.next;													// nullptr
		snake.next = psn;															// 蛇头与蛇身链接起来 增长
	}
	// 判断是否在游戏区 0~19，用于蛇尾清除，吃食物等
	if (snake.x >= 0 && snake.x <= 19 && snake.y >= 0 && snake.y <= 19) 
	{
		switch (map[snake.x][snake.y])											// 判断位置
		{
			case 0:																// 说明蛇头产生有效，删除尾巴
			{
				Node *s;
				psn = &snake;
				map[snake.x][snake.y] = 2;										// 标定蛇头
				while (psn->next->next != nullptr)								// 找到蛇尾的前一个蛇身节点
					psn = psn->next;

				s = psn->next;													// 获得蛇尾节点
				psn->next = nullptr;												// 蛇尾脱链

				map[s->x][s->y] = 0;												// 清除尾巴
				free(s);															// 释放蛇尾节点内存区，不然会内存泄露		
				break;
			}
			case 1:																// 蛇吃到食物
			{
				map[snake.x][snake.y] = 2;
				flag = 0;															// 说明当前食物已经被吃了，可以产生新食物
				break;
			}
			case 2:																// 咬到自己
			{	break; }
			default:	break;														// 特殊彩蛋。。。
		}
	}
	psn = &snake;																	// 找到蛇头
	while (1)
	{
		map[psn->x][psn->y] = 2;													// 标记全部蛇身
		if (psn->next == nullptr)
			break;																	// 如果已经到达蛇尾，退出循环
		else
			psn = psn->next;														// 还没到蛇尾，继续移动
	}
}

