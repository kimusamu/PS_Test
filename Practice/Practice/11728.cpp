// BOJ 11728

#include <iostream>

using namespace std;

int A[1000001]{};
int B[1000001]{};

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}

	int a = 0, b = 0;

	while (a < N && b < M)
	{
		if (A[a] > B[b])
		{
			cout << B[b++] << ' ';
		}

		else
		{
			cout << A[a++] << ' ';
		}
	}

	while (a < N)
	{
		cout << A[a++] << ' ';
	}

	while (b < M)
	{
		cout << B[b++] << ' ';
	}
}