#include<iostream>
#include<cstdio>
using namespace std;

class dog{
	public:
		dog(int a,int b,char c);   //���캯��������Ĭ��ֵ������ʼ�����ݳ�Ա 
		void DogAdd();     //����С����Ϣ 
		void DogShow();    //��ʾС����Ϣ 
	private:
		float height,weigth;
		char hair_color;
		static int num;   //��̬����������ͳ��С���ĸ��� 
};
	int dog::num=0;   //��̬�����ĳ�ʼ��ʹ�����������޶� 
	
dog::dog(int a,int b,char c){
	height=a;
	weigth=b;
	hair_color=c;
}

void dog::DogAdd(){ 
	cout<<"С��������ǣ�";
	cin>>height;
	cout<<"С���������ǣ�";
	cin>>weigth;
	cout<<"С����ëɫ�ǣ�";
	cin>>hair_color; 
}

void dog::DogShow(){
	num++; 
	cout<<"a"<<num<<"����С��������ǣ�"<<height<<" cm"<<endl;
	cout<<"a"<<num<<"����С���������ǣ�"<<weigth<<" kg"<<endl;
	cout<<"a"<<num<<"����С����ëɫ�ǣ�"<<hair_color<<endl; 
}

int main(){
	dog a1(0,0,'K'),a2(0,0,'K');
	a1.DogAdd();
	a1.DogShow();
	a2.DogShow();
	
	return 0;
} 

