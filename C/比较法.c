#include<stdio.h>
main(){
	int num[10],i,j,k;
	printf("input ten number: \n");
	for(i=0; i<10; i++){
		scanf("%d",&num[i]);           //获取这十个数字，并储存在num 数组中 
	}
	for(j=0; j<9; j++){              //一共比较九次 
		for(k=0; k<9-j; k++){       //找出最大的一个，把它放到还在比较的数列的最后 
			if(num[k] > num[k+1]){
				i=num[k+1];
				num[k+1]=num[k];
				num[k]=i;
			}
		}
	}
	printf("new ten number: \n");
	i=0;
	while(i<10){
		printf("%3d",num[i]);     //使用while输出数组 
		i++;
	}
	return 0;
} 
