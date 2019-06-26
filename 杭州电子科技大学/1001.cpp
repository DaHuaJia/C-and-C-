#include<iostream>
using namespace std;

int main(){
	int n;
	while(cin>>n) cout<<1ll*(n+1)*n/2<<endl<<endl; 
	return 0;
} //不知道1ll是什么东西，不过这样可以防止cout溢出 
//cout的缓存应该是有一个栈用来缓存，这个栈的大小可能和参与运算的数据类型有关。 
