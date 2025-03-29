#include "practice.h"

vector<vector<int>> rotate_90(const vector<vector<int>>& arr)
{
	int n = arr.size();
	vector<vector<int>> rotated_arr(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			rotated_arr[j][n - i - 1] = arr[i][j];
		}
	}

	return rotated_arr;
}

vector<vector<int>> solution(vector<vector<int>> arr, int n)
{
	vector<vector<int>> rotated_arr = arr;

	for (int i = 0; i < n; ++i)
	{
		rotated_arr = rotate_90(rotated_arr);
	}

	return rotated_arr;
}