#include<iostream>
using namespace std;

int main(){
	enum Weekday {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday}Day=Friday;   //����ö�ٱ���Day,�ñ���ֻ��ȡ7��ֵ 
	const char *WeekdayName[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};//����һ�������߼�ӳ������ 
	//string WeekdayName[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	cout<<Day<<endl;
	cout<<WeekdayName[Day]<<endl;
	switch(Day){      //����ö���ͱ��������������ʹ��switch�� �߼�ӳ������
		case Sunday: cout<<"Today is Sunday!"<<endl; break;
		case Monday: cout<<"Today is Monday!"<<endl; break;
		case Tuesday: cout<<"Today is Tuesday!"<<endl; break;	
		case Wednesday: cout<<"Today is Wednesday!"<<endl; break;
		case Thursday: cout<<"Today is Thursday!"<<endl; break;
		case Friday: cout<<"Today is Friday!"<<endl; break;
		case Saturday: cout<<"Today is Saturday!"<<endl; break;
		default :cout<<"һ������û�����죡"<<endl; 
	}
	return 0;
}  

//enum class Weeka{guo,ming,de}name=guo; 
//C++11 �ṩ��ǿ��ö�����͡� 
