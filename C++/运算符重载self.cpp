#include<iostream>
using namespace std;

enum weekday{sunday,monday,tuesday,wednesday,thursday,friday,saturday};

float operator + (const weekday &a,const weekday &b){
	return 66.88;
}

int main(){
	weekday i=monday,k=friday;
	cout<<i+k<<endl;
	cout<<i+monday<<endl;
	return 0;
}//��������ر������ ������ �� ö���ͱ��� 
