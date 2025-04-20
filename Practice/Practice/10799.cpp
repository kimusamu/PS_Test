// BOJ 10799

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string pipe;
	cin >> pipe;

	int cnt = 0;
	stack<int> s;

	for (int i = 0; i < pipe.size(); ++i)
	{
		if (pipe[i] == '(' && pipe[i + 1] == ')')
		{
			cnt += s.size();
			i++;
		}

		else if (pipe[i] == '(')
		{
			s.push(i);
		}

		else if (pipe[i] == ')')
		{
			cnt++;
			s.pop();
		}
	}

	cout << cnt;
}