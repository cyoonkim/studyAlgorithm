/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
Memory Usage: 7.2 MB, less than 28.97% of C++ online submissions for Rotate Image.
*/

#include <iostream>
#include <vector>
using namespace std;

void printM(vector<vector<int>>& matrix) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout<<matrix[i][j];
		}
		cout << endl;
	}
}

void rotate(vector<vector<int>>& matrix) {
	int len = matrix.size() - 1;
	int dup = (matrix.size() + 1) / 2;
	
	cout << len << " " << dup << endl;

	for (int i = 0; i < dup; i++) {
		for (int j = 0; j < len - 2*i; j++) {
			int rem = matrix[i][i+j];
			matrix[i][i + j] = matrix[len - i - j][i];
			matrix[len - i - j][i] = matrix[len - i][len - i - j];
			matrix[len - i][len - i - j] = matrix[i + j][len - i];
			matrix[i + j][len - i] = rem;
		}
	}
}

int main(void) {
	vector<vector<int>> M({
		vector<int>({1,2,3}),
		vector<int>({4,5,6}),
		vector<int>({7,8,9})
	});

	rotate(M);
	return 0;
}