#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n,b[1000],i,j,max;
    char a[1000][16];
    while(1){
    	cin>>n; if(n==0) break;
        for(i=0; i<n; i++) cin>>a[i];
        max=0; // 一次样例结束后，要对公用的变量恢复原来的值 
        for(i=0;i<n;i++){
            b[i]=0;
            for(j=i+1;j<n;j++) if(strcmp(a[i],a[j])==0) b[i]++;
            if(b[i]>max) max=b[i];
        }
        for(i=0;i<n;i++){
            if(b[i]==max) cout<<a[i]<<endl;
        }
    }
    return 0;
}

