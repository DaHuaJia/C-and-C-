#include <iostream>
using namespace std;

class X;
class Y{
	public:
	void g(X *); 
};

class X{
	public:
		X(){i=0;}
		friend void Y::g(X *x);
		friend void h(X *x){x->i+=10;}
		friend class Z;
		int fun(){ cout<<"类x 的值为："<<i;}
	private:
		int i;
};
void Y::g(X *x){x->i++;}

class Z{
	public:
		void f(X *x){x->i+=5;}
};

int main(){
	X x;
	Z z;
	z.f(&x);
	x.fun();
	return 0;
}
