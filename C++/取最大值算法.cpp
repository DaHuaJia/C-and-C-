#include<stdio.h>
int main()
{
	float a,b;
	printf("������Ҫ�Ƚϵ�����!10��\n");
	scanf("%f",&a);
	for (int i = 0; i < 9; i++)
	{
		scanf("%f", &b);
		if (a < b) {
			a = b;
		}
	}
	printf("���ֵΪ%f",a);
	return 0;
} 

 
