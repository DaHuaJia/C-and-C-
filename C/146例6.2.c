#include<stdio.h>
int main(){
	int i,a[40] = {1,1};
	for(i=2; i<40; i++){
		a[i] = a[i-1] + a[i-2];
	}
	for(i=0; i<40; i++){
		if(i%5 == 0 && i!=0) printf("\n");
		printf("%12d",a[i]);
	}
	printf("\n");
	return 0;
} 
