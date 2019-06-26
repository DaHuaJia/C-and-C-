#include<iostream>
using namespace std;

int main(){
	int n,max,min,sum=0;cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i]; sum+=arr[i];
		if(i==0) max=min=arr[i];
		if(arr[i]>=max) max=arr[i];
		else if(arr[i]<=min) min=arr[i];
	}
	cout<<max<<endl<<min<<endl<<sum;
	return 0;
} //ÊýÁÐÌØÕ÷ 
