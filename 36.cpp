#include <vector>

class Solution {
public:
	bool isValidSudoku(const std::vector<std::vector<char>>& board) {
		// Only need chars '1' to '9'.
		bool seenInColumn[9][9]{false};
		bool seenInRow[9][9]{false};
		bool seenInSubboard[3][3][9]{false};
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				const auto originalC = board[i][j];
				if(originalC == '.') {
					continue;
				}
				if(originalC == '5') {
					int a = 0;
				}
				const auto c = originalC - '1';
				int subI = i / 3;
				int subJ = j / 3;
				const auto seenBefore = seenInColumn[j][c] || seenInRow[i][c] || seenInSubboard[subI][subJ][c];
				if(seenBefore) {
					return false;
				}
				seenInColumn[j][c] = true;
				seenInRow[i][c] = true;
				seenInSubboard[subI][subJ][c] = true;
			}
		}
		return true;
	}
};

int main() {
	/*const std::vector<std::vector<char>> data {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};*/
	const std::vector<std::vector<char>> data {
		{'.','.','4','.','.','.','6','3','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'5','.','.','.','.','.','.','9','.'},
		{'.','.','.','5','6','.','.','.','.'},
		{'4','.','3','.','.','.','.','.','1'},
		{'.','.','.','7','.','.','.','.','.'},
		{'.','.','.','5','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'}
	};
	
	Solution s;
	const auto result = s.isValidSudoku(data);
	return 0;
}