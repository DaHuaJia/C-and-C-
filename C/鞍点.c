#include<stdio.h>
main(){
	int num[2][4],arrmax[2],i,j,max,btn,k=0;
	printf("����һ��2*4�Ķ�ά���飺"); 
	for(j=0; j<2; j++){
		for(i=0; i<4; i++){
			scanf("%d",&num[j][i]);
		}
	}
	printf("\n");
	for(j=0; j<2; j++){
		for(i=0; i<4; i++){
			printf("%4d",num[j][i]);
		}
		printf("\n");
	}
	do{
		for(j=0; j<2; j++){
			for(i=1; i<4; i++){
				max=num[j][0];
				if(num[j][0]<num[j][i]){
					max=num[j][i];
					btn=i;
				}
			}
			if(num[j==1][btn]<num[j==0][btn]){
				arrmax[k]=max;
				k++;
			}
		}
	}while(j<2);
	printf("\n");
	switch(k){
		case 0:printf("�����鲻���ڰ��㣡");break;
		case 1:printf("���������һ������Ϊ��%d",arrmax[0]);break;
		case 2:printf("�����������������Ϊ��%d��%d",arrmax[0],arrmax[1]);break;
		default:printf("�������"); 
	}
	return 0;
} 

