#include<stdio.h>
main(){
	int k; 
	void fun(int k);
	printf("�����������������ǣ�");
	scanf("%d",&k);
	fun(k); 
	return 0;
} 
void fun(int k){
	int num[k][k],i,j;
	for(j=0; j<k; j++){
		num[j][0]=1;                                //���û�����ֵ 
		num[j][j]=1;
		for(i=0; i<=j; i++){
			num[j][i]=num[j-1][i]+num[j-1][i-1];    //������ǵ�ԭ�� 
			num[j][0]=1;                            //���ı�Ļ�����ֵ���û��� 
			num[j][j]=1;
			printf("%-6d",num[j][i]);
		}
		printf("\n");
	}
}

