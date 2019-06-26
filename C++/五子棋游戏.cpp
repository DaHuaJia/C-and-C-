/*c++《五子棋—人机V1.0》此版本电脑修改为白子，添加电脑算法*/
#include<iostream>
#include<iomanip>
#include<string.h>
#include <windows.h>
#include<time.h>
using namespace std;
 
const int X = 21; //棋盘行数
const int Y = 21; //棋盘列数
int p[X][Y];  //定义棋盘
int m=0;//定义临时点，保存输入坐标
int n=0;

void color( int a ){             /* 颜色函数 */
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), a );
}

void gotoxy( int x, int y ){ /* 位置函数 */
	COORD pos;
	pos.X	= 2 * x;
	pos.Y	= y;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), pos );
}
 
void display()  //输出棋盘
{
	color( 11 );//初始颜色 
    for(int i=0; i<X; i++)
        cout<<setw(2)<<setfill(' ')<<i;//setw(x)x为输出间隔 
    cout<<endl;
    for(int i=1; i<Y; i++)
    {
        cout<<setw(2)<<setfill(' ')<<i; //列号 
        for(int j=1;j<X;j++){
        	if(p[i][j]==1){
        		color(15);//1白色 
        		cout<<"●";  //○
			}
        		
        	else if(p[i][j]==2){
        		color(4);//2红色 
        		cout<<"●"; //
			}
        		
        	else{
        		color( 11 ); //保持初始颜色 
        		cout<<"□";  //<<setw(3)<<setfill(' ')
			} 
        		
		}
        cout<<endl;
    }
     
}

int set(int m,int n){//判断(m,n)处是否为可以下子，可以则下子返回1，否则返回0；
	if(m<=0||m>=X||n>=Y||n<=0)  //p[m][n]==!0||
		return 0;
   	else if(p[m][n]==0){
   		p[m][n]=1;
   		return 1;
	} 
	return 0;        	
} 

int judge3(int k,int r,int x){//判断是否三子相连 ,m n为坐标,x=1or2； 

            if(p[k][r]==x&&p[k-1][r-1]==x&&p[k+1][r+1]==x){
				if(set(k-2,r-2)||set(k+2,r+2)){
                	system("cls");display();
					return 1;//成功下子并结束
				}		 
			} 
            else if(p[k][r]==x&&p[k+1][r-1]==x&&p[k-1][r+1]==x){
            	if(set(k+2,r-2)||set(k-2,r+2)){
                	system("cls");display();
					return 1;//成功下子并结束
				}
			}
                
			 /*横线判断*/
        	else if(p[k][r]==x&&p[k][r-1]==x&&p[k][r+1]==x){
        		if(set(k,r-2)||set(k,r+2)){
                	system("cls");display();
					return 1;//成功下子并结束
				}
			}
                
			 /*竖线判断*/
        	else if(p[k][r]==x&&p[k-1][r]==x&&p[k+1][r]==x){
        		if(set(k-2,r)||set(k+2,r)){
                	system("cls");display();
					return 1;//成功下子并结束
				}
			}
	return 0;
}

int judge4(int k,int r,int x){//判断是否四子相连 ,m n为坐标,x=1or2； 

            if(p[k][r]==x&&p[k+1][r+1]==x&&p[k+2][r+2]==x&&p[k+3][r+3]==x){
				if(set(k-1,r-1)||set(k+4,r+4)){
                	system("cls");display();
					return 1;//成功下子并结束
				}		 
			} 
            else if(p[k][r]==x&&p[k-1][r+1]==x&&p[k-2][r+2]==x&&p[k-3][r+3]){
            	if(set(k+1,r-1)||set(k-4,r+4)){
                	system("cls");display();
					return 1;//成功下子并结束
				}
			}
                
			 /*横线判断*/
        	else if(p[k][r]==x&&p[k][r-1]==x&&p[k][r+1]==x&&p[k][r+2]){
        		if(set(k,r-2)||set(k,r+3)){
                	system("cls");display();
					return 1;//成功下子并结束
				}
			}
                
			 /*竖线判断*/
        	else if(p[k][r]==x&&p[k-1][r]==x&&p[k+1][r]==x&&p[k+2][r]){
        		if(set(k-2,r)||set(k+3,r)){
                	system("cls");display();
					return 1;//成功下子并结束
				}
			}
	return 0;
}

void white()  //白方落子
{
	srand(time(0));
	int k = 0,r = 0;
	
	//////////////判断红四子相连 
	for(k=1;k<X-1;k++)  
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge4(k,r,2))
			return;
        }//for
    }//for
   
	///////////////白四子相连 
    for(k=1;k<X-1;k++)  //两条，其中的p[k][r]!=0是排除空子的情况
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge4(k,r,1))
			return;
                	
        }//for
    }//for
	
	//////////////判断红三子相连 
	for(k=1;k<X-1;k++)  
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge3(k,r,2))
			return;
        }//for
    }//for
   
	///////////////白三子相连 
    for(k=1;k<X-1;k++)  //两条，其中的p[k][r]!=0是排除空子的情况
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge3(k,r,1))
			return;
                	
        }//for
    }//for
     
		//红子附近6处下子 
	 	for(k=1;k<X;k++)
		 	for(r=1;r<Y;r++){
		 		if(p[k][r]==2&&set(k,r+1)){
		 			system("cls");display();
					return;//成功下子并结束
		 		}
		 		else if(p[k][r]==2&&set(k+1,r)){
		 			system("cls");display();
					return;//成功下子并结束
		 		}
		 		else if(p[k][r]==2&&set(k,r-1)){
		 			system("cls");display();
					return;//成功下子并结束
		 		}
		 		else if(p[k][r]==2&&set(k-1,r)){
		 			system("cls");display();
					return;//成功下子并结束
		 		}
		 		else if(p[k][r]==2&&set(k+1,r+1)){
		 			system("cls");display();
					return;//成功下子并结束
		 		}
		 		else if(p[k][r]==2&&set(k-1,r-1)){
		 			system("cls");display();
					return;//成功下子并结束
		 		}
			 }          	
	
	while(1){  //随机下子 
	 		k=rand()%20+1;
	 		r=rand()%20+1;
            if(p[k][r]==0)
                if(set(k,r)){
                	system("cls");display();
					return;//成功下子并结束
				}          	
	}//while
	
}
 
void red()  //红方落子
{
	color(4);
    cout<<"请红方输入落子位置：\n"
        <<"请输入落子的行数：";
    cin>>m;
    cout<<"请输入落子的列数：";
    cin>>n;
    if(m>=X||m<=0||n<=0||n>=Y)
    {
        cout<<"超出棋盘范围，请重新输入正确坐标！\n";
        red();
    }
    else if((p[m][n]==1)||p[m][n]==2)
    {
        cout<<"该点已有棋子，请重新选取落子点！\n";
        red();
    }
    else
        p[m][n]=2; //红方用2来表示
    system("cls");
    display();
}
 
int evalue()  //只需要判断落子点为中心的九点“米”字是否连续即可
{
    int k = 0,r = 0;
    /*斜线判断*/
    for(k=3;k<X-2;k++)  //两条，其中的p[k][r]!='-'是排除空子的情况
    {
        for(r=3;r<Y-2;r++)
        {
            if(p[k][r]!=0&&p[k-2][r-2]==p[k][r]&&p[k-1][r-1]==p[k][r]&&p[k+1][r+1]==p[k][r]&&p[k+2][r+2]==p[k][r])
                return 1;
            else if(p[k][r]!=0&&p[k+2][r-2]==p[k][r]&&p[k+1][r-1]==p[k][r]&&p[k-1][r+1]==p[k][r]&&p[k-2][r+2]==p[k][r])
                return 1;
        }
    }
    /*横线判断*/
    for(k=1;k<X;k++)  //p[k][r]!='-'是排除空子的情况
        for(r=3;r<Y-2;r++)
            if(p[k][r]!=0&&p[k][r-2]==p[k][r]&&p[k][r-1]==p[k][r]&&p[k][r+1]==p[k][r]&&p[k][r+2]==p[k][r])
                return 1;
    /*竖线判断*/
    for(k=3;k<X-2;k++)  //p[k][r]!='-'是排除空子的情况
        for(r=1;r<Y;r++)
            if(p[k][r]!=0&&p[k-2][r]==p[k][r]&&p[k-1][r]==p[k][r]&&p[k+1][r]==p[k][r]&&p[k+2][r]==p[k][r])
                return 1;
    return 0; 
}

void Welcome(){
	int i;
	color(1);
	gotoxy(10,10);
    cout<<"-------------------------------WELCOME-------------------------------";
    gotoxy(10,11);
    cout<<"-------------------------《五子棋人机版V1.0》------------------------";
    gotoxy(10,13);
    cout<<"                                            ——作者：Rehq";
    for(i=3;i>0;i--){
    	color(i+1);
    	gotoxy(23,15);
    	cout<<"即将开始 "<<i<<"……";
    	Sleep(1000);
	}
	system("cls");	
    
}

int main()
{
	int i,j;
    for(i=1;i<X;i++)//初始化为0 
    	for(j=1;j<Y;j++)
    		p[i][j]=0;
    		
  	Welcome();
    display();
    while(1)
    {
        red();
        if(evalue())
        {
        	color(4);
            cout<<"红方赢！\n";
            break;
        }
        white();
        if(evalue())
        {
        	color(7);
            cout<<"白方赢！\n";
            break;
        }  
    }
    return 0;
}
