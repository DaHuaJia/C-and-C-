#include<stdio.h>
int main()
{
	float a,b;
	printf("请输入要比较的数字!10个\n");
	scanf("%f",&a);
	for (int i = 0; i < 9; i++)
	{
		scanf("%f", &b);
		if (a < b) {
			a = b;
		}
	}
	printf("最大值为%f",a);
	return 0;
} 

 
