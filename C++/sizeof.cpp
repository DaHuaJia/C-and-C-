#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int i=8;
	float j;      //关于sizeof的用法 
	char k;
	cout<<sizeof(i=1)<<'\t'<<i<<'\t'<<sizeof(k)<<endl;
	cout<<setw(5)<<setprecision(4)<<3.1415<<endl;  //setw域宽    setprecision  设置浮点小数的位数（小数点占一位） 
	return 0;   
} 
