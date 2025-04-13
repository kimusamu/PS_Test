// BOJ 1406

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
	string str;
	cin >> str;

	list<char> lst;

	for (auto c : str)
	{
		lst.emplace_back(c);
	}

	auto cursor = lst.end();

	int cnt;
	cin >> cnt;

	while (cnt--)
	{
		char f_cmd;
		cin >> f_cmd;

		if ('L' == f_cmd)
		{
			if (cursor != lst.begin())
			{
				cursor--;
			}
		}

		else if ('D' == f_cmd)
		{
			if (cursor != lst.end())
			{
				cursor++;
			}
		}

		else if ('B' == f_cmd)
		{
			if (cursor != lst.begin())
			{
				cursor = lst.erase(--cursor);
				/*
				���� --cursor�� Ŀ���� �������� �̵����� ������ ��Ҹ� ����Ű���� �ϰ�,
				lst.erase�� ���� �� �� ���� ��ġ�� iterator�� ��ȯ�ϸ�,
				�� ��ȯ���� cursor�� ������ ���Ŀ��� ��ȿ�� iterator�� ����ϰ� �˴ϴ�.
				*/
			}
		}

		else if ('P' == f_cmd)
		{
			char c;
			cin >> c;

			lst.insert(cursor, c);
		}
	}

	for (char c : lst)
	{
		cout << c;
	}
}