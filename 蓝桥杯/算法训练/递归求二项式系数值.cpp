#include<iostream>
using namespace std;

int fun(long long n,long long m){
	if(m==n || n==0) return 1;
	else return fun(n,m-1) + fun(n-1,m-1);
} //用函数的递归调用 

int main(){
	long long m,n;
	cin>>n>>m;
	cout<<fun(n,m);
	return 0;
}









/*
int main(){
	long long int m,n,a=1,b=1;
	cin>>m>>n;
	for(int i=0; i<m; i++) a*=(n-i);
	for(int i=m; i>=1; i--) b*=i;
	cout<<a/b;
	return 0;
}  //采用循环，用数学公式求解。 
*/ 
