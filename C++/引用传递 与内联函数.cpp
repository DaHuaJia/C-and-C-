#include<iostream>
using namespace std;

int i=5;
int main(){
	int fun1(int x);
	void fun2(int &a);
	inline void fun3(int *p);       //ʹ��������������߳��������Ч�� 
	int j=5,k=5;
	i=fun1(i); fun2(j); fun3(&k);
	cout<<i<<ends<<j<<ends<<k;
	return 0;
} 

void fun1(int x){      //ͨ��ȫ�ֱ���ʹ�����Ӻ������ı��ֵ�������� 
	i++;
}

void fun2(int &a){         //ͨ������ʹ�����Ӻ������ı��ֵ�������� 
	a++;    /*int &a �������ã�����Ӻ����Ĳ��������ô���*/ 
}

void fun3(int *p){      //ͨ��ָ������Ӻ������ı��ֵ�������� 
	(*p)++;
}
