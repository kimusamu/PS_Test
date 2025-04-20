// BOJ 4949

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		string str;
		getline(cin, str);

		if (str == ".")
		{
			break;
		}

		stack<char> s;
		bool valid = true;

		for (auto a : str)
		{
			if (a == '(' || a == '[')
			{
				s.push(a);
			}

			else if (a == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					valid = false;
					break;
				}

				s.pop();
			}

			else if (a == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					valid = false;
					break;
				}

				s.pop();
			}
		}

		if (!s.empty())
		{
			valid = false;
		}

		if (valid)
		{
			cout << "yes\n";
		}

		else
		{
			cout << "no\n";
		}
	}
}