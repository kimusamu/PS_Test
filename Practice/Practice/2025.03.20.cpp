#include <iostream>
#include <iterator>
#include <string>

#include <cmath>
#include <algorithm>

#include <vector>
#include <stack>
#include <queue>

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

using namespace std;

/*
string solution(int n, int k, vector<string> cmd) {
    stack<int> deleted;
    vector<int> up;
    vector<int> down;

    for (int i = 0; i < n + 2; ++i)
    {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }

    k++;

    for (int i = 0; i < cmd.size(); ++i)
    {
        if (cmd[i][0] == 'C')
        {
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            if (down[k] == n + 1)
            {
                k = up[k];
            }

            else
            {
                k = down[k];
            }
        }

        else if (cmd[i][0] == 'Z')
        {
            auto r = deleted.top();
            down[up[r]] = r;
            up[down[r]] = r;
            deleted.pop();
        }

        else
        {
            int sz = stoi(cmd[i].substr(2));

            if (cmd[i][0] == 'U')
            {
                for (int j = 0; j < sz; ++j)
                {
                    k = up[k];
                }
            }

            else if (cmd[i][0] == 'D')
            {
                for (int j = 0; j < sz; ++j)
                {
                    k = down[k];
                }
            }
        }
    }

    string answer = "";
    answer.append(n, 'O');

    while (!deleted.empty())
    {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }

    return answer;
}
*/

/*
int solution(int N, int K)
{
    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        for (int i = 0; i < K - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }

    return q.front();
}
*/

/*
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days_left(n);

    for (int i = 0; i < n; ++i)
    {
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }

    int count = 0;
    int max_day = days_left[0];

    for (int i = 0; i < n; ++i)
    {
        if (days_left[i] <= max_day)
        {
            count++;
        }

        else
        {
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(count);
    return answer;
}
*/

/*
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> cd1;
    queue<string> cd2;
    queue<string> g;

    for (const string& s : cards1)
    {
        cd1.push(s);
    }

    for (const string& s : cards2)
    {
        cd2.push(s);
    }

    for (const string& s : goal)
    {
        g.push(s);
    }

    while (!g.empty())
    {
        if (!cd1.empty() && cd1.front() == g.front())
        {
            cd1.pop();
            g.pop();
        }

        else if (!cd2.empty() && cd2.front() == g.front())
        {
            cd2.pop();
            g.pop();
        }

        else
        {
            answer = "No";
            return answer;
        }
    }

    answer = "Yes";
    return answer;
}
*/

/*
void mapping(vector<int>& hash, const vector<int>& arr, int target)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] > target)
        {
            continue;
        }

        hash[arr[i]] = 1;
    }
}

bool solution(vector<int> arr, int target)
{
    vector<int> hash(target + 1, 0);
    mapping(hash, arr, target);

    for (int i = 0; i < arr.size(); ++i)
    {
        int num = target - arr[i];

        if (arr[i] == num)
        {
            continue;
        }

        if (num < 0)
        {
            continue;
        }

        if (hash[num])
        {
            return true;
        }
    }

    return false;
}
*/

long long polynomail_hash(const string& str)
{
    const int p = 31;
    const long long m = 1000000007;
    long long hash_value = 0;

    for (char c : str)
    {
        hash_value = (hash_value * p + c) % m;
    }

    return hash_value;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
    unordered_set<long long> hash_set;

    for (const string& str : string_list)
    {
        long long hash = polynomail_hash(str);
        hash_set.insert(hash);
    }

    vector<bool> result;

    for (const string& query : query_list)
    {
        long long query_hash = polynomail_hash(query);
        bool found = (hash_set.find(query_hash) != hash_set.end());

        result.push_back(found);
    }

    return result;
}