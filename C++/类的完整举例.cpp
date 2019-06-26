#include<iostream>
using namespace std;

class Complex{
	public:
		Complex(double a,double b);
		~Complex();
		void show();
		friend void add(Complex &a,Complex &b);
	private:
		double real;
		double image;
}; 
Complex::Complex(double a=0.0,double b=0.0){
	real=a;image=b;
}
Complex::~Complex(){
	cout<<"This is all."<<endl;
}
void Complex::show(){
	cout<<real<<" + "<<image<<"i"<<endl;
}
void add(Complex &a,Complex &b){
	a.real+=b.real;
	a.image+=b.image;
}

int main(){
	Complex i(3,4);
	Complex j=4.5;
	i.show();j.show();
	add(i,j);
	i.show();
	return 0;
}
