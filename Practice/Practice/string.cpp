#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 문자열 선언, 초기화
	/*
	string str1;
	string str2 = "Hello, World!";
	string str3(str2);
	string str4(str2, 0, 5);
	string str5(10, '*');
	*/
	
	// 문자열 찾기
	/*
	string str = "Hello, World!";

	size_t pos1 = str.find("Hello");
	cout << pos1 << endl;

	size_t pos2 = str.find("W");
	cout << pos2 << endl;

	size_t start_index = 2;
	size_t pos3 = str.find("Hello", start_index);
	cout << pos3 << endl;

	size_t pos4 = str.find("Python");
	cout << pos4 << endl;
	*/
	
	// 문자열 추가, 수정
	/*
	string str = "APPLE";
	str += ", World";
	cout << str << endl;

	str[7] = 'P';
	cout << str << endl;

	str.replace(7, 4, "Col");
	cout << str << endl;
	*/

	return 0;
}