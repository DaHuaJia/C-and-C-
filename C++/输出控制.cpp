#include<stdio.h>
int main()
{
	int clas =161;
	float height =45;
	char b='cm';
	char isfat='y';
	printf("姓名：慕课网\n");
	printf("学校：江西理工大学应用科学学院\n");
	printf("班级：通信%d班\n",clas);/*这是字符串%d的使用*/
	printf("身高：%f%c\n",height,b);/*这是字符串%C和%f的使用*/ 
	printf("%s\n","体重：56kg");/*这是字符串%s的使用*/ 
	printf("是否属于肥胖儿童：%c\n",isfat);
	return 0;
}
