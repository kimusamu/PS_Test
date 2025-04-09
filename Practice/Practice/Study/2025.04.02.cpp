#include "practice.h"

/*
vector<vector<int>> multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	vector<vector<int>> result(3, vector<int>(3, 0));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return result;
}

vector<vector<int>> transpose(vector<vector<int>> matrix)
{
	vector<vector<int>> result(3, vector<int>(3, 0));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			result[j][i] = matrix[i][j];
		}
	}
}

vector<vector<int>> solution(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	vector<vector<int>> multiplied = multiply(matrix1, matrix2);
	vector<vector<int>> transposed = transpose(multiplied);

	return transposed;
}
*/

/*
vector<vector<int>> solution(int n)
{
	vector<vector<int>> snail_array(n, vector<int>(n, 0));
	int num = 1;
	int start_row = 0;
	int end_row = n - 1;
	int start_col = 0;
	int end_col = n - 1;

	while (start_row <= end_row && start_col <= end_col)
	{
		for (int i = start_col; i <= end_col; ++i)
		{
			snail_array[start_row][i] = ++num;
		}

		++start_row;

		for (int i = start_row; i <= end_row; ++i)
		{
			snail_array[i][end_col] = ++num;
		}

		--end_col;

		if (start_row <= end_row)
		{
			for (int i = end_col; i >= start_col; --i)
			{
				snail_array[end_row][i] = ++num;
			}

			--end_row;
		}

		if (start_col <= end_col)
		{
			for (int i = end_row; i >= start_row; --i)
			{
				snail_array[i][start_col] = ++num;
			}

			++start_col;
		}
	}

	return snail_array;
}
*/

/*
vector<int> solution(string s) {
	int transforms = 0;
	int removed_zeros = 0;

	while (s != "1")
	{
		++transforms;

		removed_zeros += count(s.begin(), s.end(), '0');

		int ones_count = count(s.begin(), s.end(), '1');
		s = bitset<32>(ones_count).to_string();
		s = s.substr(s.find('1'));
	}

	return { transforms, removed_zeros };
}
*/

/*
int solution(vector<int> topping) {
	int answer = 0;
	unordered_map<int, int> topping_cnt;
	unordered_set<int> half_topping;

	for (auto t : topping)
	{
		if (topping_cnt.find(t) == topping_cnt.end())
		{
			topping_cnt[t] = 1;
		}

		else
		{
			++topping_cnt[t];
		}
	}

	for (int i = 0; i < topping.size(); ++i)
	{
		half_topping.insert(topping[i]);
		--topping_cnt[topping[i]];

		if (topping_cnt[topping[i]] == 0)
		{
			topping_cnt.erase(topping[i]);
		}

		if (topping_cnt.size() == half_topping.size())
		{
			++answer;
		}
	}

	return answer;
}
*/

/*
vector<int> solution(int brown, int yellow) {
	int total_size = brown + yellow;

	for (int vertical = 3; vertical <= sqrt(total_size); ++vertical)
	{
		if (total_size % vertical == 0)
		{
			int horizontal = total_size / vertical;

			if (brown == (horizontal + vertical - 2) * 2)
			{
				return { horizontal, vertical };
			}
		}
	}

	return {};
}
*/

/*
int solution(int n)
{
	return bitset<32>(n).count();
}
*/

/*
vector<int> solution(vector<string> keyinput, vector<int> board) {
	vector<int> v(2, 0);

	for (string s : keyinput)
	{
		if (s == "up" && v[1] < +board[1] / 2)
		{
			++v[1];
		}

		else if (s == "down" && v[1] > -board[1] / 2)
		{
			--v[1];
		}

		else if (s == "left" && v[0] > -board[0] / 2)
		{
			--v[0];
		}

		else if (s == "right" && v[0] < +board[0] / 2)
		{
			++v[0];
		}
	}

	return v;
}
*/

/*
int solution(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[m][n];
}
*/

/*
int solution(const vector<int> nums)
{
	int n = nums.size();
	vector<int> dp(n, 1);

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}
*/