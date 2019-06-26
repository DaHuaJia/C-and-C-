#include<stdio.h>
main(){
	int num[2][4],arrmax[2],i,j,max,btn,k=0;
	printf("输入一个2*4的二维数组："); 
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
		case 0:printf("该数组不存在鞍点！");break;
		case 1:printf("该数组存在一个鞍点为：%d",arrmax[0]);break;
		case 2:printf("该数组存在两个鞍点为：%d、%d",arrmax[0],arrmax[1]);break;
		default:printf("程序错误！"); 
	}
	return 0;
} 

