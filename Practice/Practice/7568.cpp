#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	vector<int> rank(N, 1);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			if ((v[i].first < v[j].first) && (v[i].second < v[j].second))
			{
				rank[i] += 1;
			}
		}
	}

	for (int i = 0; i < rank.size(); ++i)
	{
		cout << rank[i] << ' ';
	}
}