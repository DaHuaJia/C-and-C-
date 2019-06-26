#include<stdio.h>
int main(){
	int min(int a,int b);
	int a,b,c;
	scanf("%d,%d",&a,&b);
	c = min(a,b);
	return c;
} 
int min(int a,int b){
	int z;
	if(a > b)z = b;
	else z = a;
	return (z);
}
