#include<iostream>
using namespace std;

int main(){
	int n;cin>>n;
	for(int i=1; i<=9; i++){
		for(int j=0; j<=9; j++){
			for(int k=0; k<=9; k++){
				if(n==2*i+2*j+k) cout<<i*10001+j*1010+k*100<<endl;//�ص� 
			} //�����ҶԳƷֽ�� a*10001��˼�롣 
		}
	}
	for(int i=1; i<=9; i++){
		for(int j=0; j<=9; j++){
			for(int k=0; k<=9; k++){
				if(n==2*(i+j+k)) cout<<i*100001+j*10010+k*1100<<endl;
			}
		}
	}
	return 0;
} //����������������ñ����ķ�������ŷ���ƻ��ķ�����
 
