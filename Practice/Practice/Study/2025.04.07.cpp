#include "practice.h"

/*
int solution(vector<vector<int>> arr)
{
	int n = arr[0].size();
	vector<vector<int>> dp(4, vector<int>(n, 0));

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[2][0] = arr[2][0];
	dp[3][0] = arr[0][0] + arr[2][0];

	for (int i = 1; i < n; ++i)
	{
		dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] = arr[1][i] + max({dp[0][i - 1], dp[2][i - 1], dp[3][i - 1]});
		dp[2][i] = arr[2][i] + max(dp[0][i - 1], dp[1][i - 1]);
		dp[3][i] = arr[0][i] + arr[2][i] + dp[1][i - 1];
	}

	return max({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1], dp[3][n - 1] });
}
*/

/*
int solution(int n)
{
	vector<int> fibo = { 0, 1 };

	for (int i = 2; i <= n; ++i)
	{
		fibo.push_back((fibo[i - 1] + fibo[i - 2]) % 1234567);
	}

	return fibo[n];
}
*/

/*
long long solution(int n)
{
	if (n == 1)
	{
		return 1;
	}

	if (n == 2)
	{
		return 2;
	}

	vector<long long> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}

	return dp[n];
}
*/

/*
int solution(vector<vector<int>> triangle) {
	int L = triangle.size(); // 트리 레벨

	for (int i = L - 2; i > -1; i--) // i = L - 2, L - 3, ... , 1, 0
	{
		for (int j = 0; j < triangle[i].size(); j++) // i 레벨 노드의 개수만큼 서브트리 문제를 해결해 나간다
		{
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}

	return triangle[0][0];
}
*/

/*
int solution(vector<vector<int>> triangle) {
	int n = triangle.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		dp[n - 1][i] = triangle[n - 1][i];
	}

	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}

	return dp[0][0];
}
*/

/*
int solution(vector<vector<int>> land)
{
	for (int i = 1; i < land.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int max_val = 0;

			for (int k = 0; k < 4; ++k)
			{
				if (k != j)
				{
					max_val = max(max_val, land[i - 1][k]);
				}
			}

			land[i][j] += max_val;
		}
	}

	return *max_element(land.back().begin(), land.back().end());
}
*/

/*
int solution(vector<int> money) {
	int n = money.size();
	vector<int> dp1(n, 0);
	vector<int> dp2(n, 0);

	dp1[0] = money[0];
	dp1[1] = money[0];

	for (int i = 2; i < n - 1; ++i)
	{
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
	}

	dp2[1] = money[1];

	for (int i = 2; i < n; ++i)
	{
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}

	int answer = max(dp1[n - 2], dp2[n - 1]);

	return answer;
}
*/

/*
int solution(vector<vector<int>> board)
{
	int row = board.size();
	int col = board[0].size();

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (board[i][j] == 1)
			{
				int up = board[i - 1][j];
				int left = board[i][j - 1];
				int up_left = board[i - 1][j - 1];

				board[i][j] = min(min(up, left), up_left) + 1;
			}
		}
	}

	int max_val = 0;

	for (const auto& b : board)
	{
		max_val = max(max_val, *max_element(b.begin(), b.end()));
	}

	return max_val * max_val;
}
*/

/*
int solution(vector<string> strs, string t)
{
	int INF = numeric_limits<int>::max();
	int n = t.length();
	vector<long long> dp(n + 1, INF);

	dp[0] = 0;

	unordered_set<int> sizes;

	for (const auto& s : strs)
	{
		sizes.insert(s.length());
	}

	unordered_set<string> strs_set(strs.begin(), strs.end());

	for (int i = 1; i <= n; ++i)
	{
		for (int size : sizes)
		{
			if (i >= size && strs_set.count(t.substr(i - size, size)))
			{
				dp[i] = min(dp[i], dp[i - size] + 1);
			}
		}
	}

	return dp[n] != INF ? dp[n] : -1;
}
*/
