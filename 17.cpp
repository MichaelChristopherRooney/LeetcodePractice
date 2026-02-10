#include <string>
#include <vector>

class Solution {
public:
	const std::string values[8] = {
		"abc", // 2,
		"def", // 3
		"ghi", // 4
		"jkl", // 5
		"mno", // 6
		"pqrs", // 7,
		"tuv", // 8
		"wxyz" // 9
	};

	std::vector<std::string> letterCombinationsRecursive(const std::string &digits, int digitIndex) {
		std::vector<std::string> result;
		const auto d = digits[digitIndex];
		// Doing it this way also allows us to index into the array above correctly.
		const auto i = d - '2';
		const auto &letters = values[i];
		if(digitIndex == digits.size() - 1) {
			// Terminating condition.
			for(const auto letter : letters) {
				result.emplace_back(std::string{letter});
			}
			return result;
		}
		const auto innerResults = letterCombinationsRecursive(digits, digitIndex + 1);
		for(const auto letter : letters) {
			for(const auto &innerResult : innerResults) {
				result.emplace_back(std::string{letter} + innerResult);
			}
		}
		return result;
	}
	std::vector<std::string> letterCombinations(const std::string &digits) {
		return letterCombinationsRecursive(digits, 0);
	}
};

int main() {
	Solution s;
	s.letterCombinations("23");
	return 0;
}