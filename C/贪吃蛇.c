#include<stdio.h>
#include<windows.h>
#include<time.h>
#include <conio.h>
#define Frame_x 6
#define Frame_length 30

//定义全局变量 
int i;
int tail[2]; //用于记住蛇尾坐标  a[0]表示横坐标，a[1]表示纵坐标 

struct Snake{ //声明一个蛇的结构体
	int x[150]; //蛇的每节身体横坐标，其中x[0]表示蛇尾的横坐标，x[N-1]表示蛇头横坐标。 
	int y[150]; //蛇的每节身体的纵坐标，其中y[0]表示蛇尾的纵坐标,y[N-1]表示蛇尾的纵坐标。 
	int count;  //蛇吃的食物的个数 
	int length; //蛇的长度，初始化长度为3 
	int speed;  //蛇的速度  
};

struct Food{ //定义一个食物的结构体 
	int x; int y; //蛇的横坐标和纵坐标 
}; 

int main(void){
	void gotoxy(HANDLE Out,int x,int y); //将光标移动到指定的位置(x,y) 
	void Text_color();  //设置游戏文本颜色
	void make_frame(); //制作游戏窗口
	void game_menu(HANDLE Out,struct Snake *snake,struct Food *food); //显示游戏菜单栏信息
	void set_snake(struct Snake *snake); //对蛇的信息进行初始化
	void move_snake(HANDLE Out,struct Snake *snake); //移动蛇
	void disp_snake(HANDLE Out,struct Snake *snake); //将蛇显示在界面上 
	void produce_food(HANDLE Out,struct Snake *snake,struct Food *food);//产生食物的坐标 
	void eat_food(HANDLE Out,struct Snake *snake,struct Food *food); //蛇吃食物 
	void wall(HANDLE Out,struct Snake *snake,char ch);  //蛇穿墙壁 
	int judge_die(struct Snake *snake); //判断蛇时候已经死亡 
	void Strat_game(); //开始游戏 
	void Over_game();  //游戏结束 
	
	system("color 0D"); //设置主界面文本为粉红色 
	Strat_game();
	Over_game();
	return 0;
}

void gotoxy(HANDLE Out,int x,int y){ //将光标移动到（x,y）的位置 
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(Out,pos); //系统函数，用于控制光标的位置 
}

void Text_color(){ //设置游戏文本颜色 
	HANDLE Color=GetStdHandle(STD_OUTPUT_HANDLE); //定义句柄变量Color并赋值，成为标准输出句柄
	SetConsoleTextAttribute(Color, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	// 计算机函数，用于设置颜色属性，为蓝色，背景高亮显示 
} 

void make_frame(){ //制作游戏窗口函数 
	HANDLE window=GetStdHandle(STD_OUTPUT_HANDLE); //定义句柄变量window并赋值
	gotoxy(window,  Frame_x, Frame_x);  //将光标移动到指定位置
	printf("╔"); //在此位置输出内容 
	gotoxy(window, Frame_x+2*Frame_length, Frame_x);
	printf("╗");
	gotoxy(window, Frame_x, Frame_x+Frame_length);
	printf("╚");
	gotoxy(window, Frame_x+2*Frame_length, Frame_x+Frame_length);
	printf("╝");
	int j;
	for(j=1; j<5; j++){  //打印上横框 
		if(j==1 || j==2){
			for(i=2; i<2*Frame_length; i++){  
				if(j==1) gotoxy(window, Frame_x+i, Frame_x); //打印上横框
				else gotoxy(window, Frame_x+i, Frame_x+Frame_length);  //打印下横框
				printf("═");
			}
		}else {
			for(i=1; i<Frame_length; i++){  
				if(j==3) gotoxy(window, Frame_x, Frame_x+i);  //打印左竖框 
				else gotoxy(window, Frame_x+2*Frame_length, Frame_x+i);  //打印右竖框 
				printf("║");         
			}
		}
	}
	gotoxy(window, Frame_x+2*Frame_length+2, Frame_x+20); 
	printf("Esc 退出游戏"); 
	gotoxy(window, Frame_x+2*Frame_length+2, Frame_x+22);
	printf("大话家出品 2018.4.2"); 
	gotoxy(window, Frame_x+Frame_length-6, Frame_x-2);
	Text_color();
	printf("贪吃蛇游戏");
} 

void game_menu(HANDLE Out,struct Snake *snake,struct Food *food){ //显示游戏菜单栏信息
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+1);
	printf("level: %d",snake->count/5+1);    //打印游戏等级 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+3);
	printf("score: %d",10*snake->count);    //打印游戏得分 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+5);
	printf("eat food: %d",snake->count);    //打印产生食物个数 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+7);
	printf("speed: %dms/次",snake->speed);    //打印游戏速度 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+9);
	printf("foodX: %d",food->x);      //打印食物的横坐标
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+11);
	printf("foodY: %d",food->y);      //打印食物的竖坐标
} 

void set_snake(struct Snake *snake){ //对蛇的信息进行初始化
	snake->x[0]=Frame_x+2;  //设置蛇尾坐标 
	snake->y[0]=Frame_x+Frame_length/2;
	snake->count=0;  
	snake->length=3; //初始化长度为3 
	snake->speed=260;
	for(i=1; i<snake->length; i++){  //从蛇尾遍历到蛇头 
		snake->x[i]=snake->x[i-1]+2;
		snake->y[i]=snake->y[i-1];
	}
}

void move_snake(HANDLE Out,struct Snake *snake){  //移动蛇的位置 
	gotoxy(Out,snake->x[0],snake->y[0]);
	printf("  ");
	for(i=1; i<snake->length; i++){ //后一节坐标依次取代前一节坐标 
		snake->x[i-1]=snake->x[i];
		snake->y[i-1]=snake->y[i];
	} 
} 

void disp_snake(HANDLE Out,struct Snake *snake){  //将蛇显示在界面上 
	for(i=0; i<snake->length; i++){
		gotoxy(Out,snake->x[i],snake->y[i]);//将光标移动到指定的位置 
		if(i==0){
			printf("○"); //判断蛇尾 
		}else if(i==snake->length-1){
			printf("¤");  //判断蛇头 
		} else printf("⊙");
	} 
} 

void produce_food(HANDLE Out,struct Snake *snake,struct Food *food){  //产生食物的坐标
	srand((unsigned)time(NULL));/*系统函数，为以后的随机数提供种子， 为了防止种子相同， 
	                            因此采用系统时间作为种子，以保证不会产生相同的随机数 */
	while(1){
		food->x=rand() % (Frame_length-3); //得到一个小于Frame_length 的随机数，防止超出游戏边框 
		food->y=rand() % Frame_length;
		if(food->x==0 && food->y==0) continue; //防止其在左上角原点处 
		food->x=2*food->x+Frame_x+2;  //确定食物坐标 
		food->y=food->y+Frame_x;
		for(i=0; i<snake->length; i++)  //判断食物是否在蛇的身体上 
			if(snake->x[i]==food->x && snake->y[i]==food->y) break;
		if(i==snake->length){
			gotoxy(Out,food->x,food->y); //如果不在蛇的身体上，则显示食物的位置 
			printf("⊙");
			break;
		}
	}
} 

void eat_food(HANDLE Out,struct Snake *snake,struct Food *food){  //蛇吃食物 
	if(snake->x[snake->length-1]==food->x && snake->y[snake->length-1]==food->y){ //判断蛇头时候和食物坐标重合 
		snake->length++;
		snake->count++;
		for(i=snake->length-1; i>=1; i--){ //蛇身变长 
			snake->x[i]=snake->x[i-1];
			snake->y[i]=snake->y[i-1];
		}
		snake->x[0]=tail[0]; //得到上一次蛇移动前蛇尾的坐标 
		snake->y[0]=tail[1];
		produce_food(Out,snake,food); //重新产生食物 
		if(snake->count % 6==0) snake->speed=snake->speed-20; //每吃六个食物加速20ms 
	}
}

void wall(HANDLE Out,struct Snake *snake,char ch){  //蛇穿墙壁 
	if(ch=72 && snake->y[snake->length-1]==Frame_x) //蛇头在上边界且向上移动 
		snake->y[snake->length-1]=Frame_x+Frame_length-1;//将蛇头移动到对应的下边界的位置 
		
	if(ch=80 && snake->y[snake->length-1]==Frame_x+Frame_length) //下 
		snake->y[snake->length-1]=Frame_x+1;
		
	if(ch=75 && snake->x[snake->length-1]==Frame_x) //左 
		snake->x[snake->length-1]=Frame_x+2*Frame_length-2;
		
	if(ch=77 && snake->x[snake->length-1]==Frame_x+2*Frame_length) //右 
		snake->x[snake->length-1]=Frame_x+2;
}

int judge_die(struct Snake *snake){   //判断蛇时候已经死亡 
	for(i=0; i<snake->length-1; i++){   //当蛇头和自身任意坐标重合时，蛇死亡，游戏结束 
		if(snake->x[snake->length-1]==snake->x[i] && snake->y[snake->length-1]==snake->y[i])
		return 1;
	}
	return 0;
}

void Over_game(){   //游戏结束 
	system("cls"); //清屏
	system("color 0D"); //设置主界面文本为粉红色
	printf("\t\t\t\t\t\n\n\n\n游戏结束！");
}

void Strat_game(){  //开始游戏 
	char ch=77; //初始条件蛇向右移动
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE); //获得显示器的句柄 
	struct Snake s,*snake=&s; //定义一条蛇
	struct Food f,*food=&f;  //定义食物的结构体变量
	
	make_frame(); //制作游戏窗口
	set_snake(snake); //初始化蛇 
	produce_food(Out,snake,food);//产生食物
	while(1){ 
		game_menu(Out,snake,food); // 显示游戏信息
		tail[0]=snake->x[0]; //记住蛇尾信息，用于蛇吃食物时蛇身体的增加 
		tail[1]=snake->y[0];
		if(kbhit()){/* 判断是否按下键盘，如果按下，ch接收键盘输入 */
		    ch=getch();
		}
		switch(ch){
			case 'W':
			case 72:  //向上移动 
				move_snake(Out,snake);
				snake->y[snake->length-1]-=1;break;
				
			case 'S': 
			case 80:  //向下移动 
				move_snake(Out,snake);
				snake->y[snake->length-1]+=1;break;
				
			case 'A':
			case 75:  //向左移动 
				move_snake(Out,snake);
				snake->x[snake->length-1]-=2;break;
				
			case 'D':
			case 77:  //向右移动 
				move_snake(Out,snake);
				snake->x[snake->length-1]+=2;break;
				
			default:continue; 
		}
		wall(Out,snake,ch); //穿墙 
		eat_food(Out,snake,food); //吃食物
		disp_snake(Out,snake); //打印蛇
		if(judge_die(snake)==1 || ch==27){  //判断游戏结束   蛇死亡 或者 按下Esc 
			gotoxy(Out,Frame_x+Frame_length,Frame_x+Frame_length/2-4);
			system("color 04"); 
			printf("蛇已经死亡！"); 
			Sleep(2000); 
			break;
		}
		Sleep(snake->speed);
	} 
}





