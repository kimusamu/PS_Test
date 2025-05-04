#include <iostream>

using namespace std;

int n = 10;
int arr[1000001]{ 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };

void quick_sort(int st, int ed) // arr[st to en-1]�� ������ ����
{
	if (ed <= st + 1) // ������ ���̰� 1 �����̸� �Լ� ����.(base condition)
	{
		return;
	}

	int pivot = arr[st]; // ���� ���� ���� pivot���� ��´�. ������ ���� ��� arr[st]�� swap�ص� �������.
	int l = st + 1; // ������ l
	int r = ed - 1; // ������ r

	while (1)
	{
		while (l <= r && arr[l] <= pivot)
		{
			l++;
		}

		while (l <= r && arr[r] >= pivot)
		{
			r--;
		}

		if (l > r) // l�� r�� �����Ǵ� �� ��� Ż��
		{
			break;
		}

		swap(arr[l], arr[r]);
	}

	swap(arr[st], arr[r]);
	quick_sort(st, r);
	quick_sort(r + 1, ed);
}

int main()
{
	quick_sort(0, n);
	
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
}