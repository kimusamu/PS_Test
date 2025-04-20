// BOJ 5430

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		string cmd;
		cin >> cmd;

		int deq_size;
		cin >> deq_size;

		string deq;
		cin >> deq;

		deque<int> dq;
		string str{ "" };

		bool turn = false, error = false;

		for (int i = 0; i < deq.size(); ++i)
		{
			if (deq[i] == '[')
			{
				continue;
			}

			else if (deq[i] == ',' || deq[i] == ']')
			{
				if (!str.empty())
				{
					dq.push_back(stoi(str));
					str.clear();
				}
			}

			else
			{
				str += deq[i];
			}
		}

		for (int i = 0; i < cmd.size(); ++i)
		{
			if (cmd[i] == 'R')
			{
				turn = !turn;
			}

			else if (cmd[i] == 'D')
			{
				if (dq.size() == 0)
				{
					error = true;
					break;
				}

				if (turn)
				{
					dq.pop_back();
				}

				else
				{
					dq.pop_front();
				}
			}
		}

		if (error)
		{
			cout << "error\n";
		}

		else
		{
			if (turn)
			{
				reverse(dq.begin(), dq.end());
			}

			cout << "[";

			for (int i = 0; i < dq.size(); ++i)
			{
				if (i == dq.size() - 1)
				{
					cout << dq[i];
				}

				else
				{
					cout << dq[i] << ',';
				}
			}

			cout << "]\n";
		}
	}
}