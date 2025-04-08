// BOJ 10836

#include <iostream>
#include <vector>

using namespace std;

/*
int main()
{
	int wid_len = 0;
	int days = 0;

	cin >> wid_len >> days;

	vector<vector<int>> worms(wid_len, vector<int>(wid_len, 1));

	while (days--)
	{
		int zero = 0;
		int one = 0;
		int two = 0;

		cin >> zero >> one >> two;

		for (int i = wid_len - 1; i > 0; --i)
		{
			if (zero != 0)
			{
				worms[i][0] += 0;
				--zero;
			}

			else if (one != 0)
			{
				worms[i][0] += 1;
				--one;
			}

			else if (two != 0)
			{
				worms[i][0] += 2;
				--two;
			}
		}

		for (int i = 0; i < wid_len; ++i)
		{
			if (zero != 0)
			{
				worms[0][i] += 0;
				--zero;
			}

			else if (one != 0)
			{
				worms[0][i] += 1;
				--one;
			}

			else if (two != 0)
			{
				worms[0][i] += 2;
				--two;
			}
		}
	}

	for (int i = 1; i < wid_len; ++i)
	{
		for (int j = 1; j < wid_len; ++j)
		{
			worms[i][j] = worms[0][j];
		}
	}

	for (int i = 0; i < wid_len; ++i)
	{
		for (int j = 0; j < wid_len; ++j)
		{
			cout << worms[i][j] << " ";
		}

		cout << endl;
	}
} // 83점, 원래 제약 조건 의외의 아무 제약 조건 없을때 틀림
// 이중 벡터 사용으로 인한 메모리 문제 발생
// 벡터 하나만으로도 해결 (2 * 길이 - 1)
*/

int main()
{
	int wid_len = 0;
	int days = 0;

	cin >> wid_len >> days;

	vector<int> growth(2 * wid_len - 1, 1);
	vector<vector<int>> worms(wid_len, vector<int>(wid_len, 0));

	while (days--)
	{
		int index = 0;

		for (int i = 0; i < 3; ++i)
		{
			int grw_times = 0;
			cin >> grw_times;

			for (int j = 0; j < grw_times; ++j)
			{
				growth[index++] += i;
			}
		}
	}

	int index_2 = 0;

	for (int i = wid_len - 1; i >= 0; --i)
	{
		worms[i][0] += growth[index_2++];
	}

	for (int i = 1; i < wid_len; ++i)
	{
		for (int j = 0; j < wid_len; ++j)
		{
			worms[j][i] += growth[index_2];
		}

		index_2++;
	}

	for (int i = 0; i < wid_len; ++i)
	{
		for (int j = 0; j < wid_len; ++j)
		{
			cout << worms[i][j] << " ";
		}

		cout << endl;
	}
}