#include<stdio.h>
main(){
 	int a=0,b,i,j,k,n;
	int fun(int n);
	printf("������Ҫ��ĸ���λ���ϵĺͣ�");
	scanf("%d",&n);
	for(b=100; b<=999; b++){
		i=b/100;   //��λ 
		j=(b-i*100)/10;   // ʮλ 
		k=b%10;      //��λ 
		if(n==i+j+k){
			printf(" %d ",b);
			a++;
		}
	}
	printf("\nһ����%d������������",a);
	return 0; 
} 
