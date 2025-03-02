#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

/*
vector<int> bubblesort(vector<int>& arr) O(N^2)
{
	for (size_t i = 0; i < arr.size() - 1; ++i) {
		for (size_t j = 0; j < arr.size() - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	return arr;
}

vector<int> solution(vector<int> &arr) O(NlogN)
{
	sort(arr.begin(), arr.end());

	return arr;
}

int main()
{
	vector<int> arr{5,2,3,1,4,6,788,9,5};

	bubblesort(arr);
	// solution(arr);

	for (auto arrs : arr) {
		cout << arrs << endl;
	}
}
*/

/*
bool compare(int a, int b)
{
	return a > b;
}

vector<int> solution(vector<int>& arr)
{
	sort(arr.begin(), arr.end(), compare);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	return arr;
}

int main()
{
	vector<int> arr{ 1,4,6,76,3,3,5,6,8,7,5,4,3,12,2,6,657,8,5,4,3 };

	solution(arr);

	for (auto arrs : arr) {
		cout << arrs << ' ';
	}
}
*/

/*
vector<int> solution(vector<int> numbers) {
	set<int> sum;

	for (int i = 0; i < numbers.size(); ++i) {
		for (int j = i + 1; j < numbers.size(); ++j) {
			sum.insert(numbers[i] + numbers[j]);
		}
	}

	vector<int> answer(sum.begin(), sum.end());
	return answer;
}

int main()
{
	vector<int> arr1{ 2,1,3,4,1 };
	vector<int> arr2{ 5,0,2,7 };

	for (auto arrs : solution(arr1)) {
		cout << arrs << ' ';
	}

	cout << endl;

	for (auto arrs : solution(arr2)) {
		cout << arrs << ' ';
	}
}
*/

/*
int main()
{
	vector<string> days = { "월", "화", "수", "목", "금", "토", "일" };

	for (int i = 0; i <= 30; ++i) {
		cout << days[i % days.size()] << endl;
	}
}
*/

/*
vector<int> pattern_1 = { 1,2,3,4,5 };
vector<int> pattern_2 = { 2,1,2,3,2,4,2,5 };
vector<int> pattern_3 = { 3,3,1,1,2,2,4,4,5,5 };


vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> count(3);

	for (int i = 0; i < answers.size(); ++i) {
		if (answers[i] == pattern_1[i % pattern_1.size()]) {
			++count[0];
		}

		if (answers[i] == pattern_2[i % pattern_2.size()]) {
			++count[1];
		}

		if (answers[i] == pattern_3[i % pattern_3.size()]) {
			++count[2];
		}
	}

	int max_count = *max_element(count.begin(), count.end());

	for (int i = 0; i < 3; ++i) {
		if (max_count == count[i]) {
			answer.push_back(i + 1);
		}
	}

	return answer;
}

int main()
{
	vector<int> arr1 = { 1,2,3,4,5 };
	vector<int> arr2 = { 1,3,2,4,2 };

	for (auto arrs : solution(arr1)) {
		cout << arrs << ' ';
	}

	cout << endl;

	for (auto arrs : solution(arr2)) {
		cout << arrs << ' ';
	}
}
*/

/*
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0));

	for (int i = 0; i < arr1.size(); ++i) {
		for (int j = 0; j < arr2[1].size(); ++j) {
			for (int k = 0; k < arr2.size(); ++k) {
				answer[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	return answer;
}
*/

bool compare(pair<int, float>& a, pair<int, float>& b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<float> challenger(N + 2, 0.0);
	vector<float> fail(N + 2, 0.0);

	for (int i = 0; i < stages.size(); ++i) {
		for (int j = 1; j <= stages[i]; j++) {
			++challenger[j];
		}

		++fail[stages[i]];
	}

	vector<pair<int, float>> failRatio(N);

	for (int i = 0; i < N; ++i) {
		failRatio[i].first = i + 1;

		if (challenger[i + 1] == 0) {
			failRatio[i].second == 0;
		}

		else {
			failRatio[i].second = fail[i + 1] / challenger[i + 1];
		}
	}

	sort(failRatio.begin(), failRatio.end(), compare);

	for (int i = 0; i < N; ++i) {
		answer.push_back(failRatio[i].first);
	}

	return answer;
}