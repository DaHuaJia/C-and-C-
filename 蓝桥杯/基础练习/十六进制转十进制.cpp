#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int i=0,len;
	string sixteen;long long int ten=0;
	cin>>sixteen;
	len=sixteen.size();
	while(i<len){
			switch(sixteen[i]){
				case '0':break;
				case '1':ten+=1*pow(16,len-1-i);break;
				case '2':ten+=2*pow(16,len-1-i);break;
				case '3':ten+=3*pow(16,len-1-i);break;
				case '4':ten+=4*pow(16,len-1-i);break;
				case '5':ten+=5*pow(16,len-1-i);break;
				case '6':ten+=6*pow(16,len-1-i);break;
				case '7':ten+=7*pow(16,len-1-i);break;
				case '8':ten+=8*pow(16,len-1-i);break;
				case '9':ten+=9*pow(16,len-1-i);break;
				case 'A':ten+=10*pow(16,len-1-i);break;
				case 'B':ten+=11*pow(16,len-1-i);break;
				case 'C':ten+=12*pow(16,len-1-i);break;
				case 'D':ten+=13*pow(16,len-1-i);break;
				case 'E':ten+=14*pow(16,len-1-i);break;
				case 'F':ten+=15*pow(16,len-1-i);break;
				default:break;
			} i++;
		}
	cout<<ten;
	return 0;
} /*
	16�������ĵ�0λ��ȨֵΪ16��0�η�����1λ��ȨֵΪ16��1�η�����2λ��ȨֵΪ16��2�η�����
	������ʽ������㷨 ��
	��0λ�� 5 * 16^0 = 5
	��1λ�� F * 16^1 = 240
	��2λ�� A * 16^2= 2560
	��3λ�� 2 * 16^3 = 8192
	-------------------------------------
	10997
	ֱ�Ӽ�����ǣ�
	5 * 16^0 + F * 16^1 + A * 16^2 + 2 * 16^3 = 10997 
*/
