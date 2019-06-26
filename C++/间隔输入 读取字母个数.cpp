#include<iostream>
#include<cstdio>
using namespace std;

void fun(char *m){
	int k=0;
	for(int i=0; m[i]; i++){
		if(m[i]>'a' && m[i]<'z') k++;
		else if(m[i]>'A' && m[i]<'Z') k++;
	}
	cout<<"字母的个数为："<<k; 
}
int main(){
	char m[100];
	gets(m);
	fun(m);
	return 0;
}//统计字母的个数，难点在于输入会产生空格，中断输入流的输入，如果采用 gets 就不能使用string  
