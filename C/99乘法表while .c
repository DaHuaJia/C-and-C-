#include<stdio.h>
int main()
{
	int i = 1,j = 1,k; 
	printf("¾Å¾Å³Ë·¨±í \n "); 
	printf(" \n ");
	while( i <= 9 && j <= 9){
		while(i <= j){
			k = i * j;
			printf("%d * %d = %2d   ",i,j,k);
			i ++;
		}
		printf(" \n ");
		j ++;
		i = 1;
	} 
	return 0;
} 
 
