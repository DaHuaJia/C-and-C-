#ifndef HEAD_H
#define HEAD_H
/*在这个头文件中，首先判断标识符 HEAD_H 是否被定义过。若未被定义过，说明此头文件尚未参加过编译，于是编译下面的程序段，
并且对标识符 HEAD_H 进行宏定义，标记此文件参加过编译。若标识符 HEAD_H 被定义过，说明头文件参加过编译，于是编译器
忽略下面的程序段。这样便不会造成对类point的重复定义，防止报错*/

class point{
	public:
		point(float x=0,float y=0):x(x),y(y){ };
		float getX() const {return x;}
		float getY() const {return y;}
	private:
		float x,y;
};

#endif     //HEAD_H
