// BOJ 1929

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	vector<int> v(1000000);

	for (int i = 2; i <= N; ++i)
	{
		v[i] = i;
	}

	for (int i = 2; i * i <= N; ++i)
	{
		if (v[i] == 0)
		{
			continue;
		}

		for (int j = i * i; j <= N; j += i)
		{
			v[j] = 0;
		}
	}

	for (int i = M; i <= N; ++i)
	{
		if (v[i] != 0)
		{
			cout << v[i] << '\n';
		}
	}
}