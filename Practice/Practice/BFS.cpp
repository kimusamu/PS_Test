#include <iostream>
#include <queue>

using namespace std;

int board[502][502] = {
	{1,1,1,0,1,0,0,0,0,0},
	{1,0,0,0,1,0,0,0,0,0},
	{1,1,1,0,1,0,0,0,0,0},
	{1,1,0,0,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
}; // 1이 방문 할 수 있는 칸, 0은 아님

bool visit[502][502]; // 해당 칸 방문했는지 여부 저장

int n = 7, m = 10; // n : 행의 수 / m : 열의 수
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 }; // 우, 하, 좌, 상 네 방향

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	visit[0][0] = 1; // 0,0 방문
	q.push({ 0, 0 }); // Queue 시작점 0, 0 삽입

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); // 현재 위치
		q.pop();

		cout << "(" << cur.first << ", " << cur.second << ") -> ";

		for (int dir = 0; dir < 4; ++dir) // 상 하 좌 우 칸을 살펴봄
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위 밖일 경우 넘어감
			{
				continue;
			}

			if (visit[nx][ny] || board[nx][ny] != 1) // 이미 방문한 칸이거나, 방문 할 수 없는 칸이면 넘어감
			{
				continue;
			}

			visit[nx][ny] = 1; // nx, ny 방문했다고 명시

			q.push({ nx, ny });
		}
	}
}