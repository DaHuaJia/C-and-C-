#include <iostream>
using namespace std; 
int main()
{
	
	cout << " Enter numbers:";

	int sum = 0;
	int input;
	while ( cin >> input )     //�����������洢���Ͳ�ƥ�䣬�򷵻�false(0)��ʹѭ����ֹ 
	{
		sum += input;
	}

	cout << "Last value entered  = " << input << endl;
	cout << "sum = " << sum << endl;
	return 0;
}
