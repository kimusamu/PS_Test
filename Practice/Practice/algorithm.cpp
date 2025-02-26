#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// count() O(N)
/*
int main()
{
	vector<int> v = { 1,4,3,4,5,4,5 };

	int ret = count(v.begin(), v.end(), 5);

	cout << ret << endl;

	return 0;
}
*/

//sort() O(NlogN)
/*
int main()
{
	vector<int> v = { 4,2,5,3,1 };

	sort(v.begin(), v.end());

	sort(v.rbegin(), v.rend());

	return 0;
}
*/

/*
struct Point
{
	int x, y;

	Point(int x, int y) : x(x), y(y){}
};

bool compare(const Point& a, const Point& b)
{
	if (a.x == b.x) {
		return a.y < b.y;
	}

	return a.x < b.x;
}

int main()
{
	vector<Point> points = { {3, 4}, {1, 2}, {3, 1}, {2, 5} };

	sort(points.begin(), points.end(), compare);

	for (const Point& p : points) {
		cout << "(" << p.x << ", " << p.y << ") ";
	}

	cout << endl;
}
*/

// next_permutation() O(N * N!)
/*
int main()
{
	vector<int> v = { 1,2,3 };

	do {
		for (int i : v) {
			cout << i << " ";
		}

		cout << endl;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
*/

// unique() O(N)
/*
int main()
{
	vector<int> v = { 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5 };

	auto newEnd = unique(v.begin(), v.end());

	for (auto it = v.begin(); it != newEnd; ++it) {
		cout << *it << " ";
	}

	cout << endl;

	cout << v.size() << endl;

	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}
*/

// binary_search() O(logN)
/*
int main()
{
	vector<int> v = { 1,2,3,4,5 };

	cout << binary_search(v.begin(), v.end(), 3) << endl;
	cout << binary_search(v.begin(), v.end(), 7) << endl;

	return 0;
}
*/

// max_element(), min_element() O(N)
int main()
{
	vector<int> v = { 1, 3, 5, 7, 2, 4, 6 };

	auto maxIt = max_element(v.begin(), v.end());
	auto minIt = min_element(v.begin(), v.end());

	cout << *maxIt << endl;
	cout << *minIt << endl;
}





