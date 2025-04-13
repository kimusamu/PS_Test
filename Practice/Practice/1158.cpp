// BOJ 1158

#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> q;
	list<int> lst;
	int cnt = 1;

	for (int i = 1; i <= N; ++i)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		if (cnt == K)
		{
			lst.emplace_back(q.front());
			q.pop();
			cnt = 1;
		}

		else
		{
			cnt++;
			q.push(q.front());
			q.pop();
		}
	}

	cout << "<";

	int i = 0;

	for (auto a : lst)
	{
		if (i + 1 == lst.size())
		{
			cout << a;
		}

		else 
		{
			i++;
			cout << a << ", ";
		}
	}

	cout << ">";
}