#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findMinArrowShots(vector<vector<int>>& points) {
	int minArrow = 1;
	sort(points.begin(), points.end());

	int arrow_point = points[0][1];
	for (int i = 1; i < points.size(); i++) {
		if (arrow_point >= points[i][0]) {
			if (arrow_point < points[i][1]) continue;
			arrow_point = points[i][1];
		}
		else {
			arrow_point = points[i][1];
			minArrow++;
		}
	}

	return minArrow;
}

int main(void) {
	vector<vector<int>> points = { {1,2}, {2,3}, {3,4}, {4,5}};

	cout << findMinArrowShots(points);

	return 0;
}