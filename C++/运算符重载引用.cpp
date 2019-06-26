#include<iostream>
#include<cstring>
using namespace std;

class Mystring{
	public:
		char str[80];
		Mystring(const char *s){strcpy(str,s);}
		Mystring &operator +=(Mystring a){
			strcat(str,a.str);
			return *this;
		}
};

ostream &operator << (ostream & s,const Mystring &z){return s<<z.str;}

int main(){
	Mystring x("abc"),y("cde");
	cout<<(x+=y)<<endl;
	return 0;
}
