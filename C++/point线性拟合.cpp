#include<iostream>
#include<cmath>
#include "point.h"
using namespace std;

float lineFit(const point points[],int npoint){
	float avgX=0,avgY=0;
	float lxx=0,lyy=0,lxy=0;
	for(int i=0; i<npoint; i++){  //计算x y 的平均值 
		avgX+=points[i].getX()/npoint;
		avgY+=points[i].getY()/npoint;
	}
	for(int i=0; i<npoint; i++){
		lxx+=(points[i].getX()-avgX)*(points[i].getX()-avgX);
		lyy+=(points[i].getY()-avgY)*(points[i].getY()-avgY);
		lxy+=(points[i].getX()-avgX)*(points[i].getY()-avgY);
	} 
	cout<<"回归方程为(Y=aX+b)："<<endl;
	cout<<"Y = "<<lxy/lxx<<" X + "<<avgY-lxy*avgX/lxx<<endl;
	return static_cast<float>(lxy/sqrt(lxx*lyy)); 
} 

int main(){
	point p[10]={point(6,10),point(14,20),point(26,30),point(33,40),point(46,50),
				 point(54,60),point(67,70),point(75,80),point(84,90),point(100,100) };
	float r=lineFit(p,10);
	cout<<"相关系数 r 为："<<r<<endl;
	return 0; 
}
