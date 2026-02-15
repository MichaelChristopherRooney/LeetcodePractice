#include <string>

class Solution {
public:
	int countGoodSubstrings(const std::string &s) {
		int count = 0;
		if(s.length() < 3) {
			return 0;
		}
		for(int i = 0; i < s.length() - 2; i++) {
			const auto c1 = s[i];
			const auto c2 = s[i + 1];
			const auto c3 = s[i + 2];
			if(c1 != c2 && c1 != c3 && c2 != c3) {
				count++;
			}
		}
		return count;
	}
};

int main() {
	Solution s;
	const auto result = s.countGoodSubstrings("aababcabc");
	return 0;
}