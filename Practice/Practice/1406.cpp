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
				먼저 --cursor로 커서를 왼쪽으로 이동시켜 삭제할 요소를 가리키도록 하고,
				lst.erase는 삭제 후 그 다음 위치의 iterator를 반환하며,
				이 반환값을 cursor에 저장해 이후에도 유효한 iterator를 사용하게 됩니다.
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