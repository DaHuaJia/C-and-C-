#include<iostream>
#include<cstdio>
using namespace std;

void fun(char *m){
	int k=0;
	for(int i=0; m[i]; i++){
		if(m[i]>'a' && m[i]<'z') k++;
		else if(m[i]>'A' && m[i]<'Z') k++;
	}
	cout<<"��ĸ�ĸ���Ϊ��"<<k; 
}
int main(){
	char m[100];
	gets(m);
	fun(m);
	return 0;
}//ͳ����ĸ�ĸ������ѵ��������������ո��ж������������룬������� gets �Ͳ���ʹ��string  
