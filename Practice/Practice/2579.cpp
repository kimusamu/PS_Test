// BOJ 2579

#include <iostream>

using namespace std;

int n;
int s[305];
int d[305];

int main()
{
	cin >> n;
	int a = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		a += s[i];
	}

	if (n <= 2)
	{
		cout << a;

		return 0;
	}

	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];

	for (int i = 4; i <= n - 1; ++i)
	{
		d[i] = min(d[i - 2], d[i - 3]) + s[i];
	}

	cout << a - min(d[n - 1], d[n - 2]);
}