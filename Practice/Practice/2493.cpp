// BOJ 2493

/*
������ ÷���� ���� ����
stack<pait<int, int>> s�� ����ؼ� {��ġ, �۽�ž ����}�� �ް�
ù��°�� �� ������ �ϴ� 0 ��� ��
�ι�°���� stack�� ���� ����� ��
���� ���� �ȵǸ� pop, ���ŵǸ� ��ġ ��� �� ���� �� stack �ǽ�
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	stack<pair<int, int>> s;

	for (int i = 1; i <= N; ++i)
	{
		int top;
		cin >> top;

		if (s.empty())
		{
			cout << 0 << " ";
			s.push({ i, top });
		}

		else
		{
			while (!s.empty())
			{
				if (s.top().second > top)
				{
					cout << s.top().first << " ";
					break;
				}

				else
				{
					s.pop();
				}
			}

			if (s.empty())
			{
				cout << 0 << " ";
			}

			s.push({ i, top });
		}
	}
}