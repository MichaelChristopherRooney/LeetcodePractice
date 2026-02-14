#include <vector>

class Solution {
public:
	int maximalSquare(const std::vector<std::vector<char>>& matrix) {
		int xSize = matrix.size();
		int ySize = matrix[0].size();
		// Initialise DP matrix.
		std::vector<std::vector<int>> dp;
		dp.reserve(xSize);
		for(int i = 0; i < xSize; i++) {
			dp.emplace_back(ySize, 0);
		}
		int bestSize = 0;
		for(int i = 0; i < xSize; i++) {
			for(int j = 0; j < ySize; j++) {
				if(matrix[i][j] == '0') {
					continue;
				}
				int leftMin = 0;
				int diagonalMin = 0;
				int topMin = 0;
				if(i > 0) {
					leftMin = dp[i - 1][j];
				}
				if(j > 0) {
					topMin = dp[i][j - 1];
				}
				if(i > 0 && j > 0) {
					diagonalMin = dp[i - 1][j - 1];
				}
				const auto dpMin = std::min(std::min(leftMin, topMin), diagonalMin);
				const int size = dpMin + 1;
				dp[i][j] = size;
				if(size > bestSize) {
					bestSize = size;
				}
			}
		}
		return bestSize * bestSize;
	}
};

int main() {
	std::vector<std::vector<char>> matrix{std::vector<char>{'1','0','1','0','0'},std::vector<char>{'1','0','1','1','1'},std::vector<char>{'1','1','1','1','1'},std::vector<char>{'1','0','0','1','0'}};
	//std::vector<std::vector<char>> matrix{std::vector<char>{'0'}};
	//std::vector<std::vector<char>> matrix{std::vector<char>{'0','1'},std::vector<char>{'1','0'}};
	Solution s;
	int result = s.maximalSquare(matrix);
	return 0;
}