#include<stdio.h>
main(){
 	int a=0,b,i,j,k,n;
	int fun(int n);
	printf("请输入要求的各个位数上的和：");
	scanf("%d",&n);
	for(b=100; b<=999; b++){
		i=b/100;   //百位 
		j=(b-i*100)/10;   // 十位 
		k=b%10;      //个位 
		if(n==i+j+k){
			printf(" %d ",b);
			a++;
		}
	}
	printf("\n一共有%d个这样的数。",a);
	return 0; 
} 
