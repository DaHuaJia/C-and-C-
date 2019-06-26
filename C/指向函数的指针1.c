#include<stdio.h>
int (*p)(int,int);
char *way;
int main(){
	void judge();
	int A,B,i;
	printf("please enter numble A and B:");
	scanf("%d %d",&A,&B);
	judge(); 
	printf("\n \n \n");
	printf("You input two numble is:%d %d",A,B);
	i=(*p)(A,B);
	printf("\nThe %s is:%d",way,i);
	return 0;
} 

void judge(){
	int w,max(int,int),min(int,int),add(int,int);
	printf("please choose way:");
	scanf("%d",&w);
	switch(w){
		case 1: p=max;way="max";break;
		case 2: p=min;way="min";break;
		case 3: p=add;way="add";break;
		default:printf("errer! this way undefind!\n");judge();
	}
}

int max(int x,int y){
	int z;
	if(x>y) z=x;
	else z=y;
	return (z);
}

int min(int x,int y){
	int z;
	if(x>y) z=y;
	else z=x;
	return (z);
}

int add(int x,int y){
	int z = x + y;
	return (z);
}
