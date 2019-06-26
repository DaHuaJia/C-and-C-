#include<stdio.h>
int main(){
	int max(int a,int b);
	int a,b,c;
	scanf("%d,%d",&a,&b);
	c = max(a,b);
	return c;
} 
int max(int a,int b){
	int z;
	if(a > b)z = a;
	else z = b;
	return (z);
}
