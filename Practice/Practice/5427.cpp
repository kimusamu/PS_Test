// BOJ 5427

#include <iostream>
#include <queue>

using namespace std;

int board[1001][1001];

int fire_visit[1001][1001];
int person_visit[1001][1001];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		queue<pair<int, int>>fire_q{};
		queue<pair<int, int>>person_q{};
		int w, h;
		cin >> w >> h;

		for (int i = 0; i < h; ++i)
		{
			fill(fire_visit[i], fire_visit[i] + w, 0);
			fill(person_visit[i], person_visit[i] + w, 0);
		}

		bool escape = false;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				char c;
				cin >> c;

				if (c == '#')
				{
					board[i][j] = -1;
				}

				else
				{
					if (c == '*')
					{
						fire_q.push({ i, j });
						fire_visit[i][j] = 1;
					}

					else if (c == '@')
					{
						person_q.push({ i, j });
						person_visit[i][j] = 1;
					}

					board[i][j] = 0;
				}
			}
		}

		while (!fire_q.empty())
		{
			auto cur = fire_q.front();
			fire_q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					continue;
				}

				if (board[nx][ny] == -1 || fire_visit[nx][ny] != 0)
				{
					continue;
				}

				fire_visit[nx][ny] = fire_visit[cur.first][cur.second] + 1;
				fire_q.push({ nx, ny });
			}
		}

		while (!person_q.empty() && !escape)
		{
			auto cur = person_q.front();
			person_q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << person_visit[cur.first][cur.second] << '\n';
					escape = true;
					break;
				}

				if (board[nx][ny] == -1 || person_visit[nx][ny] != 0)
				{
					continue;
				}

				if (fire_visit[nx][ny] != 0 && fire_visit[nx][ny] <= person_visit[cur.first][cur.second] + 1)
				{
					continue;
				}

				person_visit[nx][ny] = person_visit[cur.first][cur.second] + 1;
				person_q.push({ nx, ny });
			}
		}

		if (!escape)
		{
			cout << "IMPOSSIBLE" << '\n';
		}
	}
}