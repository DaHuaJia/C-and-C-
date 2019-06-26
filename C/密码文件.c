#include<stdio.h>
main(){
	char str[50],unstr[50];
	int i=0;
	printf("please input array:");
	scanf("%s",&str);
	for(;i<50;i++){
		if(str[i]>='A' && str[i]<='Z') unstr[i]=92-(str[i]-65);
		else if(str[i]>='a' && str[i]<='z') unstr[i]=122-(str[i]-97);
			 else unstr[i]=str[i];	
	}
	printf("\n密码文件为：%s",str);
	printf("\n译文文件为：%s",unstr);
} 
