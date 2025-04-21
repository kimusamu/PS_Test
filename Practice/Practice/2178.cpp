// BOJ 2178

#include <iostream>
#include <queue>

using namespace std;

string board[101];
int visit[101][101];
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	for (int i = 0; i < N; ++i)
	{
		fill(visit[i], visit[i] + M, -1);
	}

	visit[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			if (visit[nx][ny] >= 0 || board[nx][ny] != '1')
			{
				continue;
			}

			visit[nx][ny] = visit[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}

	cout << visit[N - 1][M - 1] + 1;
}