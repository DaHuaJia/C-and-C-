#include<iostream>
using namespace std;

int main(){
	enum color{red,yellow,blue,white,black} pri;
	int n=0,i,j,k,loop;
	char c;
	for(i=red; i<=black; i++){
		for(j=red; j<=black; j++){
			if(i!=j){
				for(k=red; k<=black; k++){
					if(k!=i && k!=j){
						n++; cout.width(4);
						cout<<n;
						for(loop=1; loop<=3; loop++){
							switch(loop){
								case 1:pri=(enum color)i;break;
								case 2:pri=(enum color)j;break;
								case 3:pri=(enum color)k;break;
								default:break;
							}
							switch(pri){
								case red:cout<<"   red";break;
								case yellow:cout<<"   yellow";break;
								case blue:cout<<"   blue";break;
								case white:cout<<"   white";break;
								case black:cout<<"   black";break;
								default:break;
							}
						}
						cout<<endl;
					}
					
				}
				
			}
		}
	}
	cout<<"total:"<<n<<endl;
	return 0; 
} 
// 口袋中有 红 黄 蓝 白 黑 五种颜色的球，每次从口袋中取出三个不同颜色的球，有多少种取法？ 
