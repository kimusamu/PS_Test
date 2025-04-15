// BOJ 10773

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	int N;
	cin >> N;

	while (N--)
	{
		int i;
		cin >> i;

		if (0 == i)
		{
			s.pop();
		}

		else
		{
			s.push(i);
		}
	}
	
	int size = s.size();
	int money = 0;

	for (int i = 0; i < size; ++i)
	{
		money += s.top();
		s.pop();
	}

	cout << money << endl;
}