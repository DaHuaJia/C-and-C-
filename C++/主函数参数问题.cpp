#include<iostream>
using namespace std;

main(int argc,char *argv[]){
	//C语言允许主函数带有参数，有且只能带有两个参数，一个是整形变量，一个是数组。
	//主函数的参数由操作系统传入，现有的操作系统都是图形化的，参数的传入都是隐藏起来的。可以借助cmd定义传入参数 
	int i=0;
	cout<<"你输入给主函数的参数为："<<endl;
	cout<<argc;
	while(argv[i]!='\0'){
		cout<<argv[i]<<endl;
		i++; 
	} 
	return 0;
} 
