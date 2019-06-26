#include<stdio.h>
main(){
	int k; 
	void fun(int k);
	printf("你想输出几行杨辉三角：");
	scanf("%d",&k);
	fun(k); 
	return 0;
} 
void fun(int k){
	int num[k][k],i,j;
	for(j=0; j<k; j++){
		num[j][0]=1;                                //设置基本数值 
		num[j][j]=1;
		for(i=0; i<=j; i++){
			num[j][i]=num[j-1][i]+num[j-1][i-1];    //杨辉三角的原理 
			num[j][0]=1;                            //将改变的基本数值设置回来 
			num[j][j]=1;
			printf("%-6d",num[j][i]);
		}
		printf("\n");
	}
}

