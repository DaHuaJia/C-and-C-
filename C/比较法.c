#include<stdio.h>
main(){
	int num[10],i,j,k;
	printf("input ten number: \n");
	for(i=0; i<10; i++){
		scanf("%d",&num[i]);           //��ȡ��ʮ�����֣���������num ������ 
	}
	for(j=0; j<9; j++){              //һ���ȽϾŴ� 
		for(k=0; k<9-j; k++){       //�ҳ�����һ���������ŵ����ڱȽϵ����е���� 
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
		printf("%3d",num[i]);     //ʹ��while������� 
		i++;
	}
	return 0;
} 
