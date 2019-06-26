#include<iostream>
using namespace std;

void fun(long long int &m,long long int &n){
	long long int a=m,b=n,c;
	do{
		c=a%b;a=b;b=c;
	}while(b!=0);
	m/=a;n/=a;
}

int main(){
	long long int a,b,c,d;
	int i=0,j=0;
	cin>>a>>b>>c>>d;
	fun(a,b);
	fun(c,d);
	if(a/b==c/d) i=1;
	if(a/b < c/d) j=1;
	cout<<"zrf is:"<<a<<"/"<<b<<"; ssh is:"<<c<<"/"<<d<<endl;
	cout<<"(zrf==ssh) is:"<<i<<"; (zrf<ssh) is:"<<j;
	return 0;
}


/* //这是标准答案，题目只需要我们补全代码，考察我们的对运算符重载的熟练程度。 
ostream& operator <<(ostream &os, const zrf_Ratio &a){
	os<<a.num<<"/"<<a.den;
	return os;
}

istream& operator >>(istream &in, zrf_Ratio &a){
	in>>a.num>>a.den;
	return in;
}

bool operator == (const zrf_Ratio &a, const zrf_Ratio &b){
	if(a.num==b.num && a.den==b.den) return 1;
	return 0;
}

bool operator < (const zrf_Ratio &a, const zrf_Ratio &b){
	if(b.num*1.0/b.den > a.num*1.0/b.den) return 1;
	return 0;
}
*/
