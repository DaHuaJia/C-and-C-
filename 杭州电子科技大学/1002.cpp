#include<iostream>
#include<string>
using namespace std;

int main(){
	int num,len1,len2,j,max,k=0,i=0;
	cin>>num;
	string ans1[20],ans2[20],ans; //��string��������ݣ���ֹ��� 
	while(i<num){
		cin>>ans1[i]>>ans2[i];
		i++;
	} 
	i=0;
	while(i<num){
		len1=ans1[i].length();
		len2=ans2[i].length();
		while(len1>0 || len2>0){
			if(len1<=0) j=ans2[i][len2-1]; //ĩλ������ӡ� 
			else if(len2<=0) j=ans1[i][len1-1];
				 else j=ans1[i][len1-1]+ans2[i][len2-1]-48; //0 ��ASCII����48 
			if(j<=57){ 
				if(k==1 && j==57) { //��ʮ��һ 
					ans+=48;
					k=1;
				}else {
					ans+=(j+k);
					k=0;
				}
			}
			else{
				j-=10;  //��ʮ��һ��ʣ�µļ���ǰһλ�Ľ�λ 
				ans+=(j+k);
				k=1;
			}
			len1--;len2--;	//����������� 
		} 
		if(k==1){
			 ans+='1';k=0;  //�������֮�������ߵ�һλ��Ȼ�н�λ����Ҫ�ټ�һ 
		}
		len1=ans.length();
		cout<<"Case "<<i+1<<":"<<endl;
		cout<<ans1[i]<<" + "<<ans2[i]<<" = ";
		while(len1>=0){
			len1--;
			cout<<ans[len1]; //���ҵ������ 
		}
		i++;ans="";
		if(i<num) cout<<endl<<endl;
		else cout<<endl;
	}
	return 0;
}
