#include "practice.h"

/*
vector<vector<int>> results;
vector<int> selected_nums;

void backtrack(int N, int sum, int start)
{
	if (sum == 10)
	{
		results.push_back(selected_nums);
		return;
	}

	for (int i = start; i <= N; ++i)
	{
		if (sum + i <= 10)
		{
			selected_nums.push_back(i);
			backtrack(N, sum + i, i + 1);
			selected_nums.pop_back();
		}
	}
}

vector<vector<int>> solution(int N)
{
	backtrack(N, 0, 1);
	return results;
}
*/

/*
vector<vector<int>> board;

bool is_valid(int num, int row, int col)
{
	for (int i = 0; i < 9; ++i)
	{
		if (board[row][i] == num || board[i][col] == num)
		{
			return false;
		}
	}

	int start_row = row - row % 3;
	int start_col = col - col % 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i + start_row][j + start_col] == num)
			{
				return false;
			}
		}
	}

	return true;
}

pair<int, int> find_empty_position()
{
	for (int row = 0; row < 9; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
			if (board[row][col] == 0)
			{
				return { row, col };
			}
		}
	}

	return { -1, -1 };
}

void solve_sudoku()
{
	pair<int, int> pos = find_empty_position();

	if (pos.first == -1)
	{
		return;
	}

	for (int num = 1; num <= 9; ++num)
	{
		if (is_valid(num, pos.first, pos.second))
		{
			board[pos.first][pos.second] = num;

			solve_sudoku();

			if (find_empty_position().first == -1)
			{
				return;
			}

			board[pos.first][pos.second] = 0;
		}
	}
}

vector<vector<int>> solution(vector<vector<int>> input_board)
{
	board = input_board;

	solve_sudoku();

	return board;
}
*/

/*
int max_depth = 0;
bool visited[8] = { false };

void explore_dungeon(int depth, int power, vector<vector<int>>& dungeons)
{
	if (max_depth < depth)
	{
		max_depth = depth;
	}

	for (int i = 0; i < dungeons.size(); ++i)
	{
		if (visited[i] || dungeons[i][0] > power)
		{
			continue;
		}

		visited[i] = true;
		explore_dungeon(depth + 1, power - dungeons[i][1], dungeons);
		visited[i] = false;
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	explore_dungeon(0, k, dungeons);

	return max_depth;
}
*/

/*
bool is_same_row(int placed_row, int current_row)
{
	return placed_row == current_row;
}

bool is_diagonal_attack(int placed_col, int placed_row, int current_col, int current_row)
{
	return abs(placed_col - current_col) == abs(placed_row - current_row);
}

bool is_safe_position(const vector<int>& queen, int col, int row)
{
	for (int i = 0; i < col; ++i)
	{
		if (is_same_row(queen[i], row) || is_diagonal_attack(i, queen[i], col, row))
		{
			return false;
		}
	}

	return true;
}

long long place_queens(vector<int>& queen, int col)
{
	int n = queen.size();

	if (col == n)
	{
		return 1;
	}

	long long count = 0;

	for (int row = 0; row < n; ++row)
	{
		if (is_safe_position(queen, col, row))
		{
			queen[col] = row;
			count += place_queens(queen, col + 1);
			queen[col] = -1;
		}
	}

	return count;
}

long long solution(int n) {
	vector<int> queen(n, -1);

	return place_queens(queen, 0);
}
*/

/*
vector<int> answer;
vector<int> ryan(11, 0);

int max_score = -1;

int calc_score_diff(const vector<int>& apeach)
{
	int score_apeach = 0;
	int score_ryan = 0;

	for (int i = 0; i < 11; ++i)
	{
		if (apeach[i] == 0 && ryan[i] == 0)
		{
			continue;
		}

		if (apeach[i] >= ryan[i])
		{
			score_apeach += 10 - i;
		}

		else
		{
			score_ryan += 10 - i;
		}
	}

	return score_ryan - score_apeach;
}

void dfs(const vector<int> apeach, int score, int arrow)
{
	if (score == -1 || arrow == 0)
	{
		ryan[10] = arrow;

		int score_diff = calc_score_diff(apeach);

		if (score_diff > 0 && max_score < score_diff)
		{
			max_score = score_diff;
			answer = ryan;
		}

		ryan[10] = 0;

		return;
	}

	if (arrow > apeach[score])
	{
		ryan[score] = apeach[score] + 1;
		dfs(apeach, score - 1, arrow - apeach[score] - 1);
		ryan[score] = 0;
	}

	dfs(apeach, score - 1, arrow);
}

vector<int> solution(int n, vector<int> info) {
	dfs(info, 10, n);

	if (max_score == -1)
	{
		answer.push_back(-1);
	}

	return answer;
}
*/

/*
int solution(int n, vector<int> weak, vector<int> dist) {
	int length = weak.size();

	for (int i = 0; i < length; ++i)
	{
		weak.push_back(weak[i] + n);
	}

	int answer = dist.size() + 1;

	sort(dist.begin(), dist.end());

	do {
		for (int start = 0; start < length; ++start)
		{
			int cnt = 1;
			int position = weak[start] + dist[cnt - 1];

			for (int index = start; index < start + length; ++index)
			{
				if (position < weak[index])
				{
					cnt++;

					if (cnt > dist.size())
					{
						break;
					}

					position = weak[index] + dist[cnt - 1];
				}
			}

			answer = min(answer, cnt);
		}
	} while (next_permutation(dist.begin(), dist.end()));

	return answer > dist.size() ? -1 : answer;
}
*/
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
int n, m;

bool is_out_of_bounds(int r, int c)
{
	return r < 0 || r >= n || c < 0 || c >= m;
}

pair<bool, int> play_game(vector<vector<int>>& board, int cur_r, int cur_c, int op_r, int op_c)
{
	if (board[cur_r][cur_c] == 0)
	{
		return { false, 0 };
	}

	pair<bool, int> result = { false, 0 };

	for (int dir = 0; dir < 4; ++dir)
	{
		int next_r = cur_r + dx[dir];
		int next_c = cur_c + dy[dir];

		if (is_out_of_bounds(next_r, next_c) || board[next_r][next_c] == 0)
		{
			continue;
		}

		board[cur_r][cur_c] = 0;

		auto [op_win, steps] = play_game(board, op_r, op_c, next_r, next_c);

		board[cur_r][cur_c] = 1;

		if (!op_win)
		{
			if (!result.first || result.second > steps + 1)
			{
				result = { true, steps + 1 };
			}
		}

		else if (!result.first)
		{
			result = { false, max(result.second, steps + 1) };
		}
	}

	return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	n = board.size();
	m = board[0].size();

	auto [_, steps] = play_game(board, aloc[0], aloc[1], bloc[0], bloc[1]);

	return steps;
}