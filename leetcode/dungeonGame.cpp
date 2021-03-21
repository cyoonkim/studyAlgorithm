#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int row_count = dungeon.size();
	int col_count = dungeon[0].size();

	for (int j = col_count - 2 ; j > -1; j--) {
		if (dungeon[row_count - 1][j + 1] > 0)
			continue;
		dungeon[row_count - 1][j] += dungeon[row_count - 1][j + 1];
	}

	for (int i = row_count - 2; i > -1; i--) {
		if (dungeon[i + 1][col_count - 1] > 0)
			continue;
		dungeon[i][col_count - 1] += dungeon[i + 1][col_count - 1];
	}

	for (int i = row_count - 2; i > -1; i--) {
		for (int j = col_count - 2; j > -1; j--) {
			if (max(dungeon[i + 1][j], dungeon[i][j + 1]) > 0) {
				continue;
			}
			dungeon[i][j] += max(dungeon[i + 1][j], dungeon[i][j + 1]);
		}
	}
	return max(1,-(dungeon[0][0]-1));
}

int main(void) {
	vector<vector<int>> v = { 
		vector<int>({1,-2,1}),
//		vector<int>({-5,-10,1}),
//		vector<int>({10,30,-5}) 
	};
	cout << calculateMinimumHP(v) << endl;
	return 0;
}
