#include<iostream>
using namespace std;

int main(){
	long long int ten;int i;
	string sixteen=""; //��ʼ�� 
	cin>>ten;
	if(ten==0)sixteen+='0'; //�ж��Ƿ�Ϊ 0 
	for(i=0; ten!=0; i++){
		if(ten%16<=9) sixteen+=(char)(ten%16+48);//ת���� �ַ� 
		else if(ten%16>9) sixteen+=(char)(ten%16+55);
		ten=ten/16; 
	}
	i=sixteen.length();
	for(i=i-1; i>=0; i--){
		cout<<sixteen[i];
	}
	return 0;
} //������ʽ����ķ��� 
