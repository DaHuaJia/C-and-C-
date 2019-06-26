#include<iostream>
using namespace std;

int main(){
	enum Weekday {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday}Day=Friday;   //定义枚举变量Day,该变量只能取7个值 
	const char *WeekdayName[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};//定义一个常量逻辑映射数组 
	//string WeekdayName[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	cout<<Day<<endl;
	cout<<WeekdayName[Day]<<endl;
	switch(Day){      //对于枚举型变量的输出，可以使用switch和 逻辑映射数组
		case Sunday: cout<<"Today is Sunday!"<<endl; break;
		case Monday: cout<<"Today is Monday!"<<endl; break;
		case Tuesday: cout<<"Today is Tuesday!"<<endl; break;	
		case Wednesday: cout<<"Today is Wednesday!"<<endl; break;
		case Thursday: cout<<"Today is Thursday!"<<endl; break;
		case Friday: cout<<"Today is Friday!"<<endl; break;
		case Saturday: cout<<"Today is Saturday!"<<endl; break;
		default :cout<<"一个星期没有这天！"<<endl; 
	}
	return 0;
}  

//enum class Weeka{guo,ming,de}name=guo; 
//C++11 提供了强制枚举类型。 
