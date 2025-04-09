// BOJ 10808

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str{};
	vector<int> cnt(26);

	cin >> str;

	for (char c : str)
	{
		int num = static_cast<int>(c);
		cnt[num - 97] += 1;
	}

	for (int i = 0; i < cnt.size(); ++i)
	{
		cout << cnt[i] << " ";
	}
}