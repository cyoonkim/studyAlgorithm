/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Sudoku.
Memory Usage: 17.9 MB, less than 88.06% of C++ online submissions for Valid Sudoku.
*/

#include <iostream>
#include <vector>

using namespace std;

struct numbers {
	bool num[10] = { false };
};

int charToInt(char a) {
	if (a == '.')
		return -1;
	return (int)(a - '0');
}

bool isValidSudoku(vector<vector<char>>& board) {
	numbers kanban[3][3];
	numbers col[9];
	numbers array;

	for (int i = 0; i < 9; i++) {
		array = { false };
		for (int j = 0; j < 9; j++) {
			int now_num = charToInt(board[i][j]);
			if (now_num > 0) {
				if (!(col[j].num[now_num] || array.num[now_num] || kanban[i / 3][j / 3].num[now_num])) {
					col[j].num[now_num] = true;
					array.num[now_num] = true;
					kanban[i/3][j/3].num[now_num] = true;
				}
				else {
					return false;
				}
			}
		}
	}
	return true;
}

int main(void) {
	vector<vector<char>> board ({
		vector<char>({'8', '3', '.', '.', '7', '.', '.', '.', '.'}),
		vector<char>({'6', '.', '.', '1', '9', '5', '.', '.', '.'}),
		vector<char>({'.', '9', '8', '.', '.', '.', '.', '6', '.' }),
		vector<char>({'8', '.', '.', '.', '6', '.', '.', '.', '3'}),
		vector<char>({'4', '.', '.', '8', '.', '3', '.', '.', '1'}),
		vector<char>({'7', '.', '.', '.', '2', '.', '.', '.', '6'}),
		vector<char>({'.', '6', '.', '.', '.', '.', '2', '8', '.'}),
		vector<char>({'.', '.', '.', '4', '1', '9', '.', '.', '5'}),
		vector<char>({'.', '.', '.', '.', '8', '.', '.', '7', '9'})
		});

	cout << isValidSudoku(board);
	return 0;
}