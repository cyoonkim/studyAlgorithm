/*
Runtime: 16 ms, faster than 92.23% of C++ online submissions for Candy.
Memory Usage: 18.2 MB, less than 30.47% of C++ online submissions for Candy.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
	int n = ratings.size();
	int result = 0;
	vector<int> left_rating(n);
	vector<int> right_rating(n);

	for (int i = 1; i < n; i++) {
		if (ratings[i] > ratings[i - 1])
			left_rating[i] = left_rating[i - 1] + 1;
		if (ratings[n - 1 - i] > ratings[n - i])
			right_rating[n - 1 - i] = right_rating[n - i] + 1;
	}

	for (int i = 0; i < n; i++) {
		result += max(left_rating[i], right_rating[i]);
	}

	return result + n;
}

int main(void) {
	vector<int> rating = { 1,2,3 };
	cout << candy(rating);

	return 0;
}