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