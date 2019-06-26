#include<iostream>
using namespace std;

int main(){
	int i,a=1,b=0;
	int num[20],m1;
	cin>>i;
	if(i<=0) return 0; //如果i<=0 不用输出 
	for(int k=0; k<i; k++) cin>>num[k];
	m1=num[0];
	for(int j=1; j<i; j++){
		if(num[j]==num[j-1]) b++;
		else b=1;
		if(b>a){
			a=b;m1=num[j];
		}
	}
	cout<<m1;
	return 0;
} 
