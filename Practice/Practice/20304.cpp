// BOJ 20304

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 각 번호(0 ~ n)에 대해 “보안 등급”(혹은 거리를) 저장할 배열
// 초기값을 -1로 두어 “아직 방문 안 함”을 표시
int visit[1000010];

int main()
{
	// 1) n: 노드(번호)들의 최댓값 (0번부터 n번까지)
	int n;
	cin >> n;

	// 2) m: 보안 등급이 0으로 설정된 초기 노드(바이러스 출발점) 개수
	int m;
	cin >> m;

	// 3) v: 보안 등급이 0인 초기 노드 번호들을 저장할 벡터
	vector<int> v;

	for (int i = 0; i < m; ++i)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	// 4) visit 배열을 -1로 채워 “아직 탐색되지 않음”을 표시
	//    (배열 크기는 n까지 접근 가능하도록 n+2 정도로 잡아둠)
	fill(visit, visit + n + 2, -1);

	// 5) BFS용 큐 선언
	queue<int> q;

	// 6) 초기 노드들에 대해 거리(보안 등급)를 0으로 설정하고 큐에 삽입
	for (auto& e : v)
	{
		visit[e] = 0;
		q.push(e);
	}

	int next;

	// 7) BFS 반복문: 큐가 빌 때까지
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		// 8) 현재 번호(cur)의 모든 비트 위치(0~30)를 뒤집어 인접 노드 생성
		for (int k = 0; k < 31; ++k)
		{
			if (cur & (1 << k))
			{
				// k번 비트가 1이면 → 0으로
				next = cur & ~(1 << k);
			}

			else
			{
				// k번 비트가 0이면 → 1로
				next = cur | (1 << k);
			}

			// 9) 생성된 번호가 범위 벗어나면 건너뛰기
			if (next > n)
			{
				continue;
			}

			// 10) 이미 방문했다면(visit[next]>=0) 건너뛰기
			if (visit[next] >= 0)
			{
				continue;
			}

			// 11) 아직 방문한 적 없는 노드라면
			//     거리를 현재 거리+1로 설정하고 큐에 추가
			visit[next] = visit[cur] + 1;
			q.push(next);
		}
	}

	// 12) 모든 번호(0~n) 중 최대 거리를 찾아 출력
	//     (가장 멀리 떨어진 번호의 보안 등급)
	int ans = 0;

	for (int i = 0; i <= n; ++i)
	{
		ans = max(ans, visit[i]);
	}

	cout << ans;
}

// 비밀번호의 최대값이 10이고 해커가 시도한 비밀번호가 3이라고 합시다.
// 그러면 3으로 부터 안전거리가 1인 수들은 3에서 한 비트씩 뒤집어가며 구할 수 있습니다.
// 0011 -> 0010 0001 0111 1011(1011은 10을 넘어가서 안전거리가 1이 아닙니다.)
// 안전거리가 2인 수들은 안전거리가 1인 수들로부터 비트를 뒤집어가며 위와 동일하게 구할 수 있습니다.
// 그러므로 시작점이 여러개인 bfs를 통해 문제를 해결 할 수 있습니다.