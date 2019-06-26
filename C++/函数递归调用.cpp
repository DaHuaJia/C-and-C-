#include<iostream>
#include<cstring>
using namespace std;

string m;
string fun(string m){
	if(m.length()>1){
		int len=m.length();
		string ans=m.substr(1,len-2);
		return m.substr(len-1,len) + fun(ans) + m.substr(0,1);
	}else return m;
} //substr(start,end)是字符串截取函数，位于 cstring  ,截取从start 到 end 长度的字符。 

int main(){
	cin>>m;
	cout<<"原字符串为："<<m<<endl;
	cout<<"倒转后为："<<fun(m)<<endl;
	return 0; 
}
//通过递归调用，使字符串倒转 
