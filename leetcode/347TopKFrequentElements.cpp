/*
Runtime: 32 ms, faster than 8.21% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 13.3 MB, less than 99.49% of C++ online submissions for Top K Frequent Elements.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct couple {
	int num;
	int count = 0;
};

vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int> result;
	vector<couple> couple_result(k+1);
	int nums_size = nums.size();
	sort(nums.begin(), nums.end());
	
	int now_num = nums[0];
	int now_count = 1;
	int result_num = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != now_num) {
			couple c;
			c.num = now_num;
			c.count = now_count;

			for (int j = min(result_num,k - 1); j >= 0; j--) {
				if (couple_result[j].count < c.count) {
					result_num++;
					couple_result[j + 1] = couple_result[j];
					couple_result[j] = c;
				}
				else {
					break;
				}
			}

			now_num = nums[i];
			now_count = 1;
		}
		else {
			now_count++;
		}
	}
	couple c;
	c.num = now_num;
	c.count = now_count;

	for (int j = min(result_num, k - 1); j >= 0; j--) {
		if (couple_result[j].count < c.count) {
			result_num++;
			couple_result[j + 1] = couple_result[j];
			couple_result[j] = c;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < k; i++) {
		result.push_back(couple_result[i].num);
	}

	return result;
}

int main(void) {
	vector<int> nums = { 1,3,2,2,1,1 };

	vector<int> result = topKFrequent(nums, 2);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}