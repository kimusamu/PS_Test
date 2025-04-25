// BOJ 1074

#include <iostream>

using namespace std;

int v(int n, int r, int c)
{
	if (n == 0)
	{
		return 0;
	}

	int half = 1 << (n - 1);

	if (r < half && c < half)
	{
		return v(n - 1, r, c);
	}

	if (r < half && c >= half)
	{
		return half * half + v(n - 1, r, c - half);
	}

	if (r >= half && c < half)
	{
		return 2 * half * half + v(n - 1, r - half, c);
	}

	return 3 * half * half + v(n - 1, r - half, c - half);
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;

	cout << v(n, r, c);
}