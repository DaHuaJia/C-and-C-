#include<stdio.h>
int main(){
	int grade;
	printf("���������ķ�����");
	scanf("%d",&grade);
	if(grade >= 90 && grade <=100)printf("���ĵȼ���A��");
	else if(grade >= 80)printf("���ĵȼ���B��"); 
		 else if(grade >= 70)printf("���ĵȼ���C��");
		 	  else if(grade >= 60)printf("���ĵȼ���D��");
		 	  	   else printf("���ĵȼ���E��"); 
	return grade; 
} 
