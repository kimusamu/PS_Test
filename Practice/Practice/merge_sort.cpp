#include <iostream>

using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001]; // merge �Լ����� ����Ʈ 2���� ��ģ ����� �ӽ÷� �����ϰ� ���� ����

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.
void merge(int st, int ed)
{
	int mid = (st + ed) / 2;
	int lidx = st; // arr[st:mid]���� ���� ���� ���� ����ϴ� index
	int ridx = mid; // arr[mid:en]���� ���� ���� ���� ����ϴ� index

	for (int i = st; i < ed; ++i)
	{
		if (ridx == ed)
		{
			tmp[i] = arr[lidx++];
		}

		else if (lidx == mid)
		{
			tmp[i] = arr[ridx++];
		}

		else if (arr[lidx] <= arr[ridx])
		{
			tmp[i] = arr[lidx++];
		}

		else
		{
			tmp[i] = arr[ridx++];
		}
	}

	for (int i = st; i < ed; ++i)
	{
		arr[i] = tmp[i]; // tmp�� �ӽ������ص� ���� a�� �ٽ� �ű�
	}
}

// a[st:en]�� �����ϰ� �ʹ�.
void merge_sort(int st, int ed)
{
	if (ed == st + 1) // ����Ʈ�� ���̰� 1�� ���
	{
		return;
	}

	int mid = (st + ed) / 2;

	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�.
	merge_sort(mid, ed); // arr[mid:en]�� �����Ѵ�.
	merge(st, ed); // arr[st:mid]�� arr[mid:en]�� ��ģ��.
}

int main()
{
	merge_sort(0, n);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
}