#include<iostream>
using namespace std;

int main(){
	int a,b,n,i;
	int f[51];  // mod7之后，f(i-1)和f(i-2)各有7种情况，且a,b为固定值，所以，一共有49种情况。 
	while(1){ //循环为49，因此，f(49)和f(51)重复。 
		cin>>a>>b>>n; if(a==0) break;
		f[0]=1;f[1]=1;
		for(i=2; i<51; i++){ //计算循环体的值 
			f[i]=(a*f[i-1]+b*f[i-2])%7;
		}
		for(i=0; i<49; i++){ //通过重复值找到循环体 
			if(f[49]==f[i] && f[50]==f[i+1]) break;
		}
		n=(n+i-2)%49; //对于这个公式，不太懂 
		cout<<f[n]<<endl;
	}
	return 0;
}
//该题能采用递归，内存会超限，将一次递归分解成多次递归也不行，n值太大。
//采用循环覆盖也不行，时间会超限。 




