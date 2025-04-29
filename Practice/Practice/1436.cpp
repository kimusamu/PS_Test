// BOJ 1436

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	string str_title{};
	int check = 0;
	int title;

	for (title = 666; ;++title)
	{
		str_title = to_string(title);

		if (str_title.find("666") != string::npos)
		{
			check++;

			if (N == check)
			{
				cout << str_title;
				break;
			}
		}
	}
}