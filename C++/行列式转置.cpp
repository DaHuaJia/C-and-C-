#include<iostream>
using namespace std;

int main(){
	int x,y;
	cout<<"你要输入几行几列的矩阵："; cin>>x>>y; 
	cout<<"请输入矩阵："<<endl;
	int num[x][y];
	for(int i=0; i<x; i++) for(int j=0; j<y; j++) cin>>num[i][j]; 
	cout<<"转置后的矩阵为："<<endl;
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++) cout<<num[j][i]<<"  "; 
		cout<<endl;
	}
	return 0; 
}
