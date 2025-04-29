// BOJ 1676

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0;

	for (long long i = 5; i <= N; i *= 5)
	{
		cnt += N / i;
	}

	cout << cnt;
}