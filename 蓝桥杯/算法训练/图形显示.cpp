#include<iostream>
using namespace std;

int main(void){
	long long num,i;
	cin>>num;
	for(; num>0; num--){
		for(i=1; i<=num; i++) cout<<"* ";
		cout<<endl;
	}
	return 0;
} 
