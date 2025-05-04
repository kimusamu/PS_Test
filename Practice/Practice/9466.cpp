// BOJ 9466

#include <iostream>

using namespace std;

int room1[100002]; // 학생의 번호
int room2[100002]; // 방문/사이클 검사 상태
int n;

void run(int a)
{
	int cur = a; // 현재 학생

	while (true)
	{
		room2[cur] = a;
		cur = room1[cur]; // 다음 학생으로 이동

		// 이번 방문에서 지나간 학생에 도달했을때
		if (room2[cur] == a)
		{
			while (room2[cur] != -1) // 사이클 만들기
			{
				room2[cur] = -1;
				cur = room1[cur];
			}

			return;
		}

		// 이전 방문에서 지나간 학생에 도달했을때
		else if (room2[cur] != 0)
		{
			return;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> n;

		fill(room2 + 1, room2 + n + 1, 0); // 전부 다 들어가지 않았음으로 초기화

		for (int i = 1; i <= n; ++i)
		{
			cin >> room1[i];
		}

		int ans = 0;

		for (int i = 1; i <= n; ++i)
		{
			if (room2[i] == 0) // 만약 안들어갔으면
			{
				run(i); // run 함수 실시
			}
		}

		int cnt = 0;

		for (int i = 1; i <= n; ++i)
		{
			if (room2[i] != -1) // 만약 짝 안지어졌으면
			{
				cnt++; // 올리기
			}
		}

		cout << cnt << '\n';
	}
}

/*

n = 7
room1: [–, 3,1,3,7,3,4,6]
// 인덱스 1~7

1) i=1 → run(1):
   경로 표시: 1→3, but room2[3]==0 → 표시 → cur=3→room1[3]=3
   이제 room2[3]==1? (아니니) room2[3]!=0이므로 return.
   (사이클 아님)

2) i=2 → run(2):
   2→1(→3→3… 하지만 1,3 이미 표시됐으므로 사이클 아님)

3) i=3 → run(3):
   3→3, 처음에 room2[3]==0이니 표시, 다음 cur=3, room2[3]==3이므로
   사이클 발견 → 해당 정점 3만 room2[3]=-1로 표시

… 이후 4→7→6→4 경로에서 4,7,6이 cycle로 표시

최종 room2: [–,1,2,-1,-1,-1,-1,-1]
→ `-1`인 3,4,6,7 네 명만 팀에 속함 → 나머지 `cnt=3`

*/