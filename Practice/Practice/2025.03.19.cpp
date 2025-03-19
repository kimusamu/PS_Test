#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

/*
unordered_map<char, char> bracketPair = { {')', '('}, {']', '['}, {'}', '{'} };

bool isValid(string& s, int start)
{
    stack<char> st;
    unsigned int sz = s.size();

    for (int i = 0; i < sz; i++)
    {
        char ch = s[(start + i) % sz];

        if (bracketPair.count(ch))
        {
            if (st.empty() || st.top() != bracketPair[ch])
            {
                return false;
            }

            st.pop();
        }

        else
        {
            st.push(ch);
        }
    }

    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        answer += isValid(s, i);
    }

    return answer;
}
*/

/*
int solution(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }

        else
        {
            st.pop();
        }
    }

    return st.empty();
}
*/

/*
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;

    int price_num = prices.size();

    for (int i = 0; i < price_num; i++)
    {
        while (!st.empty() && prices[st.top()] > prices[i])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        answer[st.top()] = price_num - st.top() - 1;
        st.pop();
    }

    return answer;
}
*/

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<stack<int>> lanes(board[0].size());

    for (int i = board.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j])
            {
                lanes[j].push(board[i][j]);
            }
        }
    }

    stack<int> bucket;
    int answer = 0;

    for (int m : moves)
    {
        if (lanes[m - 1].size())
        {
            int doll = lanes[m - 1].top();
            lanes[m - 1].pop();

            if (bucket.size() && bucket.top() == doll)
            {
                bucket.pop();
                answer += 2;
            }

            else
            {
                bucket.push(doll);
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({ {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 }) << endl;
    return 0;
}