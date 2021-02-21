#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	int first_buy = 100000;
	int first_profit = 0;
	int second_buy = -100000;
	int second_profit = 0;

	int size = prices.size();

	for (int i = 0; i < size; i++) {
		first_buy = min(first_buy, prices[i]);
		first_profit = max(first_profit, prices[i] - first_buy);
		second_buy = max(second_buy, first_profit - prices[i]);
		second_profit = max(second_profit, second_buy + prices[i]);
	}

	return second_profit;
}

int main(void) {
	vector<int> v = { 3, 3, 5, 0, 0, 3, 1, 4 };
	if (maxProfit(v) == 6)
		cout << "성공";
	return 0;
}