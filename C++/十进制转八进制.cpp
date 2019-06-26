#include<iostream>
using namespace std;

int main(){
	int i,j;
	long long int a;
	string b="";
	cin>>a; 
	while(a!=0){
		i=a%8;
		a=a/8;
		switch(i){
			case 0:b+='0';break;
			case 1:b+='1';break;
			case 2:b+='2';break;
			case 3:b+='3';break;
			case 4:b+='4';break;
			case 5:b+='5';break;
			case 6:b+='6';break;
			case 7:b+='7';break;
			default:break; 
		}
	}
	j=b.length()-1;
	for(; j>=0; j--){
		cout<<b[j];
	}
	return 0;
}//十进制转八进制 
