#include<iostream>
using namespace std;

//Fibonacci���� 
int main(){
	int i=1,j=1,sum=1,n;
	cin>>n;
	for(int k=3; k<=n; k++){
		sum=(i+j)%10007;  //�ص㣺�Ⱥ����࣬�Խ����û��̫���Ӱ�졣 
		i=j;j=sum;
	}
	cout<<sum;
	return 0;
} 
//���n ���󣬾ͻ���� sum���������ɽ����׼ȷ�� 
