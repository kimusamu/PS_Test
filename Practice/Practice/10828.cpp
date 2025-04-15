// BOJ 10828

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<int> s;
	int N;
	cin >> N;

	while (N--)
	{
		string cmd;
		cin >> cmd;

		if ("push" == cmd)
		{
			int i;
			cin >> i;

			s.push(i);
		}

		else if ("pop" == cmd)
		{
			if (s.empty())
			{
				cout << -1 << endl;
			}

			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}

		else if ("size" == cmd)
		{
			cout << s.size() << endl;
		}

		else if ("empty" == cmd)
		{
			if (s.empty())
			{
				cout << 1 << endl;
			}

			else
			{
				cout << 0 << endl;
			}
		}

		else if ("top" == cmd)
		{
			if (s.empty())
			{
				cout << -1 << endl;
			}

			else
			{
				cout << s.top() << endl;
			}
		}
	}
}