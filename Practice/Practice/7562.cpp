// BOJ 7562

#include <iostream>
#include <queue>

using namespace std;

int visit[301][301];
int dx[8]{ 1,2,2,1,-1,-2,-2,-1 };
int dy[8]{ -2,-1,1,2,2,1,-1,-2 };

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		int l;
		cin >> l;

		int x1, y1;
		cin >> x1 >> y1;

		int x2, y2;
		cin >> x2 >> y2;

		for (int i = 0; i < l; ++i)
		{
			fill(visit[i], visit[i] + l, -1);
		}

		queue<pair<int, int>> q;

		visit[x1][y1] = 0;
		q.push({ x1, y1 });

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int i = 0; i < 8; ++i)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= l || ny < 0 || ny >= l)
				{
					continue;
				}

				if (visit[nx][ny] >= 0)
				{
					continue;
				}

				visit[nx][ny] = visit[cur.first][cur.second] + 1;
				q.push({ nx, ny });
			}
		}

		cout << visit[x2][y2] << '\n';
	}
}