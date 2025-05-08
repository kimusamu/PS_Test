// BOJ 9095

#include <iostream>

using namespace std;

int T;
int n;
int D[100000];

int main()
{
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	for (int i = 4; i < 11; ++i)
	{
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}

	cin >> T;

	while (T--)
	{
		cin >> n;
		cout << D[n] << '\n';
	}
}