#include<iostream>
using namespace std;

int main(){
	int n,m,a,b,j;
	cin>>n;cin>>m;
	char arr[n][m];
	for(int i=0; i<n; i++){ //i 控制行数 
		for(j=0,b=0,a=i; j<m; j++){ //j 控制每行输出个数  a 控制输出的字母类型，通过 65+a实现  
			if(b==0 && a<=i){ 
				cout<<char(65+a);  //A的ascii码是65 
				if(a==0){b=1;a+=2;} //a+2 是为了和下面的a--抵消一个数，同时避免重复输出 A 
				a--;
			}else if(b==1){ cout<<char(65+a);a++; }
		}
		cout<<endl;
	} 
	return 0;
}//字母图形，第 i 的第一个字母就是 字母表中的第 i 个字母，先降序，再升序，一共输出 m 个 。 
//升序和降序的转折点就是输出 A 即 65+a =65 ,a=0,一旦判断a==0,就不再做降序，一直升序输出。 

/*
	for(i=0;i<n;i++){  
        for(j=0;j<m;j++){  
            k=abs(i-j);    //abs是求绝对值   
            printf("%c",a[k]);  
        }  
        printf("\n");  
    }  
*/ 
