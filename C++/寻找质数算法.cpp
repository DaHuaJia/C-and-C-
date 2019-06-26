#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int i,j,flap;
	for(i=2; i<=100; i++){
		flap=1;
		for(j=2; j<=sqrt(i); j++){
			if(i%j==0){
				flap=0;break;
			}
		}
		if(flap==1){
			cout.width(4);
			cout<<i<<" ÊÇÖÊÊý\n";
		}
	}
	return 0;
} 
