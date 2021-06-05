
/*
Runtime: 16 ms, faster than 43.37% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.3 MB, less than 44.61% of C++ online submissions for Set Matrix Zeroes.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	int a = (int)matrix.size();
	int b = (int)matrix[0].size();

	vector<int> row_set;
	vector<int> col_set;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (matrix[i][j] == 0) {
				row_set.push_back(i);
				col_set.push_back(j);
			}
		}
	}
	
	sort(col_set.begin(), col_set.end());

	row_set.erase(unique(row_set.begin(), row_set.end()), row_set.end());
	col_set.erase(unique(col_set.begin(), col_set.end()), col_set.end());

	int row_size = (int)row_set.size();
	int col_size = (int)col_set.size();

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < b; j++) {
			matrix[row_set[i]][j] = 0;
		}
	}
	for (int i = 0; i < col_size; i++) {
		for (int j = 0; j < a; j++) {
			matrix[j][col_set[i]] = 0;
		}
	}
}

void printVector(vector<vector<int>>& matrix) {
	int a = (int)matrix.size();
	int b = (int)matrix[0].size();
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	vector<vector<int>> matrix({
		vector<int>({0,1,2,0}),
		vector<int>({3,4,5,2}),
		vector<int>({1,3,1,5}),
	});
	setZeroes(matrix);
	printVector(matrix);
	return 0;
}