#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 51
#define MIN -999

vector<vector<vector<int>>> dp;
int dp_size;

int find_cherry(const vector<vector<int>>& grid, int x1, int y1, int x2) {
	const int y2 = x1 + y1 - x2;
	//끝에 왔으면

	if (x1 == dp_size || y1 == dp_size || x2 == dp_size || y2 == dp_size) {
		return -1;
	}
	if (x1 == dp_size - 1 && y1 == dp_size - 1) {
		return grid[dp_size - 1][dp_size - 1];
	}
	//값이 -1
	if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
		return -1;
	}

	if (dp[x1][y1][x2] > MIN)
		return dp[x1][y1][x2];

	dp[x1][y1][x2] = max({ find_cherry(grid, x1 + 1, y1, x2 + 1),
						find_cherry(grid, x1 + 1, y1, x2),
						find_cherry(grid, x1, y1 + 1, x2 + 1),
						find_cherry(grid, x1, y1 + 1, x2) }
	);
	if (dp[x1][y1][x2] == -1)
		return -1;

	// 만약 둘이 같은 좌표라면
	if (x1 == x2) {
		dp[x1][y1][x2] += grid[x1][y1];
	}
	else {
		dp[x1][y1][x2] += grid[x1][y1] + grid[x2][y2];
	}
	dp[x1][y1][x2] = dp[x1][y1][x2];
	return dp[x1][y1][x2];
}


int cherryPickup(vector<vector<int>>& grid) {
	dp_size = grid.size();

	dp.resize(dp_size + 1, vector<vector<int>>(dp_size + 1, vector<int>(dp_size + 1, MIN)));

	int return_value = find_cherry(grid, 0, 0, 0);

	if (return_value > 0)
		return return_value;
	else
		return 0;
}

int main(void) {
	vector<vector<int>> v = {
		vector<int>({0,1,-1}),
		vector<int>({1,0,-1}),
		vector<int>({1,1,1})
	};

	int return_value = cherryPickup(v);

	cout << return_value;

	return 0;
}