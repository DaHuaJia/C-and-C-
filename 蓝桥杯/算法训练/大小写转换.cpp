#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	char arr[20];
	//scanf("%s",&arr);
	cin>>arr;
	int len=strlen(arr);
	for(int i=0; i<=len; i++){
		if(arr[i]>='A' && arr[i]<='Z') arr[i]+=32;
		else if(arr[i]>='a' && arr[i]<='z') arr[i]-=32;
	}
	//printf("%s",arr);
	cout<<arr;
	return 0;
} // a - A =32£» 
