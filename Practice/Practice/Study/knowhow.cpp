#include <iostream>
#include <vector>

using namespace std;

// 조기반환
/*
double total_price(int quantity, double price)
{
	double total = quantity * price;

	if (total > 100) {
		return total * 0.9;
	}

	return total;
}

int main()
{
	cout << total_price(4, 50) << endl;

	return 0;
}
*/

// 보호구문
double get_avg(const vector<int>& arr, int N)
{
	if (arr.empty()) {
		return -1;
	}

	if (N == 0) {
		return -1;
	}

	int sum = 0;

	for (int num : arr) {
		sum += num;
	}

	return sum / N;
}