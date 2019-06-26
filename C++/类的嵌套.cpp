#include<iostream>
#include<cmath>
using namespace std;

class point{  //point�� 
	public:
		point(int a=0,int b=0){    //���캯�� 
			x=a;y=b;
		}
		point(point &p);   //���ƹ��캯�� 
		int getx(){
			return x;
		}
		int gety(){
			return y;
		}
		void pointSet();   //���õ������ 
	private:
		int x,y;
}; 
point::point(point &p){  //���ƹ��캯����ʵ�� 
	x=p.x;
	y=p.y;
}  
void point::pointSet(){
	cout<<"�õ�ĺ�����Ϊ��";
	cin>>x;
	cout<<"�õ��������Ϊ��";
	cin>>y; 
} 


class line{   //line�� (�����) 
	public:
		line(point M,point N);   //���캯��
		line(line &l1);     //���ƹ��캯�� 
		float getLen(){ return lenght; } 
	private:
		point a,b;
		float lenght;
}; 
//�����Ĺ��캯��
line::line(point M,point N):a(M),b(N){
	float x=static_cast<float>(a.getx()-b.getx());
	float y=static_cast<float>(a.gety()-b.gety());
	lenght=sqrt(x*x + y*y);
} 
//�����ĸ��ƹ��캯��
line::line(line &l1):a(l1.a),b(l1.b){
	lenght=l1.lenght;
} 


int main(){
	point myp1,myp2;
	myp1.pointSet();
	myp2.pointSet();
	line myline1(myp1,myp2);
	line myline2(myline1);
	cout<<"������֮���ֱ�߾���Ϊ��"<<myline1.getLen()<<endl;
	cout<<"���ƺ�������֮���ֱ�߾���Ϊ��"<<myline2.getLen()<<endl;
	return 0; 
}
