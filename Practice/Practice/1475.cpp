// BOJ 1475

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	vector<int> v(10);
	int set = 1;
	cin >> str;

	for (char c : str)
	{
		if (c == '6' || c == '9')
		{
			v[6] += 1;
		}
		
		else
		{
			v[static_cast<int>(c) - 48] += 1;
		}
	}

	if (v[6] > 1)
	{
		if (v[6] % 2 == 0)
		{
			v[6] /= 2;
		}

		else
		{
			v[6] /= 2;
			v[6] += 1;
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		set = max(set, v[i]);
	}

	cout << set << endl;
}