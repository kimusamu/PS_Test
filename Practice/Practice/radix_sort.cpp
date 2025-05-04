#include <iostream>
#include <vector>

using namespace std;

int n = 15;
int arr[1000001] = { 12, 421, 46, 674, 103, 502, 7, 100, 21, 545, 722, 227, 62, 91, 240 };
// 1, 10, 100�� �ڸ��� ���ؼ� ����, ���� �ִ� 3�ڸ����� �ƴ� ��� d�� �����ؾ� ��
int d = 3;
// p10[i] = 10�� i��
int p10[3];

// x�� 10^a �ڸ��� ���� ��ȯ�ϴ� �Լ�
int digit_num(int x, int a)
{
	return (x / p10[a]) % 10;
}

vector<int> l[10];

int main()
{
	p10[0] = 1;

	for (int i = 1; i < d; ++i)
	{
		p10[i] = p10[i - 1] * 10;
	}

	// �� ���� list�� ����
	for (int i = 0; i < d; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			l[j].clear();
		}

		for (int j = 0; j < n; ++j)
		{
			l[digit_num(arr[j], i)].push_back(arr[j]);
		}

		// 0�� ����Ʈ���� ���ʷ� �ٽ� arr�� �־� ��迭
		int aidx = 0;

		for (int j = 0; j < 10; ++j)
		{
			for (auto x : l[j])
			{
				arr[aidx++] = x;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
}