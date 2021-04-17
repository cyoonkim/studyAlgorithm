/*
2021-04-17
Runtime: 204 ms, faster than 94.97% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 129.9 MB, less than 70.40% of C++ online submissions for Sliding Window Maximum.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int numdata[201][100];
int row_count[201];

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	for (int i = 0; i < 201; i++) {
		memset(numdata[i], 0, sizeof(int) * 100);
		row_count[i] = 0;
	}

	vector<int> r;
	int nums_size = nums.size();
	int max = nums[0];
	int plus_num = nums[0] + 10000;

	numdata[plus_num / 100][plus_num % 100] = 1;
	row_count[plus_num / 100]++;

	for (register int i = 1; i < k; i++) {
		plus_num = nums[i] + 10000;
		numdata[plus_num / 100][plus_num % 100]++;
		row_count[plus_num / 100]++;

		if (max <= nums[i]) {
			max = nums[i];
		}
	}
	
	r.push_back(max);

	int del_data_plus;
	
	for (register int i = k; i < nums_size; i++) {
		del_data_plus = nums[i - k] + 10000;
		plus_num = nums[i] + 10000;

		numdata[plus_num / 100][plus_num % 100]++;
		row_count[plus_num / 100]++;

		numdata[del_data_plus / 100][del_data_plus % 100]--;
		row_count[del_data_plus / 100]--;
		
		if (max < nums[i]) {
			max = nums[i];
			r.push_back(max);
			continue;
		}

		if (nums[i - k] == max) {
			int j_row = del_data_plus / 100;
			int j_col;
			while (row_count[j_row] == 0) {
				j_row--;
			}
			for (j_col = 99; j_col >= 0; j_col--) {
				if (numdata[j_row][j_col] > 0) {
					max = j_row * 100 + j_col - 10000;
					break;
				}
			}
		}
		r.push_back(max);
	}
	return r;
}

int main(void) {
	vector<int> v = { 1,3,1,-3,5,3,6,7 };
	int k = 3;

	vector<int> return_value = maxSlidingWindow(v, k);
	
	for (int i = 0; i < return_value.size(); i++)
		cout << return_value[i] << " ";
	return 0;
}