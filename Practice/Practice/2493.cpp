// BOJ 2493

/*
스택을 첨부터 쌓지 말고
stack<pait<int, int>> s를 사용해서 {위치, 송신탑 길이}를 받고
첫번째는 비교 물가능 하니 0 출력 후
두번째부터 stack에 쌓인 값들과 비교
만약 수신 안되면 pop, 수신되면 위치 출력 후 다음 값 stack 실시
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