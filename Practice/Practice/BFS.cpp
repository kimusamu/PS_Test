#include <iostream>
#include <queue>

using namespace std;

int board[502][502] = {
	{1,1,1,0,1,0,0,0,0,0},
	{1,0,0,0,1,0,0,0,0,0},
	{1,1,1,0,1,0,0,0,0,0},
	{1,1,0,0,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
}; // 1�� �湮 �� �� �ִ� ĭ, 0�� �ƴ�

bool visit[502][502]; // �ش� ĭ �湮�ߴ��� ���� ����

int n = 7, m = 10; // n : ���� �� / m : ���� ��
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 }; // ��, ��, ��, �� �� ����

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	visit[0][0] = 1; // 0,0 �湮
	q.push({ 0, 0 }); // Queue ������ 0, 0 ����

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); // ���� ��ġ
		q.pop();

		cout << "(" << cur.first << ", " << cur.second << ") -> ";

		for (int dir = 0; dir < 4; ++dir) // �� �� �� �� ĭ�� ���캽
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) // ���� ���� ��� �Ѿ
			{
				continue;
			}

			if (visit[nx][ny] || board[nx][ny] != 1) // �̹� �湮�� ĭ�̰ų�, �湮 �� �� ���� ĭ�̸� �Ѿ
			{
				continue;
			}

			visit[nx][ny] = 1; // nx, ny �湮�ߴٰ� ���

			q.push({ nx, ny });
		}
	}
}