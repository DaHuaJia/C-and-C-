#include <stdio.h>  
#include<stdlib.h>
int main()  
{  
	int i;
	printf("fjsdklfjds");
    //将投票数据保存到file1.txt磁盘文件中   
    FILE *fpWrite=fopen("file1.txt","w");  
    if(fpWrite==NULL)  
    {  
        printf("无法打开文件\n");
		exit(0);  
    }  
   	int abc[10]={2,3,21,23,4,5,6,7,67,54};
   	for(i=0; i<10; i++){
   		fprintf(fpWrite,"%d ",abc[i]); 
	} 
    fclose(fpWrite);  
    //从file1.txt磁盘文件中读出投票数据  
    int a[10]={0};  
    FILE *fpRead=fopen("file1.txt","r");  
    if(fpRead==NULL)  
    {  
        printf("无法打开文件\n");
		exit(0);  
    }  
    for(i=0;i<10;i++)  
    {  
        fscanf(fpRead,"%d ",&a[i]);  
        printf("%d ",a[i]);  
    }  
    getchar();//等待  
    return 1;  
}  

