// BOJ 2775

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int k, n;
		cin >> k >> n;

		int apart[15][15]{};

		for (int i = 1; i < 15; ++i)
		{
			apart[0][i] = i;
		}

		for (int i = 1; i <= k; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (apart[k][n])
				{
					continue;
				}

				for (int k = 1; k <= j; ++k)
				{
					apart[i][j] += apart[i - 1][k];
				}
			}
		}

		cout << apart[k][n] << '\n';
	}
}