#include<iostream>
using namespace std;

int main(){
	int n,m,i;cin>>n;
	int arr[n];
	for(i=0; i<n; i++) cin>>arr[i];
	cin>>m;
	for(i=0; i<n; i++){
		if(arr[i]==m){cout<<i+1;return 0;}
	}
	if(i==n)cout<<-1; //循环结束后，i 其实是多加了 1 的 
	return 0;
} //查找整数 
