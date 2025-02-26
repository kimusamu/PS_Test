#include <iostream>

using namespace std;

/*
int func1(param1, param2, ... , paramN)
{
	// executable code

	return result;
}
*/

int add(int num1, int num2)
{
	return num1 + num2;
}

int main()
{
	int a = 5;
	int b = 10;

	cout << add(a, b) << endl;
	return 0;
}