#include<stdio.h>
#include<math.h>
int main(){
	float p,r = 0.1,n;
	printf("ÇëÊäÈënµÄÖµ£¬n = ");
	scanf("%f",&n);
	getchar(); 
	p = pow(1+r,n);
	printf("p = %f \n",p);
	return 0;
} 
