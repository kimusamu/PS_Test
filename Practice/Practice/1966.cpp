// BOJ 1966

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int L;
	cin >> L;

	while (L--)
	{
		int N, M;
		cin >> N >> M;

		int cnt = 0;
		int imp = 0;

		priority_queue<int> pq;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; ++i)
		{
			cin >> imp;
			q.push({ i, imp });
			pq.push(imp);
		}

		while (!q.empty())
		{
			int loc = q.front().first;
			int val = q.front().second;
			q.pop();

			if (pq.top() == val)
			{
				pq.pop();
				cnt++;

				if (loc == M)
				{
					cout << cnt << '\n';
					break;
				}
			}

			else
			{
				q.push({ loc, val });
			}
		}
	}
}