#include<iostream>
#include<cmath>
using namespace std;

class point{  //point类 
	public:
		point(int a=0,int b=0){    //构造函数 
			x=a;y=b;
		}
		point(point &p);   //复制构造函数 
		int getx(){
			return x;
		}
		int gety(){
			return y;
		}
		void pointSet();   //设置点的坐标 
	private:
		int x,y;
}; 
point::point(point &p){  //复制构造函数的实现 
	x=p.x;
	y=p.y;
}  
void point::pointSet(){
	cout<<"该点的横坐标为：";
	cin>>x;
	cout<<"该点的纵坐标为：";
	cin>>y; 
} 


class line{   //line类 (组合类) 
	public:
		line(point M,point N);   //构造函数
		line(line &l1);     //复制构造函数 
		float getLen(){ return lenght; } 
	private:
		point a,b;
		float lenght;
}; 
//组合类的构造函数
line::line(point M,point N):a(M),b(N){
	float x=static_cast<float>(a.getx()-b.getx());
	float y=static_cast<float>(a.gety()-b.gety());
	lenght=sqrt(x*x + y*y);
} 
//组合类的复制构造函数
line::line(line &l1):a(l1.a),b(l1.b){
	lenght=l1.lenght;
} 


int main(){
	point myp1,myp2;
	myp1.pointSet();
	myp2.pointSet();
	line myline1(myp1,myp2);
	line myline2(myline1);
	cout<<"两个点之间的直线距离为："<<myline1.getLen()<<endl;
	cout<<"复制后两个点之间的直线距离为："<<myline2.getLen()<<endl;
	return 0; 
}
