#include<stdio.h>
int main(){
	int dgt[4]={1,12,123,1234};
	int *p=dgt;
	printf("%d \n",*p); 
	printf("%d \n",++*p);    //等价于  ++（*p） ;右结合性，从右往左看 
	printf("%d \n",*p++);   //等价于 *（p++）；自增、自减计算符 和 *（指针运算符）的优先级相同 
	printf("%d \n",*++p);   //等价于 *（++p） 
	printf("%d \n",*p);	
	printf("%x \n",p);     //输出指针变量p的地址。用十六进制表示。 
	printf("%d \n",*p * 2); 
	return 0;
} 
