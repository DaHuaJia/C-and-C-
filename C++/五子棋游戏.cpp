/*c++�������塪�˻�V1.0���˰汾�����޸�Ϊ���ӣ���ӵ����㷨*/
#include<iostream>
#include<iomanip>
#include<string.h>
#include <windows.h>
#include<time.h>
using namespace std;
 
const int X = 21; //��������
const int Y = 21; //��������
int p[X][Y];  //��������
int m=0;//������ʱ�㣬������������
int n=0;

void color( int a ){             /* ��ɫ���� */
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), a );
}

void gotoxy( int x, int y ){ /* λ�ú��� */
	COORD pos;
	pos.X	= 2 * x;
	pos.Y	= y;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), pos );
}
 
void display()  //�������
{
	color( 11 );//��ʼ��ɫ 
    for(int i=0; i<X; i++)
        cout<<setw(2)<<setfill(' ')<<i;//setw(x)xΪ������ 
    cout<<endl;
    for(int i=1; i<Y; i++)
    {
        cout<<setw(2)<<setfill(' ')<<i; //�к� 
        for(int j=1;j<X;j++){
        	if(p[i][j]==1){
        		color(15);//1��ɫ 
        		cout<<"��";  //��
			}
        		
        	else if(p[i][j]==2){
        		color(4);//2��ɫ 
        		cout<<"��"; //
			}
        		
        	else{
        		color( 11 ); //���ֳ�ʼ��ɫ 
        		cout<<"��";  //<<setw(3)<<setfill(' ')
			} 
        		
		}
        cout<<endl;
    }
     
}

int set(int m,int n){//�ж�(m,n)���Ƿ�Ϊ�������ӣ����������ӷ���1�����򷵻�0��
	if(m<=0||m>=X||n>=Y||n<=0)  //p[m][n]==!0||
		return 0;
   	else if(p[m][n]==0){
   		p[m][n]=1;
   		return 1;
	} 
	return 0;        	
} 

int judge3(int k,int r,int x){//�ж��Ƿ��������� ,m nΪ����,x=1or2�� 

            if(p[k][r]==x&&p[k-1][r-1]==x&&p[k+1][r+1]==x){
				if(set(k-2,r-2)||set(k+2,r+2)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}		 
			} 
            else if(p[k][r]==x&&p[k+1][r-1]==x&&p[k-1][r+1]==x){
            	if(set(k+2,r-2)||set(k-2,r+2)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}
			}
                
			 /*�����ж�*/
        	else if(p[k][r]==x&&p[k][r-1]==x&&p[k][r+1]==x){
        		if(set(k,r-2)||set(k,r+2)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}
			}
                
			 /*�����ж�*/
        	else if(p[k][r]==x&&p[k-1][r]==x&&p[k+1][r]==x){
        		if(set(k-2,r)||set(k+2,r)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}
			}
	return 0;
}

int judge4(int k,int r,int x){//�ж��Ƿ��������� ,m nΪ����,x=1or2�� 

            if(p[k][r]==x&&p[k+1][r+1]==x&&p[k+2][r+2]==x&&p[k+3][r+3]==x){
				if(set(k-1,r-1)||set(k+4,r+4)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}		 
			} 
            else if(p[k][r]==x&&p[k-1][r+1]==x&&p[k-2][r+2]==x&&p[k-3][r+3]){
            	if(set(k+1,r-1)||set(k-4,r+4)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}
			}
                
			 /*�����ж�*/
        	else if(p[k][r]==x&&p[k][r-1]==x&&p[k][r+1]==x&&p[k][r+2]){
        		if(set(k,r-2)||set(k,r+3)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}
			}
                
			 /*�����ж�*/
        	else if(p[k][r]==x&&p[k-1][r]==x&&p[k+1][r]==x&&p[k+2][r]){
        		if(set(k-2,r)||set(k+3,r)){
                	system("cls");display();
					return 1;//�ɹ����Ӳ�����
				}
			}
	return 0;
}

void white()  //�׷�����
{
	srand(time(0));
	int k = 0,r = 0;
	
	//////////////�жϺ��������� 
	for(k=1;k<X-1;k++)  
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge4(k,r,2))
			return;
        }//for
    }//for
   
	///////////////���������� 
    for(k=1;k<X-1;k++)  //���������е�p[k][r]!=0���ų����ӵ����
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge4(k,r,1))
			return;
                	
        }//for
    }//for
	
	//////////////�жϺ��������� 
	for(k=1;k<X-1;k++)  
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge3(k,r,2))
			return;
        }//for
    }//for
   
	///////////////���������� 
    for(k=1;k<X-1;k++)  //���������е�p[k][r]!=0���ų����ӵ����
    {
        for(r=1;r<Y-1;r++)
        {
            if(judge3(k,r,1))
			return;
                	
        }//for
    }//for
     
		//���Ӹ���6������ 
	 	for(k=1;k<X;k++)
		 	for(r=1;r<Y;r++){
		 		if(p[k][r]==2&&set(k,r+1)){
		 			system("cls");display();
					return;//�ɹ����Ӳ�����
		 		}
		 		else if(p[k][r]==2&&set(k+1,r)){
		 			system("cls");display();
					return;//�ɹ����Ӳ�����
		 		}
		 		else if(p[k][r]==2&&set(k,r-1)){
		 			system("cls");display();
					return;//�ɹ����Ӳ�����
		 		}
		 		else if(p[k][r]==2&&set(k-1,r)){
		 			system("cls");display();
					return;//�ɹ����Ӳ�����
		 		}
		 		else if(p[k][r]==2&&set(k+1,r+1)){
		 			system("cls");display();
					return;//�ɹ����Ӳ�����
		 		}
		 		else if(p[k][r]==2&&set(k-1,r-1)){
		 			system("cls");display();
					return;//�ɹ����Ӳ�����
		 		}
			 }          	
	
	while(1){  //������� 
	 		k=rand()%20+1;
	 		r=rand()%20+1;
            if(p[k][r]==0)
                if(set(k,r)){
                	system("cls");display();
					return;//�ɹ����Ӳ�����
				}          	
	}//while
	
}
 
void red()  //�췽����
{
	color(4);
    cout<<"��췽��������λ�ã�\n"
        <<"���������ӵ�������";
    cin>>m;
    cout<<"���������ӵ�������";
    cin>>n;
    if(m>=X||m<=0||n<=0||n>=Y)
    {
        cout<<"�������̷�Χ��������������ȷ���꣡\n";
        red();
    }
    else if((p[m][n]==1)||p[m][n]==2)
    {
        cout<<"�õ��������ӣ�������ѡȡ���ӵ㣡\n";
        red();
    }
    else
        p[m][n]=2; //�췽��2����ʾ
    system("cls");
    display();
}
 
int evalue()  //ֻ��Ҫ�ж����ӵ�Ϊ���ĵľŵ㡰�ס����Ƿ���������
{
    int k = 0,r = 0;
    /*б���ж�*/
    for(k=3;k<X-2;k++)  //���������е�p[k][r]!='-'���ų����ӵ����
    {
        for(r=3;r<Y-2;r++)
        {
            if(p[k][r]!=0&&p[k-2][r-2]==p[k][r]&&p[k-1][r-1]==p[k][r]&&p[k+1][r+1]==p[k][r]&&p[k+2][r+2]==p[k][r])
                return 1;
            else if(p[k][r]!=0&&p[k+2][r-2]==p[k][r]&&p[k+1][r-1]==p[k][r]&&p[k-1][r+1]==p[k][r]&&p[k-2][r+2]==p[k][r])
                return 1;
        }
    }
    /*�����ж�*/
    for(k=1;k<X;k++)  //p[k][r]!='-'���ų����ӵ����
        for(r=3;r<Y-2;r++)
            if(p[k][r]!=0&&p[k][r-2]==p[k][r]&&p[k][r-1]==p[k][r]&&p[k][r+1]==p[k][r]&&p[k][r+2]==p[k][r])
                return 1;
    /*�����ж�*/
    for(k=3;k<X-2;k++)  //p[k][r]!='-'���ų����ӵ����
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
    cout<<"-------------------------���������˻���V1.0��------------------------";
    gotoxy(10,13);
    cout<<"                                            �������ߣ�Rehq";
    for(i=3;i>0;i--){
    	color(i+1);
    	gotoxy(23,15);
    	cout<<"������ʼ "<<i<<"����";
    	Sleep(1000);
	}
	system("cls");	
    
}

int main()
{
	int i,j;
    for(i=1;i<X;i++)//��ʼ��Ϊ0 
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
            cout<<"�췽Ӯ��\n";
            break;
        }
        white();
        if(evalue())
        {
        	color(7);
            cout<<"�׷�Ӯ��\n";
            break;
        }  
    }
    return 0;
}
