// BOJ 2206

#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int board[1001][1001]{};
bool visit[1001][1001][2]{}; // [x][y][broken]
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int cnt = 0;

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; ++j)
		{
			board[i][j] = str[j] - '0';
		}
	}

	// queue�� x, y, broken, dist
	queue<tuple<int, int, int, int>> q;
	q.emplace(0, 0, 0, 1);
	visit[0][0][0] = true;

	while (!q.empty())
	{
		auto[x, y, broken, dist] = q.front();
		q.pop();

		// ����üũ
		if (x == N - 1 && y == M - 1)
		{
			cout << dist << '\n';
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			// �̵��Ϸ��� ĭ�� 0�̸�
			if (board[nx][ny] == 0 && !visit[nx][ny][broken])
			{
				visit[nx][ny][broken] = true;
				q.emplace(nx, ny, broken, dist + 1);
			}

			// �̵��Ϸ��� ĭ�� 1�ε�, ���� ���� �μ� ���� ������
			else if (board[nx][ny] == 1 && broken == 0 && !visit[nx][ny][1])
			{
				visit[nx][ny][1] = true;
				q.emplace(nx, ny, 1, dist + 1);
			}
		}
	}

	cout << -1 << '\n';
}