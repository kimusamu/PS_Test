// BOJ 4179

#include <iostream>
#include <queue>

using namespace std;

string room[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int main()
{
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		cin >> room[i];
	}

	for (int i = 0; i < R; ++i)
	{
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}

	queue<pair<int, int>>q1;
	queue<pair<int, int>>q2;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (room[i][j] == 'F')
			{
				q1.push({ i, j });
				dist1[i][j] = 0;
			}

			else if (room[i][j] == 'J')
			{
				q2.push({ i, j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!q1.empty())
	{
		auto cur = q1.front();
		q1.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				continue;
			}

			if (dist1[nx][ny] >= 0 || room[nx][ny] == '#')
			{
				continue;
			}

			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			q1.push({ nx, ny });
		}
	}

	while (!q2.empty())
	{
		auto cur = q2.front();
		q2.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}

			if (dist2[nx][ny] >= 0 || room[nx][ny] == '#')
			{
				continue;
			}

			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1)
			{
				continue;
			}

			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			q2.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}