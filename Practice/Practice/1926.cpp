// BOJ 1926

#include <iostream>
#include <queue>

using namespace std;

int board[502][502];
bool visit[502][502];

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	int mx = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] != 1 || visit[i][j])
			{
				continue;
			}

			cnt++;

			visit[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i, j });

			int area = 0;

			while (!q.empty())
			{
				area++;

				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						continue;
					}

					if (visit[nx][ny] || board[nx][ny] != 1)
					{
						continue;
					}

					visit[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}

			mx = max(mx, area);
		}
	}

	cout << cnt << '\n' << mx;
}