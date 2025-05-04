// BOJ 11931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmd(int& a, int& b)
{
	return b < a;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmd);

	for (auto a : v)
	{
		cout << a << '\n';
	}
}