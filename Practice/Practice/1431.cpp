// BOJ 1431

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<string> v;

bool cmp(string& a, string& b)
{
	int acnt = 0;
	int bcnt = 0;

	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}

	for (int i = 0; i < a.size(); ++i)
	{
		if (isdigit(a[i]))
		{
			acnt += (a[i] - '0');
		}
	}

	for (int i = 0; i < b.size(); ++i)
	{
		if (isdigit(b[i]))
		{
			bcnt += (b[i] - '0');
		}
	}

	if (acnt != bcnt)
	{
		return acnt < bcnt;
	}

	return a < b;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		v.push_back(str);
	}
	
	sort(v.begin(), v.end(), cmp);

	for (auto a : v)
	{
		cout << a << '\n';
	}
}