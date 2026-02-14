#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

class Solution {
public:
	int maximalSquare(std::vector<std::vector<char>>& matrix) {
		int xSize = matrix.size();
		int ySize = matrix[0].size();
		int bestSize = 0;
		maximalSquareRecursive(matrix, 0, 0, xSize, ySize, bestSize);
		int a = 0;
		return bestSize * bestSize;
	}

private:
	bool isValidMatrix(std::vector<std::vector<char>>& matrix, int xStart, int yStart, int xSize, int ySize) {
		for(int x = xStart; x < xStart + xSize; x++) {
			for(int y = yStart; y < yStart + ySize; y++) {
				if(matrix.at(x).at(y) == '0') {
					return false;
				}
			}
		}
		return true;

	}
	void maximalSquareRecursive(
			std::vector<std::vector<char>>& matrix,
			int xStart,
			int yStart,
			int xSize,
			int ySize,
			int &bestSize) {
		std::string key = std::to_string(xStart) + "_" + std::to_string(yStart) + "_" + std::to_string(xSize) + "_" + std::to_string(ySize);
		if(alreadyVisited.contains(key)) {
			return;
		}
		alreadyVisited.emplace(key);
		if(xStart == 2 && yStart == 1 && xSize == 2 && ySize == 2) {
			int a = 0;
		}
		if(xSize == ySize) {
			if(isValidMatrix(matrix, xStart, yStart, xSize, ySize)) {
				if(xSize > bestSize) {
					bestSize = xSize;
				}
			}
		}
		// We started with the full matrix, so it should get smaller each iteration.

		// First handle all permutations in the X axis.
		// Can we make X side smaller by shrinking it?
		if(xSize > 1) {
			maximalSquareRecursive(matrix, xStart, yStart, xSize - 1, ySize, bestSize);
		}
		// Do we have room to move the X start right?
		if(xStart + xSize < matrix.size()) {
			maximalSquareRecursive(matrix, xStart + 1, yStart, xSize, ySize, bestSize);
		}

		// Now handle all permutations in the Y axis.
		// Can we shrink up?
		if(ySize > 1) {
			maximalSquareRecursive(matrix, xStart, yStart, xSize, ySize - 1, bestSize);
		}
		// Do we have room to move the Y start down?
		if(yStart + ySize < matrix[0].size()) {
			maximalSquareRecursive(matrix, xStart, yStart + 1, xSize, ySize, bestSize);
		}
	}

	// i-j-iLen-jLen
	std::unordered_set<std::string> alreadyVisited;
	std::unordered_map<std::string, int> subMatrixSizes;
};

int main() {
	std::vector<std::vector<char>> matrix{std::vector<char>{'1','0','1','0','0'},std::vector<char>{'1','0','1','1','1'},std::vector<char>{'1','1','1','1','1'},std::vector<char>{'1','0','0','1','0'}};
	//std::vector<std::vector<char>> matrix{std::vector<char>{'0'}};
	//std::vector<std::vector<char>> matrix{std::vector<char>{'0','1'},std::vector<char>{'1','0'}};
	Solution s;
	int result = s.maximalSquare(matrix);
	return 0;
}