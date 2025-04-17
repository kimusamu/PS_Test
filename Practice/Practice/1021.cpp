// BOJ 1021

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> d;
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		d.push_back(i);
	}

	int M;
	cin >> M;

	int cnt = 0;

	while (M--)
	{
		int target;
		cin >> target;

		int idx = 0;

		for (auto i = d.begin(); i != d.end(); ++i, ++idx)
		{
			if (*i == target)
			{
				break;
			}
		}

		int left_moves = idx;
		int right_moves = d.size() - idx;

		if (left_moves <= right_moves)
		{
			cnt += left_moves;

			for (int i = 0; i < left_moves; ++i)
			{
				d.push_back(d.front());
				d.pop_front();
			}
		}

		else
		{
			cnt += right_moves;

			for (int i = 0; i < right_moves; ++i)
			{
				d.push_front(d.back());
				d.pop_back();
			}
		}

		d.pop_front();
	}

	cout << cnt;
}