#include<stdio.h>
int main(){
	int grade;
	printf("请输入您的分数：");
	scanf("%d",&grade);
	if(grade >= 90 && grade <=100)printf("您的等级是A级");
	else if(grade >= 80)printf("您的等级是B级"); 
		 else if(grade >= 70)printf("您的等级是C级");
		 	  else if(grade >= 60)printf("您的等级是D级");
		 	  	   else printf("您的等级是E级"); 
	return grade; 
} 
