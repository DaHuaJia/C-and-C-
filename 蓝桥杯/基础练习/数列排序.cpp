#include<iostream> 
using namespace std;

int main(){
	int n,tmp;cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	//�߶�ȡ�������򣬶�ȡһ�������ͽ������������������Ч�ʡ�	
		if(i!=0 && arr[i]<=arr[i-1])
			for(int j=i; j>0; j--)  
				if(arr[j]<=arr[j-1]){  
					tmp=arr[j];arr[j]=arr[j-1];arr[j-1]=tmp;
				}else break;
			
	}
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	return 0;
} //���ڱȽ�С�����ݣ����Բ���ð�ݷ��Ƚ������򣬺���Ч�ʵ�Ӱ�졣 
