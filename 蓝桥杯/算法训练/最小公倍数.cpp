#include<iostream>
using namespace std;

int main(){
	long long int a,b,c,d;
	cin>>a>>b;
	d=a*b;
	do{
		c=a%b;
		a=b;b=c;
	}while(c!=0);
	cout<<d/a;
	return 0;
} //最大公因数计算采用 辗转相除法  然后 最小公倍数 = 两数之积 / 最大公因数
//此外，还有相减法，穷举法 在博客收藏 
 
