#include<iostream>
using namespace std;

int main(){
	int x,y;
	cout<<"��Ҫ���뼸�м��еľ���"; cin>>x>>y; 
	cout<<"���������"<<endl;
	int num[x][y];
	for(int i=0; i<x; i++) for(int j=0; j<y; j++) cin>>num[i][j]; 
	cout<<"ת�ú�ľ���Ϊ��"<<endl;
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++) cout<<num[j][i]<<"  "; 
		cout<<endl;
	}
	return 0; 
}
