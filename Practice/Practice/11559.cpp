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

// visit �ʱ�ȭ
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

// bfs ��� ���� �� �ѿ� �����
void puyo(int x, int y)
{
	bool erase = false; // �ѿ� �������ϴ���?

	visit[x][y] = true;

	char color = board[x][y];
	queue<pair<int, int>> q;
	vector<pair<int, int>> tmp; // tmp : 4�� �̻��Ͻ� �ѿ� ���� ��ġ ����

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

			// �湮�ߴµ�, ��ĭ�̰ų�, ���� �ٸ��� ��
			if (visit[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color)
			{
				continue;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
			tmp.push_back({ nx, ny });
		}
	}

	// 4�� �̻��̸� ����
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
		is_puyo = false; // �ѿ� ����?

		for (int i = 0; i < 6; ++i) // �ʵ� ��ĭ ��� �ѿ� ����
		{
			for (int j = 10; j >= 0; --j)
			{
				int tmp = j;

				while (tmp < 11 && board[tmp + 1][i] == '.') // ��ĭ�̸� ��ġ �ٲ�
				{
					swap(board[tmp][i], board[tmp + 1][i]);
					++tmp;
				}
			}
		}

		// ���� �� �������ϴ� �ѿ�� �ϴ� ��Ʈ��
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
			++ans; // true�� �� �ø���
		}

		reset_visit();

	} while (is_puyo); // �ѿ� �� ���������� ���ѹݺ�

	cout << ans;
}