#include<iostream>
#include<algorithm> 
using namespace std;

struct abc{
		int i;int j;int k;
	}; 
bool cmp(int i,int j){return i>j;} //从大到小排列， return i<j; 从小到大排列 
bool cnp(abc a,abc b){ //从大到小排列，先比较 i 如果 i 相等，比较 j , 如果 j 相等，比较 k ,
	if(a.i!=b.i) return a.i>b.i;
	if(a.j!=b.j) return a.j>b.j;
	if(a.k!=b.k) return a.k>b.k;
}

int main(){
	abc a[3]={1,4,9,8,4,7,3,9,5};
	int arr[5]={1,5,4,3,2};
	sort(arr,arr+5,cmp); //系统默认为从从小到大排列 
	sort(a,a+3,cnp);
	for(int i=0; i<5; i++) cout<<arr[i]<<" ";
	for(int i=0; i<3; i++) cout<<endl<<a[i].i<<" "<<a[i].j<<" "<<a[i].k;
	return 0;
}
