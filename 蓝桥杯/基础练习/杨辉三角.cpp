#include<iostream>
using namespace std;

int main(){
	int n;cin>>n;
	long int num[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0 || j==i) num[i][j]=1; //����������Ϊ 1 
			else num[i][j]=num[i-1][j-1]+num[i-1][j]; //������ǵ����� 
			cout<<num[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
