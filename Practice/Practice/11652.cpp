// BOJ 11652

#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long arr[100005];

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int cnt = 0;
	long long max_val = -(1ll << 62) - 1;
	int max_cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		if (i == 0 || arr[i - 1] == arr[i])
		{
			cnt++;
		}

		else
		{
			if (cnt > max_cnt)
			{
				max_cnt = cnt;
				max_val = arr[i - 1];
			}

			cnt = 1;
		}
	}

	if (cnt > max_cnt)
	{
		max_val = arr[N - 1];
	}

	cout << max_val;
}