#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
	int now_idx = nums.size() - 1;
	
	for (int i = now_idx - 1; i >= 0; i--) {
		if (i + nums[i] >= now_idx) {
			now_idx = i;
		}
	}

	if (now_idx == 0)
		return true;
	else 
		return false;
}

int main(void) {
	vector<int> matrix({3,2,1,0,4});
	canJump(matrix);
	return 0;
}