// BOJ 2108

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	
	int all = 0;

	for (int x : v)
	{
		all += x;
	}

	int mean = (int)round(static_cast<double>(all) / N);

	if (mean == -0)
	{
		mean = 0;
	}

	cout << mean << '\n';
	
	//=================//

	sort(v.begin(), v.end());

	int mid = 0;

	if (N == 1)
	{
		mid = v[0];
	}

	else
	{
		mid = v[(N - 1) / 2];
	}

	cout << mid << '\n';

	//=================//

	int cnt[8001]{};

	for (int i = 0; i < N; ++i)
	{
		if (v[i] >= 0)
		{
			cnt[int(v[i])]++;
		}

		else
		{
			cnt[int(fabs(v[i])) + 4000]++;
		}
	}

	int max = cnt[0];
	int idx = 0;

	for (int i = 0; i < 8001; ++i)
	{
		if (max < cnt[i])
		{
			idx = i;
			max = cnt[i];
		}
	}

	vector<double> mv;

	for (int i = 0; i < 8001; ++i)
	{
		if (max == cnt[i])
		{
			if (i <= 4000)
			{
				mv.push_back(i);
			}

			else
			{
				mv.push_back((i - 4000) * (-1));
			}
		}
	}

	sort(mv.begin(), mv.end());

	int mode = 0;

	if (mv.size() == 1)
	{
		mode = mv[0];
	}

	else
	{
		mode = mv[1];
	}

	cout << mode << '\n';

	int range = v[N - 1] - v[0];

	cout << range << '\n';
}