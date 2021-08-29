/*
Runtime: 540 ms, faster than 23.10% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 31.6 MB, less than 32.35% of C++ online submissions for Longest Consecutive Sequence.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	if (nums.size() < 2) {
		return nums.size();
	}
	int returnValue = 0;

	unordered_map<int, bool> m;
	for (int i = 0; i < nums.size(); i++) {
		m.insert(make_pair(nums[i], true));
	}

	for (int i = 0; i < nums.size(); i++) {
		//제일 작은 수 아니면 pass
		if (!m.count(nums[i] - 1)) {
			int len = 1;
			int now_num = nums[i] + 1;
			while (m.count(now_num)) {
				now_num++;
				len++;
			}
			returnValue = max(len, returnValue);
		}
	}

	return returnValue;
}

int main(void) {
	vector<int> n = { 100,4,200,1,3,2 };
	cout << longestConsecutive(n);

	return 0;
}