/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
Memory Usage: 7 MB, less than 76.20% of C++ online submissions for Wiggle Subsequence.
*/

#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
	int max_len = 1;
	int befor_flag = 0;
	int nums_size = nums.size();
	
	for (int i = 0; i < nums_size-1; i++) {
		int temp_flag = (nums[i] == nums[i+1] ? befor_flag : (nums[i] > nums[i + 1]) ? -1 : 1);
		if (temp_flag != befor_flag) {
			befor_flag = temp_flag;
			max_len++;
		}
	}

	return max_len;
}

int main(void) {
	vector<int> n = { 1,17,5,10,13,15,10,5,16,8 };
	vector<int> n2 = { 1,2,3,4,5,6,7,8,9 };

	cout << "expect : 7 actual : " << wiggleMaxLength(n) << endl;
	cout << "expect : 2 actual : " << wiggleMaxLength(n2) << endl;

	return 0;
}