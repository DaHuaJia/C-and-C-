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
} //substr(start,end)���ַ�����ȡ������λ�� cstring  ,��ȡ��start �� end ���ȵ��ַ��� 

int main(){
	cin>>m;
	cout<<"ԭ�ַ���Ϊ��"<<m<<endl;
	cout<<"��ת��Ϊ��"<<fun(m)<<endl;
	return 0; 
}
//ͨ���ݹ���ã�ʹ�ַ�����ת 
