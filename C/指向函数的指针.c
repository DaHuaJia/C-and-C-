#include<stdio.h>
	int max(int,int);        //设置全局变量 
	int min(int,int);
	int (*p)(int,int);
	int a,b,c,n;
int main(){
	void fun();
	printf("please enter a and b: ");
	scanf("%d,%d",&a,&b);        //设置比较的值 
	fun();                       //选择比较方式 
	c=(*p)(a,b);
	printf(" \na=%d,b=%d \n",a,b);
	if(n==1) printf("max is %d \n",c);
	else printf("min is %d \n",c);
	return 0;
}

	void fun(){
		printf("please choose 1 way or 2 way:");
		scanf("%d",&n);
		if(n==1) p=max;
		else if(n==2) p=min;
		 	 else{
		 		printf("\ninput is errer! \n ");
		 		fun();
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
	
	
