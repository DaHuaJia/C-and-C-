#include <stdio.h>  
#include<stdlib.h>
int main()  
{  
	int i;
	printf("fjsdklfjds");
    //��ͶƱ���ݱ��浽file1.txt�����ļ���   
    FILE *fpWrite=fopen("file1.txt","w");  
    if(fpWrite==NULL)  
    {  
        printf("�޷����ļ�\n");
		exit(0);  
    }  
   	int abc[10]={2,3,21,23,4,5,6,7,67,54};
   	for(i=0; i<10; i++){
   		fprintf(fpWrite,"%d ",abc[i]); 
	} 
    fclose(fpWrite);  
    //��file1.txt�����ļ��ж���ͶƱ����  
    int a[10]={0};  
    FILE *fpRead=fopen("file1.txt","r");  
    if(fpRead==NULL)  
    {  
        printf("�޷����ļ�\n");
		exit(0);  
    }  
    for(i=0;i<10;i++)  
    {  
        fscanf(fpRead,"%d ",&a[i]);  
        printf("%d ",a[i]);  
    }  
    getchar();//�ȴ�  
    return 1;  
}  

