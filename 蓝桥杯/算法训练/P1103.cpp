#include<iostream>
#include<iomanip>
using namespace std;

struct complex{
	double rea;
	double img;
};
complex* fun1(complex a,complex b){
	static complex c;
	c.rea=a.rea+b.rea;
	c.img=a.img+b.img;
	return &c;
}
complex* fun2(complex a,complex b){
	static complex c;
	c.rea=a.rea-b.rea;
	c.img=a.img-b.img;
	return &c;
}
complex* fun3(complex a,complex b){
	static complex c;
	c.rea=a.rea*b.rea;
	c.img=a.img*b.img;
	return &c;
}
complex* fun4(complex a,complex b){
	static complex c;
	c.rea=a.rea/b.rea;
	c.img=a.img/b.img;
	return &c;
}

int main(){
	complex a,b;complex* e=new complex;
	char label; 
	cin>>label>>a.rea>>a.img>>b.rea>>b.img;
	switch(label){
		case '+':e=fun1(a,b);break;
		case '-':e=fun2(a,b);break;
		case '*':e=fun3(a,b);break;
		case '/':e=fun4(a,b);break;
		default:break;
	}
	cout<<fixed<<setprecision(2);
	cout<<e->rea<<'+'<<e->img<<'i';
	return 0;
}
