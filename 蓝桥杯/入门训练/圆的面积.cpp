#include<iostream>
#include<cmath>
#include<iomanip> 
using namespace std;

int main(){
	int r;double s;
	cin>>r;
	const long double pi=atan(1.0)*4;
	s=pi*r*r;
	cout<<setprecision(7)<<fixed<<s;
	return 0;
}
