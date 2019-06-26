#include<iostream>
using namespace std;

int i=5;
int main(){
	int fun1(int x);
	void fun2(int &a);
	inline void fun3(int *p);       //使用内联函数，提高程序的运行效率 
	int j=5,k=5;
	i=fun1(i); fun2(j); fun3(&k);
	cout<<i<<ends<<j<<ends<<k;
	return 0;
} 

void fun1(int x){      //通过全局变量使调用子函数所改变的值保留下来 
	i++;
}

void fun2(int &a){         //通过引用使调用子函数所改变的值保留下来 
	a++;    /*int &a 这是引用，这个子函数的参数是引用传递*/ 
}

void fun3(int *p){      //通过指针调用子函数所改变的值保留下来 
	(*p)++;
}
