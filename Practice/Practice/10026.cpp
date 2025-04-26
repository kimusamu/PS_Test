// BOJ 10026

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;

char board[101][101];
bool visit[101][101];
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0, 1, 0, -1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x , y });
	visit[x][y] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			if (visit[nx][ny] || board[x][y] != board[nx][ny])
			{
				continue;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int area()
{
	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visit[i][j])
			{
				cnt++;
				bfs(i, j);
			}
		}
	}

	return cnt;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	int not_green = area();

	for (int i = 0; i < N; ++i)
	{
		fill(visit[i], visit[i] + N, false);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 'G')
			{
				board[i][j] = 'R';
			}
		}
	}

	int green = area();

	cout << not_green << ' ' << green;
}