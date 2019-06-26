#include<stdio.h>
#include<windows.h>
#include<time.h>
#include <conio.h>
#define Frame_x 6
#define Frame_length 30

//����ȫ�ֱ��� 
int i;
int tail[2]; //���ڼ�ס��β����  a[0]��ʾ�����꣬a[1]��ʾ������ 

struct Snake{ //����һ���ߵĽṹ��
	int x[150]; //�ߵ�ÿ����������꣬����x[0]��ʾ��β�ĺ����꣬x[N-1]��ʾ��ͷ�����ꡣ 
	int y[150]; //�ߵ�ÿ������������꣬����y[0]��ʾ��β��������,y[N-1]��ʾ��β�������ꡣ 
	int count;  //�߳Ե�ʳ��ĸ��� 
	int length; //�ߵĳ��ȣ���ʼ������Ϊ3 
	int speed;  //�ߵ��ٶ�  
};

struct Food{ //����һ��ʳ��Ľṹ�� 
	int x; int y; //�ߵĺ������������ 
}; 

int main(void){
	void gotoxy(HANDLE Out,int x,int y); //������ƶ���ָ����λ��(x,y) 
	void Text_color();  //������Ϸ�ı���ɫ
	void make_frame(); //������Ϸ����
	void game_menu(HANDLE Out,struct Snake *snake,struct Food *food); //��ʾ��Ϸ�˵�����Ϣ
	void set_snake(struct Snake *snake); //���ߵ���Ϣ���г�ʼ��
	void move_snake(HANDLE Out,struct Snake *snake); //�ƶ���
	void disp_snake(HANDLE Out,struct Snake *snake); //������ʾ�ڽ����� 
	void produce_food(HANDLE Out,struct Snake *snake,struct Food *food);//����ʳ������� 
	void eat_food(HANDLE Out,struct Snake *snake,struct Food *food); //�߳�ʳ�� 
	void wall(HANDLE Out,struct Snake *snake,char ch);  //�ߴ�ǽ�� 
	int judge_die(struct Snake *snake); //�ж���ʱ���Ѿ����� 
	void Strat_game(); //��ʼ��Ϸ 
	void Over_game();  //��Ϸ���� 
	
	system("color 0D"); //�����������ı�Ϊ�ۺ�ɫ 
	Strat_game();
	Over_game();
	return 0;
}

void gotoxy(HANDLE Out,int x,int y){ //������ƶ�����x,y����λ�� 
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(Out,pos); //ϵͳ���������ڿ��ƹ���λ�� 
}

void Text_color(){ //������Ϸ�ı���ɫ 
	HANDLE Color=GetStdHandle(STD_OUTPUT_HANDLE); //����������Color����ֵ����Ϊ��׼������
	SetConsoleTextAttribute(Color, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	// ���������������������ɫ���ԣ�Ϊ��ɫ������������ʾ 
} 

void make_frame(){ //������Ϸ���ں��� 
	HANDLE window=GetStdHandle(STD_OUTPUT_HANDLE); //����������window����ֵ
	gotoxy(window,  Frame_x, Frame_x);  //������ƶ���ָ��λ��
	printf("�X"); //�ڴ�λ��������� 
	gotoxy(window, Frame_x+2*Frame_length, Frame_x);
	printf("�[");
	gotoxy(window, Frame_x, Frame_x+Frame_length);
	printf("�^");
	gotoxy(window, Frame_x+2*Frame_length, Frame_x+Frame_length);
	printf("�a");
	int j;
	for(j=1; j<5; j++){  //��ӡ�Ϻ�� 
		if(j==1 || j==2){
			for(i=2; i<2*Frame_length; i++){  
				if(j==1) gotoxy(window, Frame_x+i, Frame_x); //��ӡ�Ϻ��
				else gotoxy(window, Frame_x+i, Frame_x+Frame_length);  //��ӡ�º��
				printf("�T");
			}
		}else {
			for(i=1; i<Frame_length; i++){  
				if(j==3) gotoxy(window, Frame_x, Frame_x+i);  //��ӡ������ 
				else gotoxy(window, Frame_x+2*Frame_length, Frame_x+i);  //��ӡ������ 
				printf("�U");         
			}
		}
	}
	gotoxy(window, Frame_x+2*Frame_length+2, Frame_x+20); 
	printf("Esc �˳���Ϸ"); 
	gotoxy(window, Frame_x+2*Frame_length+2, Frame_x+22);
	printf("�󻰼ҳ�Ʒ 2018.4.2"); 
	gotoxy(window, Frame_x+Frame_length-6, Frame_x-2);
	Text_color();
	printf("̰������Ϸ");
} 

void game_menu(HANDLE Out,struct Snake *snake,struct Food *food){ //��ʾ��Ϸ�˵�����Ϣ
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+1);
	printf("level: %d",snake->count/5+1);    //��ӡ��Ϸ�ȼ� 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+3);
	printf("score: %d",10*snake->count);    //��ӡ��Ϸ�÷� 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+5);
	printf("eat food: %d",snake->count);    //��ӡ����ʳ����� 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+7);
	printf("speed: %dms/��",snake->speed);    //��ӡ��Ϸ�ٶ� 
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+9);
	printf("foodX: %d",food->x);      //��ӡʳ��ĺ�����
	gotoxy(Out, Frame_x+2*Frame_length+3, Frame_x+11);
	printf("foodY: %d",food->y);      //��ӡʳ���������
} 

void set_snake(struct Snake *snake){ //���ߵ���Ϣ���г�ʼ��
	snake->x[0]=Frame_x+2;  //������β���� 
	snake->y[0]=Frame_x+Frame_length/2;
	snake->count=0;  
	snake->length=3; //��ʼ������Ϊ3 
	snake->speed=260;
	for(i=1; i<snake->length; i++){  //����β��������ͷ 
		snake->x[i]=snake->x[i-1]+2;
		snake->y[i]=snake->y[i-1];
	}
}

void move_snake(HANDLE Out,struct Snake *snake){  //�ƶ��ߵ�λ�� 
	gotoxy(Out,snake->x[0],snake->y[0]);
	printf("  ");
	for(i=1; i<snake->length; i++){ //��һ����������ȡ��ǰһ������ 
		snake->x[i-1]=snake->x[i];
		snake->y[i-1]=snake->y[i];
	} 
} 

void disp_snake(HANDLE Out,struct Snake *snake){  //������ʾ�ڽ����� 
	for(i=0; i<snake->length; i++){
		gotoxy(Out,snake->x[i],snake->y[i]);//������ƶ���ָ����λ�� 
		if(i==0){
			printf("��"); //�ж���β 
		}else if(i==snake->length-1){
			printf("��");  //�ж���ͷ 
		} else printf("��");
	} 
} 

void produce_food(HANDLE Out,struct Snake *snake,struct Food *food){  //����ʳ�������
	srand((unsigned)time(NULL));/*ϵͳ������Ϊ�Ժ��������ṩ���ӣ� Ϊ�˷�ֹ������ͬ�� 
	                            ��˲���ϵͳʱ����Ϊ���ӣ��Ա�֤���������ͬ������� */
	while(1){
		food->x=rand() % (Frame_length-3); //�õ�һ��С��Frame_length �����������ֹ������Ϸ�߿� 
		food->y=rand() % Frame_length;
		if(food->x==0 && food->y==0) continue; //��ֹ�������Ͻ�ԭ�㴦 
		food->x=2*food->x+Frame_x+2;  //ȷ��ʳ������ 
		food->y=food->y+Frame_x;
		for(i=0; i<snake->length; i++)  //�ж�ʳ���Ƿ����ߵ������� 
			if(snake->x[i]==food->x && snake->y[i]==food->y) break;
		if(i==snake->length){
			gotoxy(Out,food->x,food->y); //��������ߵ������ϣ�����ʾʳ���λ�� 
			printf("��");
			break;
		}
	}
} 

void eat_food(HANDLE Out,struct Snake *snake,struct Food *food){  //�߳�ʳ�� 
	if(snake->x[snake->length-1]==food->x && snake->y[snake->length-1]==food->y){ //�ж���ͷʱ���ʳ�������غ� 
		snake->length++;
		snake->count++;
		for(i=snake->length-1; i>=1; i--){ //����䳤 
			snake->x[i]=snake->x[i-1];
			snake->y[i]=snake->y[i-1];
		}
		snake->x[0]=tail[0]; //�õ���һ�����ƶ�ǰ��β������ 
		snake->y[0]=tail[1];
		produce_food(Out,snake,food); //���²���ʳ�� 
		if(snake->count % 6==0) snake->speed=snake->speed-20; //ÿ������ʳ�����20ms 
	}
}

void wall(HANDLE Out,struct Snake *snake,char ch){  //�ߴ�ǽ�� 
	if(ch=72 && snake->y[snake->length-1]==Frame_x) //��ͷ���ϱ߽��������ƶ� 
		snake->y[snake->length-1]=Frame_x+Frame_length-1;//����ͷ�ƶ�����Ӧ���±߽��λ�� 
		
	if(ch=80 && snake->y[snake->length-1]==Frame_x+Frame_length) //�� 
		snake->y[snake->length-1]=Frame_x+1;
		
	if(ch=75 && snake->x[snake->length-1]==Frame_x) //�� 
		snake->x[snake->length-1]=Frame_x+2*Frame_length-2;
		
	if(ch=77 && snake->x[snake->length-1]==Frame_x+2*Frame_length) //�� 
		snake->x[snake->length-1]=Frame_x+2;
}

int judge_die(struct Snake *snake){   //�ж���ʱ���Ѿ����� 
	for(i=0; i<snake->length-1; i++){   //����ͷ���������������غ�ʱ������������Ϸ���� 
		if(snake->x[snake->length-1]==snake->x[i] && snake->y[snake->length-1]==snake->y[i])
		return 1;
	}
	return 0;
}

void Over_game(){   //��Ϸ���� 
	system("cls"); //����
	system("color 0D"); //�����������ı�Ϊ�ۺ�ɫ
	printf("\t\t\t\t\t\n\n\n\n��Ϸ������");
}

void Strat_game(){  //��ʼ��Ϸ 
	char ch=77; //��ʼ�����������ƶ�
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE); //�����ʾ���ľ�� 
	struct Snake s,*snake=&s; //����һ����
	struct Food f,*food=&f;  //����ʳ��Ľṹ�����
	
	make_frame(); //������Ϸ����
	set_snake(snake); //��ʼ���� 
	produce_food(Out,snake,food);//����ʳ��
	while(1){ 
		game_menu(Out,snake,food); // ��ʾ��Ϸ��Ϣ
		tail[0]=snake->x[0]; //��ס��β��Ϣ�������߳�ʳ��ʱ����������� 
		tail[1]=snake->y[0];
		if(kbhit()){/* �ж��Ƿ��¼��̣�������£�ch���ռ������� */
		    ch=getch();
		}
		switch(ch){
			case 'W':
			case 72:  //�����ƶ� 
				move_snake(Out,snake);
				snake->y[snake->length-1]-=1;break;
				
			case 'S': 
			case 80:  //�����ƶ� 
				move_snake(Out,snake);
				snake->y[snake->length-1]+=1;break;
				
			case 'A':
			case 75:  //�����ƶ� 
				move_snake(Out,snake);
				snake->x[snake->length-1]-=2;break;
				
			case 'D':
			case 77:  //�����ƶ� 
				move_snake(Out,snake);
				snake->x[snake->length-1]+=2;break;
				
			default:continue; 
		}
		wall(Out,snake,ch); //��ǽ 
		eat_food(Out,snake,food); //��ʳ��
		disp_snake(Out,snake); //��ӡ��
		if(judge_die(snake)==1 || ch==27){  //�ж���Ϸ����   ������ ���� ����Esc 
			gotoxy(Out,Frame_x+Frame_length,Frame_x+Frame_length/2-4);
			system("color 04"); 
			printf("���Ѿ�������"); 
			Sleep(2000); 
			break;
		}
		Sleep(snake->speed);
	} 
}





