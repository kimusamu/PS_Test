// BOJ 2292

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int max = 1;
	int ret = 0;
	int cnt = 1;

	while (true)
	{
		if (n <= max)
		{
			cout << cnt << '\n';
			return 0;
		}

		ret += 6;
		max += ret;
		cnt++;
	}
}