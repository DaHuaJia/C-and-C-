#include<iostream>
using namespace std;

int main(){
	int n,m;cin>>n;
	string a,b;  //�����������飬���㴢���㹻�����  
	for(int i=0; i<n; i++){
		cin>>a;
		b="";  //��ʼ������� b �е����� 
		for(int j=0; j<a.length(); j++){
			switch(a[j]){
				case '0':b+="0000";break;
				case '1':b+="0001";break;
				case '2':b+="0010";break;
				case '3':b+="0011";break;
				case '4':b+="0100";break;
				case '5':b+="0101";break;
				case '6':b+="0110";break;
				case '7':b+="0111";break;
				case '8':b+="1000";break;
				case '9':b+="1001";break;
				case 'A':b+="1010";break;
				case 'B':b+="1011";break;
				case 'C':b+="1100";break;
				case 'D':b+="1101";break;
				case 'E':b+="1110";break;
				case 'F':b+="1111";break;
				default:break;
			}
		}
		if(b.length()%3==1) b="00"+b; //��λ���� 
		else if(b.length()%3==2) b='0'+b;
		for(int k=0; k<b.length(); k+=3){ //����һ�飬ת���ɰ˽��� 
			m=4*(b[k]-48)+2*(b[k+1]-48)+(b[k+2]-48); //���ַ�ת�������֣�0��ASCII��Ϊ 48 
			if(m==0 && k==0)continue; //ȥ����λ���� 
			cout<<m;
		}
		cout<<endl;
	}
	return 0 
} //�Ƚ�ʮ������ÿһλת������λ�����ƣ��ٽ���λ������ת����һλ�˽��� 
