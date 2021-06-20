/*
Runtime: 56 ms, faster than 86.25% of C++ online submissions for Coin Change.
Memory Usage: 14.6 MB, less than 23.98% of C++ online submissions for Coin Change.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end());
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	int coins_size = coins.size();
	for (int i = 0; i <= amount; i++) {
		int now_min = INT_MAX;
		for (int j = 0; j < coins_size; j++) {
			if (coins[j] > i)
				break;
			now_min = min(now_min, dp[i - coins[j]]);
		}
		if (now_min != INT_MAX)
			dp[i] = 1 + now_min;
	}
	if (dp[amount] == INT_MAX) return -1;
	return dp[amount];

}

int main(void) {
	vector<int> v = { 1,2,5 };
	int a = coinChange(v, 11);
	cout << a << endl;
	return 0;
}