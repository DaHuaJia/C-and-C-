#include<iostream>
#include <iomanip>
using namespace std;

int main(){
	double en=0,sum=1.0;
	int n=0,i,j;
	cout<<"n"<<" "<<"e"<<endl;
	cout<<"-"<<" "<<"-----------"<<endl;
	while(n<10){
		cout<<n<<" ";
		j=n;
		while(j>=0){
			for(i=j; i>0; i--){
				sum*=i;
			}
			en+=(1.0/sum); sum=1; j--;
		}
		if(n==8) cout<<setprecision(10)<<en<<"0"<<endl; //n=8,�޷�������Ӧ�ľ��� 
		else cout<<setprecision(10)<<en<<endl; //���ƾ�ȷ���λ�� 
		en=0; n++;
	}	
	return 0;
} 
