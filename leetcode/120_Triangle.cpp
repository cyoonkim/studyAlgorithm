/*
Runtime: 4 ms, faster than 93.70% of C++ online submissions for Triangle.
Memory Usage: 8.5 MB, less than 82.18% of C++ online submissions for Triangle.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
	int size = triangle.size();

	for (int i = 1; i < size; i++) {
		triangle[i][0] += triangle[i - 1][0];
		for (int j = 1; j < i; j++) {
			triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
		triangle[i][i] += triangle[i - 1][i-1];
	}

	int min_val = INT_MAX;
	for (int i = 0; i < size; i++) {
		min_val = min(min_val, triangle[size - 1][i]);
	}
	return min_val;
}

int main(void) {
	vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
	cout << minimumTotal(triangle) << endl;
	return 0;
}