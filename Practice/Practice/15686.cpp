// BOJ 15686

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int board[55][55];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				house.push_back({ i, j });
			}

			if (board[i][j] == 2)
			{
				chicken.push_back({ i, j });
			}
		}
	}

	vector<int> brute(chicken.size(), 1);

	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);

	int ans = INT_MAX;

	do
	{
		int dist = 0;

		for (auto h : house)
		{
			int tmp = INT_MAX;

			for (int i = 0; i < chicken.size(); ++i)
			{
				if (brute[i] == 0)
				{
					continue;
				}

				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}

			dist += tmp;
		}

		ans = min(ans, dist);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << ans;
}