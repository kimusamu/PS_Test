#include "practice.h"

/*
string solution(string s)
{
	vector<int> counts(26, 0);

	for (char c : s)
	{
		counts[c - 'a']++;
	}

	string sorted_str = "";

	for (int i = 0; i < 26; ++i)
	{
		sorted_str += string(counts[i], i + 'a');
	}

	return sorted_str;
}
*/

/*
vector<int> solution(vector<int> arr1, vector<int> arr2)
{
	vector<int> merged;
	int i = 0;
	int j = 0;

	while (i < arr1.size() && j < arr2.size())
	{
		if (arr1[i] <= arr2[j])
		{
			merged.push_back(arr1[i]);
			++i;
		}

		else
		{
			merged.push_back(arr2[j]);
			++j;
		}
	}

	while (i < arr1.size())
	{
		merged.push_back(arr1[i]);
		++i;
	}

	while (j < arr2.size())
	{
		merged.push_back(arr2[j]);
		++j;
	}

	return merged;
}
*/

/*
int idx;

bool compare(string a, string b)
{
	return a[idx] == b[idx] ? a < b : a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n)
{
	idx = n;

	sort(strings.begin(), strings.end(), compare);

	return strings;
}
*/

/*
long long solution(long long n) {
	string str = to_string(n);

	sort(str.rbegin(), str.rend());
	return stoll(str);
}
*/

/*
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> sub_array;

	for (const auto& cmd : commands)
	{
		sub_array.assign(array.begin() + (cmd[0] - 1), array.begin() + cmd[1]);
		sort(sub_array.begin(), sub_array.end());
		answer.push_back(sub_array[cmd[2] - 1]);
	}

	return answer;
}
*/

/*
bool compare(const string& lhs, const string& rhs)
{
	return (lhs + rhs) > (rhs + lhs);
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> strings;

	for (auto n : numbers)
	{
		strings.push_back(to_string(n));
	}

	sort(strings.begin(), strings.end(), compare);

	for (auto s : strings)
	{
		answer += s;
	}

	return answer[0] == '0' ? "0" : answer;
}
*/

/*
int counts[100001] = {};

void update_counts(const string& s)
{
	string num_str;

	for (char ch : s)
	{
		if (isdigit(ch))
		{
			num_str += ch;
		}

		else
		{
			if (!num_str.empty())
			{
				counts[stoi(num_str)]++;
				num_str.clear();
			}
		}
	}
}

vector<int> solution(string s) {
	vector<int> answer;

	update_counts(s);

	vector<pair<int, int>> freq_pairs;

	for (int i = 1; i <= 100000; ++i)
	{
		if (counts[i] > 0)
		{
			freq_pairs.push_back({ counts[i], i });
		}
	}

	sort(freq_pairs.rbegin(), freq_pairs.rend());

	for (const auto& p : freq_pairs)
	{
		answer.push_back(p.second);
	}

	return answer;
}
*/

struct Pos
{
	int r;
	int c;
	int height_diff;

	bool operator<(const Pos& p) const
	{
		return height_diff > p.height_diff;
	}
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool visited[301][301];

bool is_valid(int nr, int nc, int rows, int cols)
{
	return nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc];
}

int solution(vector<vector<int>> land, int height) {
	int total_cost = 0;
	int rows = land.size();
	int cols = land[0].size();

	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0 });

	while (!pq.empty())
	{
		Pos current = pq.top();
		pq.pop();

		if (visited[current.r][current.c])
		{
			continue;
		}

		total_cost += current.height_diff;

		for (int i = 0; i < 4; ++i)
		{
			int nr = current.r + dy[i];
			int nc = current.c + dx[i];

			if (is_valid(nr, nc, rows, cols))
			{
				int diff = abs(land[current.r][current.c] - land[nr][nc]);

				if (diff > height)
				{
					pq.push({ nr, nc, diff });
				}

				else
				{
					pq.push({ nr, nc, 0 });
				}
			}
		}

		visited[current.r][current.c] = true;
	}

	return total_cost;
}