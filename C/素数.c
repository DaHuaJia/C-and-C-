#include<stdio.h>
#include<string.h>
int main(){
	void fun(char array[]);
	char str[100];
	printf("input string:");
	scanf("%s",&str);
	fun(str);
	printf("inverse string:%s \n",str);
	return 0;
} 

void fun(char array[]){
	char t;
	int i,j;
	for(i=0,j=strlen(array); i<(strlen(array)/2); i++,j--){
		t=array[i];
		array[i]=array[j-1];
		array[j-1]=t;
	}
}
