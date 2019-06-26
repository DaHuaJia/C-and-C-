#include <iostream>
using namespace std; 
int main()
{
	
	cout << " Enter numbers:";

	int sum = 0;
	int input;
	while ( cin >> input )     //如果输入流与存储类型不匹配，则返回false(0)，使循环终止 
	{
		sum += input;
	}

	cout << "Last value entered  = " << input << endl;
	cout << "sum = " << sum << endl;
	return 0;
}
