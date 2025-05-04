// BOJ 11559

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string board[12];
bool visit[12][6];
bool is_puyo;
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };
int ans;

// visit 초기화
void reset_visit()
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			visit[i][j] = false;
		}
	}
}

// bfs 기반 같은 색 뿌요 지우기
void puyo(int x, int y)
{
	bool erase = false; // 뿌요 지워야하는지?

	visit[x][y] = true;

	char color = board[x][y];
	queue<pair<int, int>> q;
	vector<pair<int, int>> tmp; // tmp : 4개 이상일시 뿌요 삭제 위치 공유

	q.push({ x, y });
	tmp.push_back({ x, y });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
			{
				continue;
			}

			// 방문했는데, 빈칸이거나, 색이 다르면 컷
			if (visit[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color)
			{
				continue;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
			tmp.push_back({ nx, ny });
		}
	}

	// 4개 이상이면 삭제
	if (tmp.size() >= 4)
	{
		is_puyo = true;

		for (auto cur : tmp)
		{
			board[cur.first][cur.second] = '.';
		}
	}
}

int main()
{
	for (int i = 0; i < 12; ++i)
	{
		cin >> board[i];
	}

	do
	{
		is_puyo = false; // 뿌요 터짐?

		for (int i = 0; i < 6; ++i) // 필드 빈칸 모두 뿌요 위로
		{
			for (int j = 10; j >= 0; --j)
			{
				int tmp = j;

				while (tmp < 11 && board[tmp + 1][i] == '.') // 빈칸이면 위치 바꿔
				{
					swap(board[tmp][i], board[tmp + 1][i]);
					++tmp;
				}
			}
		}

		// 보드 위 터져야하는 뿌요들 싹다 터트림
		for (int i = 0; i < 12; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (!visit[i][j] && board[i][j] != '.')
				{
					puyo(i, j);
				}
			}
		}

		if (is_puyo)
		{
			++ans; // true면 수 올리기
		}

		reset_visit();

	} while (is_puyo); // 뿌요 다 터질때까지 무한반복

	cout << ans;
}