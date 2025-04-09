// BOJ 2577

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int abc = a * b * c;

	string str = to_string(abc);
	vector<int> vi(10);

	for (char c : str)
	{
		vi[static_cast<int>(c) - 48] += 1;
	}

	for (int i = 0; i < vi.size(); ++i)
	{
		cout << vi[i] << endl;
	}
}