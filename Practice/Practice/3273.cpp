// BOJ 3273

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
	}

	int x;
	cin >> x;

	int cnt = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] >= x)
		{
			continue;
		}

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[i] + v[j] == x)
			{
				++cnt;
			}
		}
	}

	cout << cnt;
} // �ð��ʰ� ���� �־��� ��� O(n^2) ���
*/

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
	}

	int x;
	cin >> x;

	sort(v.begin(), v.end());

	int left = 0;
	int right = n - 1;
	int cnt = 0;

	while (left < right)
	{
		int sum = v[left] + v[right];

		if (sum == x)
		{
			cnt++;
			left++;
			right--;
		}

		else if (sum < x)
		{
			left++;
		}

		else
		{
			right--;
		}
	}
	
	cout << cnt;
} // �� ������ ����� ���� O(nlogn) �ذ�