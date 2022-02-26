/*
Runtime: 102 ms, faster than 76.57% of C++ online submissions for Distant Barcodes.
Memory Usage: 41.5 MB, less than 82.29% of C++ online submissions for Distant Barcodes.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> map1;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
	for (int i = 0; i < barcodes.size(); i++) {
		auto item = map1.find(barcodes[i]);
		if (item == map1.end()) {
			map1.insert(pair<int, int>(barcodes[i], 1));
		}
		else {
			item->second++;
		}
		
	}
	vector<pair<int, int>> vec(map1.begin(), map1.end());
	sort(vec.begin(), vec.end(), cmp);

	int i = 0;
	for (auto num : vec) {
		if (i >= barcodes.size())
			i = 1;
		for (int j = 0; j < num.second; j++) {
			barcodes[i] = num.first;
			i = i + 2 >= barcodes.size() ? 1 : i + 2;
		}
	}
	return barcodes;
}

bool checkAnswer(vector<int> &answer) {
	int before_num = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (before_num == answer[i])
			return false;
		before_num = answer[i];
	}
	return true;
}

int main(void) {

	vector<int> barcodes = { 1,1,1,1,2,2,3,3 };
	vector<int> barcodes2 = { 1,1,1,2,2,2 };

	vector<int> answer = rearrangeBarcodes(barcodes);
	cout << checkAnswer(answer) << endl;


	return 0;
}