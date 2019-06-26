#include<iostream>
using namespace std;

void fun(int num[],int n){
	int count=0;
	for(int i=0; i<n; i++)
		if(num[i]!=0) count++;
	cout<<count<<endl;
	for(int i=0; i<n; i++){
		if(num[i]!=0) cout<<num[i]<<" ";
	}
}

int main(void){
	int n;cin>>n;
	int* num=new int[n];
	for(int i=0; i<n; i++) cin>>num[i];
	fun(num,n);
	return 0;
}
