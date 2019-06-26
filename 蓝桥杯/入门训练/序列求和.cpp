#include<iostream>
using namespace std;
 
int main(){
	long long n; //long long int n（错误） 
	cin>>n;
	cout<<n*(n+1)/2; 
	return 0;
}
//处理大数据是，依靠循环暴力计算是错误，不但效率低下唉，而且，也无法储存。 
