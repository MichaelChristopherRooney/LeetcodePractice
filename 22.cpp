#include <vector>
#include <string>

class Solution {
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> result;
		std::vector<char> cur;
		generateRecursive('(', n - 1, 1, result, cur);
		return result;
	}

	void generateRecursive(char c, int n, int open, std::vector<std::string> &result, std::vector<char> &cur) {
		cur.emplace_back(c);
		if(n == 0 && open == 0) {
			std::string val(cur.data(), cur.data() + cur.size());
			result.emplace_back(val);
			cur.pop_back();
		}
		if(open > 0) {
			generateRecursive(')', n, open - 1, result, cur);
		}
		if(n > 0) {
			generateRecursive('(', n - 1, open + 1, result, cur);
		}
		cur.pop_back();
	}
};

int main() {
	Solution s;
	const auto res = s.generateParenthesis(3);
	return 0;
}