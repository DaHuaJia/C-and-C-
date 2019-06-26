#include<iostream>
#include<string>
using namespace std;

int main(){
	int num,len1,len2,j,max,k=0,i=0;
	cin>>num;
	string ans1[20],ans2[20],ans; //用string类接收数据，防止溢出 
	while(i<num){
		cin>>ans1[i]>>ans2[i];
		i++;
	} 
	i=0;
	while(i<num){
		len1=ans1[i].length();
		len2=ans2[i].length();
		while(len1>0 || len2>0){
			if(len1<=0) j=ans2[i][len2-1]; //末位对齐相加。 
			else if(len2<=0) j=ans1[i][len1-1];
				 else j=ans1[i][len1-1]+ans2[i][len2-1]-48; //0 的ASCII码是48 
			if(j<=57){ 
				if(k==1 && j==57) { //满十进一 
					ans+=48;
					k=1;
				}else {
					ans+=(j+k);
					k=0;
				}
			}
			else{
				j-=10;  //满十进一，剩下的加上前一位的进位 
				ans+=(j+k);
				k=1;
			}
			len1--;len2--;	//从右至左遍历 
		} 
		if(k==1){
			 ans+='1';k=0;  //遍历完成之后，如果左边第一位依然有进位，需要再加一 
		}
		len1=ans.length();
		cout<<"Case "<<i+1<<":"<<endl;
		cout<<ans1[i]<<" + "<<ans2[i]<<" = ";
		while(len1>=0){
			len1--;
			cout<<ans[len1]; //从右到左输出 
		}
		i++;ans="";
		if(i<num) cout<<endl<<endl;
		else cout<<endl;
	}
	return 0;
}
