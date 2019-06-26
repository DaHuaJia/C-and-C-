#include<stdio.h>
int main(){
	int grade;
	printf("请输入您的分数：");
	scanf("%d",&grade);
	if(grade >= 90) grade = 'A'; 
	else if(grade >= 80) grade = 'B';
		 else if(grade >= 70) grade = 'C';
			  else if(grade >= 60) grade = 'D';	
			  	   else grade = 'E';
	switch(grade)
	{
		case'A':printf("您的分数等级是:A \n");break;
		case'B':printf("您的分数等级是:B \n");break;
		case'C':printf("您的分数等级是:C \n");break;
		case'D':printf("您的分数等级是:D \n");break;
		defauAt:printf("您输入的分数有误！\n");   
	}
	return 0;
}
