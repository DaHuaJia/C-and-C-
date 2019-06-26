#include<iostream>
using namespace std;

class shape{
	public:
		shape(){}
		~shape(){}
		virtual float getArea(){return -1;}
};

class circle:public shape{
	public:
		circle(float radius):itsradius(radius){}
		~circle(){}
		float getArea(){return 3.14*itsradius*itsradius;}
	private:
		float itsradius;	
};

class rectangle:public shape{
	public:
		rectangle(float len,float width):itslength(len),itswidth(width){}
		~rectangle(){}
		virtual float getArea(){return itslength* itswidth;}
		virtual float getlength(){return itslength;}
		virtual float getwidth(){return itswidth;}
	private:
		float itswidth;
		float itslength;
};

class square:public rectangle{
	public:
		square(float len);
		~square(){}
};
square::square(float len):rectangle(len,len){}


int main(void){
	shape* sp;
	sp=new circle(5);
	cout<<"The area of the ciecle is "<<sp->getArea()<<endl;
	delete sp;
	sp=new rectangle(4,6);
	cout<<"The area of the rectangle is "<<sp->getArea()<<endl;
	delete sp;
	sp=new square(5);
	cout<<"The area of the square is "<<sp->getArea()<<endl;
	delete sp;
	return 0;
}
