#include<stdio.h>
#include<math.h>
main(){
	double sqrtnum,num;
	printf("Please input smaller number than 1000:");
	scanf("%lf",&num);
	while(1){
		if(num<1000 && num>0) break;
		else {
			printf("\nPlease input smaller number than 1000:");
			scanf("%lf",&num);
		}
	}
	sqrtnum = sqrt(num);
	printf("The sqrtnum is:%lf",sqrtnum);
} 
