#include<iostream>
#include<string>
using namespace std;

int main(){
	int num[100001]; //������������� 
	int N,i,j,k,sum /*�ۼӺ�*/,st[20] /*��ʼ��ַ*/,en[20] /*��ֹ��ַ*/;
	long long int max[20] /*�ۼӺ͵����ֵ*/;
	cin>>N;
	for(i=0; i<N; i++){
		cin>>num[0]; //��������ĳ��� 
		k=1;sum=0;max[i]=-1001;  /*"����" ��ֹ��һ������Ա����������Ӱ��*/
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
