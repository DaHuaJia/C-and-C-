#include<stdio.h>
int main(){
	int dgt[4]={1,12,123,1234};
	int *p=dgt;
	printf("%d \n",*p); 
	printf("%d \n",++*p);    //�ȼ���  ++��*p�� ;�ҽ���ԣ��������� 
	printf("%d \n",*p++);   //�ȼ��� *��p++�����������Լ������ �� *��ָ��������������ȼ���ͬ 
	printf("%d \n",*++p);   //�ȼ��� *��++p�� 
	printf("%d \n",*p);	
	printf("%x \n",p);     //���ָ�����p�ĵ�ַ����ʮ�����Ʊ�ʾ�� 
	printf("%d \n",*p * 2); 
	return 0;
} 
