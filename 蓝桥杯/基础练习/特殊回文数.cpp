#include<iostream>
#include<cstdlib> 
using namespace std;

int main(){
	int n,m;
	char str[10];
	long int num;
	cin>>n;
	for(num=10001; num<1000000; num++){
		itoa(num,str,10);//������ת�����ַ��������� 
		if(num<100000){
			m=str[0]+str[1]+str[2]+str[3]+str[4]-48*5;
			if(n==m && str[0]==str[4] && str[1]==str[3]) cout<<num<<endl;
		}else if(num>=100000){
			m=str[0]+str[1]+str[2]+str[3]+str[4]+str[5]-48*6;
			if(n==m && str[0]==str[5] && str[1]==str[4] && str[2]==str[3])cout<<num<<endl;
		}
	}
	return 0;
} //������Ҫ�ǲ���ѭ�����Ҹտ�ʼ��Ϊ���ܲ���ѭ������ �����ķ��������ÿ���ʹ�ü��ɡ� 
