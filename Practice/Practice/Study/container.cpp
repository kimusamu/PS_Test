#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 상수 레퍼런스
/*
void modify(int& value)
{
	value = 10;

	cout << "주소 : " << &value << endl;
	cout << "값 : " << value << endl;
}

int main()
{
	int value = 5;

	cout << "주소 : " << &value << endl;
	cout << "값 : " << value << endl;

	modify(value);

	cout << "값 : " << value << endl;
}
*/

// auto문
/*
int main()
{
	auto num = 42;
	cout << num << endl;

	auto pi = 3.141592;
	cout << pi << endl;

	auto greeting = string("Hello, World!");
	cout << greeting << endl;
}
*/

// 범위 기반 반복문
/*
int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5 };

	for (int num : vec) {
		cout << num << ' ';
	}

	cout << endl;

	map<string, int> fruitMap = { {"apple", 1}, {"banana", 2}, { "cherry", 3 } };

	for (const auto& pair : fruitMap) {
		cout << pair.first << "=" << pair.second << ' ';
	}

	cout << endl;

	set<string> fruitSet = { "apple", "banana", "cherry" };
	
	cout << "Set : ";

	for (const auto& pair : fruitSet) {
		cout << pair << " ";
	}

	cout << endl;
}
*/

// 순방향 반복자
/*
int main()
{

	vector<int> vec = { 10, 20, 30, 40, 50 };

	for (auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;

	auto result = find(vec.begin(), vec.end(), 30);

	if (result != vec.end()) {
		cout << "Found : " << *result << endl;
	}

	else {
		cout << "Not Found" << endl;
	}
	
	return 0;

	/////////////////////////////////////////////////////////////////////////////////

	map<string, int> myMap = { {"apple", 1}, {"banana", 2}, {"cherry", 3} };

	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		cout << it->first << ": " << it->second << " ";
	}

	cout << endl;

	auto result = myMap.find("banana");

	if (result != myMap.end()) {
		cout << "Found : " << result->first << " -> " << result->second << endl;
	}

	else {
		cout << "Not Found" << endl;
	}

	return 0;
}
*/

// 역방향 반복자
/*
int main()
{
	vector<int> vec = { 10, 20, 30, 40, 50 };

	for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
		cout << *it << " ";
	}

	cout << endl;

	auto result = find(vec.rbegin(), vec.rend(), 30);

	if (result != vec.rend()) {
		cout << "Found : " << *result << endl;
	}

	else {
		cout << "Not Found" << endl;
	}

	return 0;
}
*/

// vector O(1)
/*
int main()
{
	// vector<int> v;
	// vector<int> v2 = { 1, 2, 3, 4, 5 };
	// vector<int> v3(4, 3);
	// vector<int> v4(v3);

	//vector<vector<int>> v1;

	//int rows = 3;
	//int cols = 4;

	//vector<vector<int>> v2(rows, vector<int>(cols));

	//int val = 9;
	
	//vector<vector<int>> v3(rows, vector<int>(cols, val));

	//vector<vector<int>> v4 = {
	//	{1,2,3},
	//	{4,5,6},
	//	{7,8,9}
	//};

	//vector<int> vec = { 1,2,3,4,5 };

	//vec[2] = 10;

	//vector<int> v = { 2,3,4,5 };
	//v.push_back(6);
	//v.pop_back();

	//vector<int> v = { 2,3,4,5 };
	//v.insert(v.begin(), 1);
	//v.erase(v.begin());

	return 0;
}
*/

// set O(logN)
/*
int main()
{
	//set<int> s1;
	//set<int> s2 = { 3,1,3,4,5 };
	//set<int> s3(s2);

	//set<int> numbers = { 1,2,3,4,5 };
	//int targets[] = { 3, 7 };

	//for (int target : targets) {
	//	auto it = numbers.find(target);
	//
	//	if (it != numbers.end()) {
	//		cout << "원소 " << target << "를 찾았습니다. 값 : " << *it << endl;
	//	}

	//	else {
	//		cout << "원소 " << target << "를 찾지 못했습니다." << endl;
	//	}
	//}

	//set<int> s = { 1,3,2,1,5 };

	//s.insert(4);
	//s.erase(2);

	//auto it = s.find(4);

	//if (it != s.end()) {
	//	s.erase(it);
	//}

	return 0;
}
*/

// map O(logN), O(1)
/*
int main()
{
	//map<string, double> employeeSalaries;

	//map<string, double> studentGrades = {
	//	{"John", 3.7},
	//	{"Emma", 3.9},
	//	{"Sophia", 4.0}
	//};

	//map<string, int> studentScores;

	//studentScores["Alice"] = 95;
	//studentScores["Bob"] = 88;
	//studentScores["Charlie"] = 92;

	//int score1 = studentScores["Alice"];
	//cout << score1 << endl;

	//int score2 = studentScores["Bob"];
	//cout << score2 << endl;

	//auto it = studentScores.find("Charlie");

	//if (it != studentScores.end()) {
	//	int score3 = it->second;
	//	cout << score3 << endl;
	//}

	//map<string, int>myMap = { {"Apple", 1}, {"Banana", 2}, {"Cherry", 3} };
	//myMap["Banana"] = 10;

	//map<int, string> myMap;

	//myMap.insert(make_pair(1, "Apple"));
	//myMap.insert({ 2, "Banana" });
	//myMap[3] = "Cherry";

	//for (const auto& pair : myMap) {
	//	cout << pair.first << " : " << pair.second << " ";
	//}

	//cout << endl;

	//myMap.erase(2);

	//for (const auto& pair : myMap) {
	//	cout << pair.first << " : " << pair.second << " ";
	//}

	//cout << endl;

	//auto it = myMap.find(3);

	//if (it != myMap.end()) {
	//	myMap.erase(it);
	//}

	//for (const auto& pair : myMap) {
	//	cout << pair.first << " : " << pair.second << " ";
	//}
}
*/

// unordered_map, unordered_set O(1)
int main()
{
	//unordered_set<int> myUnorderedSet;
	//myUnorderedSet.insert(3);
	//myUnorderedSet.insert(1);
	//myUnorderedSet.insert(4);
	//myUnorderedSet.insert(2);

	//for (int num : myUnorderedSet) {
	//	cout << num << endl;
	//}

	unordered_map<string, int> myUnorderedMap;
	myUnorderedMap["apple"] = 3;
	myUnorderedMap["banana"] = 1;
	myUnorderedMap["cherry"] = 4;
	myUnorderedMap["date"] = 2;

	for (const auto& pair : myUnorderedMap) {
		cout << pair.first << " " << pair.second << endl;
	}
}