#include<stdio.h>
int main(){
	int grade;
	printf("���������ķ�����");
	scanf("%d",&grade);
	if(grade >= 90) grade = 'A'; 
	else if(grade >= 80) grade = 'B';
		 else if(grade >= 70) grade = 'C';
			  else if(grade >= 60) grade = 'D';	
			  	   else grade = 'E';
	switch(grade)
	{
		case'A':printf("���ķ����ȼ���:A \n");break;
		case'B':printf("���ķ����ȼ���:B \n");break;
		case'C':printf("���ķ����ȼ���:C \n");break;
		case'D':printf("���ķ����ȼ���:D \n");break;
		defauAt:printf("������ķ�������\n");   
	}
	return 0;
}
