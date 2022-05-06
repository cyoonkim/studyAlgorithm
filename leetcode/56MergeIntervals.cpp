/*
Runtime: 83 ms, faster than 16.33 % of C++ online submissions for Merge Intervals.
Memory Usage : 28 MB, less than 8.80 % of C++ online submissions for Merge Intervals.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

#define START_POINT 1
#define END_POINT 2

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> answer;
	vector<vector<int>> numbers;
	for (auto interval : intervals) {
		numbers.push_back({ interval[0],START_POINT });
		numbers.push_back({ interval[1],END_POINT });
	}
	sort(numbers.begin(), numbers.end());

	stack<int> stacks;
	for (auto number : numbers) {
		if (number[1] == START_POINT) {
			stacks.push(number[0]);
		}
		else {
			int a = stacks.top();
			stacks.pop();
			if (stacks.empty()) {
				answer.push_back({ a, number[0] });
			}
		}
	}
	return answer;
}

int main(void) {
	vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>> interval2 = { {1,4},{4,5} };

	vector<vector<int>> answer;
	answer = merge(intervals);
	for (int i = 0; i < answer.size(); i++) {
		cout << "[" << answer[i][0] << " , " << answer[i][1] << "] ";
	}
	cout << endl;
	answer = merge(interval2);
	for (int i = 0; i < answer.size(); i++) {
		cout << "[" << answer[i][0] << " , " << answer[i][1] << "] ";
	}

	return 0;
}