#include<iostream>
using namespace std;

int main(){
	long long int a,b,c,d;
	cin>>a>>b;
	d=a*b;
	do{
		c=a%b;
		a=b;b=c;
	}while(c!=0);
	cout<<d/a;
	return 0;
} //�������������� շת�����  Ȼ�� ��С������ = ����֮�� / �������
//���⣬�������������ٷ� �ڲ����ղ� 
 
