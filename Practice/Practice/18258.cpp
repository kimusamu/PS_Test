// BOJ 18258

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
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

			q.push(i);
		}

		else if ("pop" == cmd)
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}

			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}

		else if ("size" == cmd)
		{
			cout << q.size() << '\n';
		}

		else if ("empty" == cmd)
		{
			if (q.empty())
			{
				cout << 1 << '\n';
			}

			else
			{
				cout << 0 << '\n';
			}
		}

		else if ("front" == cmd)
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}

			else
			{
				cout << q.front() << '\n';
			}
		}

		else if ("back" == cmd)
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}

			else
			{
				cout << q.back() << '\n';
			}
		}
	}
}