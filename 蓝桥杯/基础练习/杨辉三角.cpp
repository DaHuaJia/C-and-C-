#include<iostream>
using namespace std;

int main(){
	int n;cin>>n;
	long int num[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0 || j==i) num[i][j]=1; //将两边设置为 1 
			else num[i][j]=num[i-1][j-1]+num[i-1][j]; //杨辉三角的性质 
			cout<<num[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
