#include<iostream>
#include<cmath> 
using namespace std;

int main(){
	int len;
	string a;long long b=0;
	cin>>a;
	len=a.length();
	
	for(int i=0; a[i]!='\0'; i++) b+=(a[i]-'0')*pow(8,len-i-1);
	
	cout<<b;
	return 0;
}//八进制转十进制 
