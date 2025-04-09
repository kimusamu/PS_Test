#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

/*
vector<int> pattern1 = {1, 2, 3, 4, 5};
vector<int> pattern2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> pattern3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	vector<int> cnt(3);

	for (int i = 0; i < answers.size(); ++i)
	{
		if (answers[i] == pattern1[i % pattern1.size()])
		{
			++cnt[0];
		}

		if (answers[i] == pattern2[i % pattern2.size()])
		{
			++cnt[1];
		}

		if (answers[i] == pattern3[i % pattern3.size()])
		{
			++cnt[2];
		}
	}

	int max_cnt = *max_element(cnt.begin(), cnt.end());

	for (int i = 0; i < 3; ++i) {
		if (max_cnt == cnt[i])
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}
*/

/*
bool compare(pair<int, float>& a, pair<int, float>& b)
{
	if (a.second == b.second)
	{
		return a.first > b.first;
	}

	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<float> challenger(N + 2, 0.0);
	vector<float> fail(N + 2, 0.0);

	for (int i = 0; i < stages.size(); ++i)
	{
		for (int j = 0; j < stages[i]; j++)
		{
			challenger[j]++;
		}

		fail[stages[i]]++;
	}

	vector<pair<int, float>> failRatio(N);

	for (int i = 0; i < N; i++)
	{
		failRatio[i].first = i + 1;

		if (challenger[i + 1] == 0)
		{
			failRatio[i].second = 0;
		}

		else
		{
			failRatio[i].second = fail[i + 1] / challenger[i + 1];
		}
	}

	sort(failRatio.begin(), failRatio.end(), compare);

	for (int i = 0; i < N; i++)
	{
		answer.push_back(failRatio[i].first);
	}

	return answer;
}
*/

/*
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};

bool visited[11][11][4];

int todir(char dir)
{
	int ret{};

	if (dir == 'U')
	{
		ret = 0;
	}

	else if (dir == 'R')
	{
		ret = 1;
	}

	else if (dir == 'D')
	{
		ret = 2;
	}

	else if (dir == 'L')
	{
		ret = 3;
	}

	return ret;
}

bool isNotValid(int x, int y)
{
	return x < 0 || y < 0 || x > 11 || y > 11;
}

int opposite(int dir)
{
	return (dir + 2) % 4;
}

int solution(string dirs) {
	int answer = 0;
	int x = 5, y = 5;

	for (auto c : dirs)
	{
		int dir = todir(c);
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (isNotValid(nx, ny))
		{
			continue;
		}

		if (visited[x][y][dir] == false)
		{
			visited[x][y][dir] = true;
			visited[nx][ny][opposite(dir)] = true;

			answer++;
		}

		x = nx;
		y = ny;
	}

	return answer;
}
*/

/*
bool solution(string s)
{
	stack<char> s;

	for (auto c : s)
	{
		if (c == '(')
		{
			s.push_back(c);
		}

		else if (c == ')')
		{
			if (s.empty())
			{
				return false;
			}

			else
			{
				s.pop_back();
			}
		}
	}

	return s.empty();
}
*/

string solution(int decimal)
{
	stack<int> s;

	if (decimal == 0)
	{
		return "0";
	}

	while (decimal > 0)
	{
		s.push(decimal % 2);
		decimal /= 2;
	}

	string binary = "";

	while (!s.empty())
	{
		binary += to_string(s.top());
		s.pop();
	}

	return binary;
}
