#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct singer{
	char name[30];   //储存选手姓名
	int id;          //选手序号
	char  sex;      //性别 
	char song[30];    //歌曲名字
}singer_num[10]={
	"张欢",16238,'F',"这就是爱",
	"查惠群",16237,'F',"远走高飞",
	"刘娟",16232,'F',"说散就散",
};
int score[10];    //综合成绩 

int main(){
	int fun_grade();      //评分函数
	int fun_search();     //搜索函数
	int fun_cheak();      //修改信息函数 
	int fun_add();        //添加信息
	int fun_order();      //排序函数
	int fun_delect();     //删除函数
	int fun_average();    //求综合成绩函数 
	int fun_save();       //保存综合成绩函数 
	int fun_read();       //读取综合成绩函数 
	int fun_menu();       //菜单函数 
	printf("欢迎进入通信16级 歌唱比赛 评分系统！\n");
	fun_menu();  
	return 0; 
};

int fun_grade(){       //评分函数
	int i;    //用于输出选手信息和录入成绩 
	float sum;
	printf("当前选手有：\n");
	for(i=0; i<10; i++){        //输出选手信息 
		if(singer_num[i].id!=0) printf("%s (%d)\t\t",singer_num[i].name,singer_num[i].id);
		else if(i==0){printf("系统错误！"); return fun_menu();}
	}
	loop1:     //输入序号有误，返回当前语段 
	printf("\n请输入你要评分的选手的序号(五位)："); 
	scanf("%d",&i); 
	if(i>16100 && i<16244){      //提高系统检索效率 
		int j;
		for(j=0; j<10; j++){
			if(i==singer_num[j].id){
				sum=fun_average();     //求综合成绩函数 
				score[j]=sum;
				break;
			}
		}
		if(j==10){printf("该选手序号不存在！");goto loop1;}
	}else {printf("该选手序号不存在！");goto loop1;}
	fun_save();      //保存该选手的综合成绩 
	printf("去掉一个最高分，去掉一个最低分,该选手的最后得分为：%5.2f ",sum);
	return fun_menu();    //返回菜单函数 
};

int fun_search(){  //搜索函数
	int num,i;
	printf("请输入你要搜索的选手的序号(五位)："); 
	scanf("%d",&num);
	for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("姓名：%s\t序号：%d\t性别：%c \t歌曲名称：%s\n",singer_num[i].name,singer_num[i].id,singer_num[i].sex,singer_num[i].song);
			break;
		}
	}
	if(i==10){printf("该选手序号不存在！\n");return fun_menu();}
	return fun_menu();
};

int fun_cheak(){      //修改信息函数 
	int num,i;
	printf("请输入你要修改的选手的序号(五位)：");
	scanf("%d",&num);
	for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("姓名：%s\t序号：%d\t性别：%c \t歌曲名称：%s\n",singer_num[i].name,singer_num[i].id,singer_num[i].sex,singer_num[i].song);
			break;	
		}
	} 
	if(i==10){printf("该选手序号不存在！\n");return fun_menu();}
	printf("是否确认修改该选手的信息？(1、确认)：");
	scanf("%d",&num); 
	if(num!=1) return fun_menu();
	printf("请输入该选手修改后的名字：");
	scanf("%s",&singer_num[i].name); 
	printf("请输入该选手修改后的歌曲名字：");
	scanf("%s",&singer_num[i].song); 
	printf("信息修改成功！");
	return fun_menu(); 
};

int fun_add(){     //添加信息
	int num,i;
	printf("请输入你要添加的选手的序号(五位)：");
	scanf("%d",&num);
	for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("该序号的选手已存在，无法添加！");
			return fun_menu(); 
		}else if(singer_num[i].id==0) break;
	}
	if(i==10){
		printf("当前无法添加新选手！");
		return fun_menu();
	}
	singer_num[i].id=num;     //将该序号赋值给此选手
	printf("请输入该选手的名字：");      //添加新的选手的姓名 
	scanf("%s",&singer_num[i].name); 
	printf("请输入该选手的性别："); 
	scanf("%s",&singer_num[i].sex); 
	printf("请输入该选手的歌曲名字：");    //添加选手的歌曲名字 
	scanf("%s",&singer_num[i].song);  
	printf("信息添加成功！");
	return fun_menu(); 
};

int fun_order(){      //排序函数
	int max,i,j,k;
	fun_read();
	for(j=1; j<10; j++){
		for(i=0,max=0,k=10; i<10; i++){
			if(max<score[i]){
				max=score[i];
				k=i;
			}
		}
		if(singer_num[k].id==0){score[k]=0;continue;} 
		printf("第%d名：%s\t得分：%d\t序号：%d\t歌曲名称：%s \n",j,singer_num[k].name,score[k],singer_num[k].id,singer_num[k].song);
		score[k]=0;
	}
	fun_read();
	return fun_menu();
};

int fun_delect(){       //删除函数
	int i,num;
	printf("请输入你要删除的选手的序号："); 
	scanf("%d",&num);
		for(i=0; i<10; i++){
		if(singer_num[i].id==num){
			printf("姓名：%s\t序号：%d\t性别：%c \t歌曲名称：%s\n",singer_num[i].name,singer_num[i].id,singer_num[i].sex,singer_num[i].song);
			break;
		}
	}
	if(i==10){printf("该选手序号不存在！\n");return fun_menu();}
	printf("你确定删除此选手：(1、确定)：");
	scanf("%d",&num);
	if(num==1){
		singer_num[i].id=0;
		printf("删除成功！");
		return fun_menu(); 
	}else{
		printf("你已放弃删除该选手！");
		return fun_menu(); 
	}
};

int fun_average(){    //求综合成绩函数 
	int i;
	int num[5];      //用于保存五位评委给出的分数 
	int max,min,sum;
	printf("请输入五位评委给出的分数(100分制)：");
	scanf("%d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4]); 
	max=num[0];min=num[0];sum=num[0];
	for(i=1; i<5; i++){
		if(max>num[i]) min=num[i];
		if(max<=num[i]) max=num[i];
		sum+=num[i];
	}
	sum=(sum-max-min)/3.0;   //去掉一个最高分，去掉一个最低分,求平均分
	return sum;
};

int fun_save(){    //保存综合成绩函数 
    //将综合成绩数据保存到file1.txt磁盘文件中   
    int i;
    FILE *fpWrite=fopen("file1.txt","w");  
    if(fpWrite==NULL)  
    {
        printf("无法打开文件\n");
		exit(0);  
    }
   	for(i=0; i<10; i++){
   		fprintf(fpWrite,"%d ",score[i]); 
	} 
    fclose(fpWrite); 
	return 0; 
};

fun_read(){  	  //读取综合成绩函数 
    //从file1.txt磁盘文件中读出成绩数据  
    int i;
    FILE *fpRead=fopen("file1.txt","r");  
    if(fpRead==NULL)  
    {  
        printf("无法打开文件\n");
		exit(0);  
    }  
    for(i=0;i<10;i++) fscanf(fpRead,"%d ",&score[i]); 
    fclose(fpRead); 
    return 0;
};

int fun_menu(){       //菜单函数 
	loop:                                    //输入错误时，返回此语段 
	printf("\n1、进行评分\n");
	printf("2、搜索选手信息\n");
	printf("3、修改选手信息\n");
	printf("4、添加选手信息\n");
	printf("5、选手成绩排名\n");
	printf("6、删除选手信息\n"); 
	printf("0、退出\n");
	printf("请选择你要选择的功能："); 
	fun_read();
	int power;
	scanf("%d",&power);
	switch(power){
		case 1: fun_grade();break;
		case 2: fun_search();break;
		case 3: fun_cheak();break;
		case 4: fun_add();break;
		case 5: fun_order();break;
		case 6: fun_delect();break;
		case 0: exit(0); 
		default :printf("输入错误！请重新选择！"); goto loop; 
	}
	return 0; 	
};


