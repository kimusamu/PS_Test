// BOJ 1012

#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };
int field[51][51];
bool visit[51][51];

queue<pair<int, int>> q;

void bfs(int x, int y)
{
	visit[x][y] = true;
	q.push({ x, y });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx > N || ny < 0 || ny >= M)
			{
				continue;
			}

			if (visit[nx][ny] == true || field[nx][ny] != 1)
			{
				continue;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;

		for (int i = 0; i < N; ++i)
		{
			fill(field[i], field[i] + M, 0);
			fill(visit[i], visit[i] + M, false);
		}

		while (K--)
		{
			int x, y;
			cin >> x >> y;

			field[y][x] = 1;
		}

		int worm = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (field[i][j] == 1 && visit[i][j] == false)
				{
					bfs(i, j);
					worm++;
				}
			}
		}

		cout << worm << '\n';
	}
}