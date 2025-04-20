// BOJ 3986

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0;

	while (N--)
	{
		string str;
		cin >> str;

		stack<char> s;

		for (auto a : str)
		{
			if (!s.empty() && s.top() == a)
			{
				s.pop();
			}

			else 
			{
				s.push(a);
			}
		}

		if (s.empty())
		{
			cnt++;
		}
	}

	cout << cnt;
}