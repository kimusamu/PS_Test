// BOJ 5397

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		string str;
		list<char> lst;
		auto cursor = lst.end();

		cin >> str;

		for (auto a : str)
		{
			if ('<' == a)
			{
				if (cursor != lst.begin())
				{
					cursor--;
				}
			}

			else if ('>' == a)
			{
				if (cursor != lst.end())
				{
					cursor++;
				}
			}

			else if ('-' == a)
			{
				if (cursor != lst.begin())
				{
					cursor = lst.erase(--cursor);
				}
			}

			else
			{
				lst.insert(cursor, a);
			}
		}

		for (auto a : lst)
		{
			cout << a;
		}

		cout << endl;
	}
}