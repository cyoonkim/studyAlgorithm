#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

bool comp(int a, int b) {
	return a > b;
}

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
	
	vector<pair<int, int>> nums2_copy;
	int size = nums2.size();
	vector<int> result(size);

	for(int i = 0; i<size; i++) {
		nums2_copy.push_back(pair<int, int>(i, nums2[i]));
	}

	sort(nums2_copy.begin(), nums2_copy.end(), cmp);
	sort(nums1.begin(), nums1.end(), comp);

#if DEBUG
	for (auto num : nums2_copy) {
		cout << "key: " << num.first << " | value: " << num.second << "\n";
	}
#endif

	int nums1_idx = 0;
	int nums1_last_idx = size - 1;

	for(int nums2_idx = 0; nums2_idx < size; nums2_idx++) {
		if (nums2_copy[nums2_idx].second < nums1[nums1_idx]) {
			result[nums2_copy[nums2_idx].first] = nums1[nums1_idx];
			nums1_idx++;
		}
		else {
			result[nums2_copy[nums2_idx].first] = nums1[nums1_last_idx];
			nums1_last_idx--;
		}
	}

	return result;
}

int main(void) {
	vector<int> num1 = { 2, 7, 11, 15 };
	vector<int> num2 = { 1, 10, 4, 11 };

	vector<int> result = advantageCount(num1, num2);

	//[2,11,7,15]
	for (auto a : result) {
		cout << a << " ";
	}
	cout << endl;

	return 0;
}