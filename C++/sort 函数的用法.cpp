#include<iostream>
#include<algorithm> 
using namespace std;

struct abc{
		int i;int j;int k;
	}; 
bool cmp(int i,int j){return i>j;} //�Ӵ�С���У� return i<j; ��С�������� 
bool cnp(abc a,abc b){ //�Ӵ�С���У��ȱȽ� i ��� i ��ȣ��Ƚ� j , ��� j ��ȣ��Ƚ� k ,
	if(a.i!=b.i) return a.i>b.i;
	if(a.j!=b.j) return a.j>b.j;
	if(a.k!=b.k) return a.k>b.k;
}

int main(){
	abc a[3]={1,4,9,8,4,7,3,9,5};
	int arr[5]={1,5,4,3,2};
	sort(arr,arr+5,cmp); //ϵͳĬ��Ϊ�Ӵ�С�������� 
	sort(a,a+3,cnp);
	for(int i=0; i<5; i++) cout<<arr[i]<<" ";
	for(int i=0; i<3; i++) cout<<endl<<a[i].i<<" "<<a[i].j<<" "<<a[i].k;
	return 0;
}
