#include<stdio.h>
int main(){
	int a,b,c,z,i;
	scanf("%d,%d,%d",&a,&b,&c);
	if(a > b) i = a;
	else i = b;
	if(i > c) z = i;
	z = c;
	printf("this is %d",z);
	return 0;
} 
