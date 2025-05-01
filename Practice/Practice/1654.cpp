// BOJ 1654

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int K, N;
	cin >> K >> N;

	vector<long long> v(K + 1);
	long long max_line = 0;

	for (int i = 0; i < K; ++i)
	{
		cin >> v[i];
		max_line = max(max_line, v[i]);
	}

	long long left = 1, right = max_line, mid = 0;
	long long answer = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		long long now = 0;

		for (int i = 0; i < K; ++i)
		{
			now += v[i] / mid;
		}

		if (now >= N)
		{
			left = mid + 1;
			answer = max(answer, mid);
		}

		else
		{
			right = mid - 1;
		}
	}

	cout << answer << '\n';
}