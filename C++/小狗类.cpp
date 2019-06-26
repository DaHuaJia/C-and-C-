#include<iostream>
#include<cstdio>
using namespace std;

class dog{
	public:
		dog(int a,int b,char c);   //构造函数（具有默认值），初始化数据成员 
		void DogAdd();     //设置小狗信息 
		void DogShow();    //显示小狗信息 
	private:
		float height,weigth;
		char hair_color;
		static int num;   //静态变量，用于统计小狗的个数 
};
	int dog::num=0;   //静态变量的初始化使用类名进行限定 
	
dog::dog(int a,int b,char c){
	height=a;
	weigth=b;
	hair_color=c;
}

void dog::DogAdd(){ 
	cout<<"小狗的身高是：";
	cin>>height;
	cout<<"小狗的体重是：";
	cin>>weigth;
	cout<<"小狗的毛色是：";
	cin>>hair_color; 
}

void dog::DogShow(){
	num++; 
	cout<<"a"<<num<<"这条小狗的身高是："<<height<<" cm"<<endl;
	cout<<"a"<<num<<"这条小狗的体重是："<<weigth<<" kg"<<endl;
	cout<<"a"<<num<<"这条小狗的毛色是："<<hair_color<<endl; 
}

int main(){
	dog a1(0,0,'K'),a2(0,0,'K');
	a1.DogAdd();
	a1.DogShow();
	a2.DogShow();
	
	return 0;
} 

