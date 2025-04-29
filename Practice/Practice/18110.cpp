// BOJ 18110

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

float cur = 0;
float cnt = 0;

int main()
{
	int N;
	cin >> N;

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	int a = int(round(N * 0.15));

	sort(arr.begin(), arr.end());

	int start = a;
	int end = N - a;

	if (start >= end)
	{
		cout << 0;
		return 0;
	}

	for (int i = start; i < end; ++i)
	{
		cur += arr[i];
		cnt++;
	}

	int answer = int(round(cur / cnt));

	cout << answer << '\n';
}