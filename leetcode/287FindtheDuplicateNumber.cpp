#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
	vector<bool>check(nums.size());
	for (auto i : nums) {
		if (check[i])
			return i;
		check[i] = true;
	}
	return -1; // error
}

int main(void) {
	vector<int> nums = { 3,1,3,4,2 };

	cout << findDuplicate(nums);
	return 0;
}