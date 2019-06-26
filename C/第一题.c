#include<stdio.h>
int main(){
	int num[20]={1,1},i,add; 
	for(i=2; i<20; i++){
		num[i] = num[i-1] + num[i-2];
	}
	for(i=0; i<20; i++){
		add += num[i];
		printf("%d,",num[i]);
	}
	printf("\n %d",add);
    return 0; 
}
