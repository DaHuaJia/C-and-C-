#include<iostream> 
using namespace std;

int main(){
	int n,tmp;cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	//边读取，边排序，读取一个数，就进行排序。这样可以提高效率。	
		if(i!=0 && arr[i]<=arr[i-1])
			for(int j=i; j>0; j--)  
				if(arr[j]<=arr[j-1]){  
					tmp=arr[j];arr[j]=arr[j-1];arr[j-1]=tmp;
				}else break;
			
	}
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	return 0;
} //对于比较小的数据，可以采用冒泡法等进行排序，忽略效率的影响。 
