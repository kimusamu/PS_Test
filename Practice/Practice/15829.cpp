// BOJ 15829

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int L;
	cin >> L;

	string str;
	cin >> str;

	const long long MOD = 1234567891;
	long long hash = 0;
	long long r = 1;

	for (int i = 0; i < L; ++i)
	{
		long long x = int(str[i]) - 96;
		hash = (hash + x * r) % MOD;
		r = (r * 31) % MOD;
	}

	cout << hash;
}