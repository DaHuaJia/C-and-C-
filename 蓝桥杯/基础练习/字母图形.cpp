#include<iostream>
using namespace std;

int main(){
	int n,m,a,b,j;
	cin>>n;cin>>m;
	char arr[n][m];
	for(int i=0; i<n; i++){ //i �������� 
		for(j=0,b=0,a=i; j<m; j++){ //j ����ÿ���������  a �����������ĸ���ͣ�ͨ�� 65+aʵ��  
			if(b==0 && a<=i){ 
				cout<<char(65+a);  //A��ascii����65 
				if(a==0){b=1;a+=2;} //a+2 ��Ϊ�˺������a--����һ������ͬʱ�����ظ���� A 
				a--;
			}else if(b==1){ cout<<char(65+a);a++; }
		}
		cout<<endl;
	} 
	return 0;
}//��ĸͼ�Σ��� i �ĵ�һ����ĸ���� ��ĸ���еĵ� i ����ĸ���Ƚ���������һ����� m �� �� 
//����ͽ����ת�۵������� A �� 65+a =65 ,a=0,һ���ж�a==0,�Ͳ���������һֱ��������� 

/*
	for(i=0;i<n;i++){  
        for(j=0;j<m;j++){  
            k=abs(i-j);    //abs�������ֵ   
            printf("%c",a[k]);  
        }  
        printf("\n");  
    }  
*/ 
