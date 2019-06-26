#include<iostream>
using namespace std;

//Fibonacci数列 
int main(){
	int i=1,j=1,sum=1,n;
	cin>>n;
	for(int k=3; k<=n; k++){
		sum=(i+j)%10007;  //重点：先后求余，对结果并没有太大的影响。 
		i=j;j=sum;
	}
	cout<<sum;
	return 0;
} 
//如果n 过大，就会造成 sum的溢出，造成结果不准确。 
