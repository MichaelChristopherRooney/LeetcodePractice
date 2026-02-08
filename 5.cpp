#include <string>

class Solution {
public:
	// Initial slow version for testing and reference.
	std::string longestPalindrome(const std::string &s) {
		std::string best = std::string{s[0]};
		for(int i = 0; i < s.length(); i++) {
			const auto cStart = s[i];
			// Find all matching characters starting from the end of the string.
			for(int j = s.length() - 1; j != i; j--) {
				if(s[j] != cStart) {
					continue;
				}
				// TODO: if length is already less than the best match we can skip it.
				const auto view = std::string_view(s.data() + i, j - i + 1);
				if(!isPalindrome(view)) {
					continue;
				}
				if(view.length() > best.length()) {
					best = view;
					break;
				}
			}

		}
		return best;
	}

private:
	bool isPalindrome(const std::string_view &s) {
		for(int i = 0; i < s.length() / 2; i++) {
			if(s[i] != s[s.length() - 1 - i]) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	const auto result = s.longestPalindrome("babad");
	return 0;
}