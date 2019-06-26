#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student{        //用户自定义的结构体变量 
	long num;     
	float score;      
	struct Student *next;     
};
int n;		
struct Student *creat(void){       //此函数为返回一个指向链表头的指针 
	struct Student *head;  
	struct Student *p1,*p2;  
	n = 0;   
	p1=p2=(struct Student *)malloc(LEN);     //开辟一个新的单元
	scanf("%ld,%f",&p1.num,&p1.score);       //malloc 是一种分配指定长度的内存块函数 
	head=NULL;  
	while(p1.num!=0){
		n++;    
		if(n==1) head=p1;     
		else p2.next=p1;        
		p2=p1;     
		p1=(struct Student *)malloc(LEN);     //开辟一个动态的存储区，把起始地址赋值给p1 
		scanf("%ld,%f",&p1.num,&p1.score);        
	}     
	p2.next=NULL;      
	renturn (head);	      
};      
        // 可以写一个main主函数调用这个creat函数 
int main(){   
	struct Student *pt;    
	pt=creat();    
	printf("\nnum:%ld \nscore:%5.1f\n",pt.num,pt.score);     
	return 0;   
}    
