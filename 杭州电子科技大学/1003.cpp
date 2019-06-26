#include<iostream>
#include<string>
using namespace std;

int main(){
	int num[100001]; //保存输入的数组 
	int N,i,j,k,sum /*累加和*/,st[20] /*起始地址*/,en[20] /*终止地址*/;
	long long int max[20] /*累加和的最大值*/;
	cin>>N;
	for(i=0; i<N; i++){
		cin>>num[0]; //保存数组的长度 
		k=1;sum=0;max[i]=-1001;  /*"归零" 防止上一次输入对本次运算造成影响*/
		for(j=1; j<=num[0]; j++){
			cin>>num[j];
			sum+=num[j];
			if(sum>max[i]){
				max[i]=sum;
				st[i]=k;en[i]=j;
			}
			if(sum<0){
				sum=0;
				k=j+1;
			}
		}
	}
	
	for(i=0; i<N; i++){
		cout<<"Case "<<i+1<<":"<<endl ;
		cout<<max[i]<<" "<<st[i]<<" "<<en[i]<<endl;
		if(i<N-1) cout<<endl; 
	}
	return 0;
} 
