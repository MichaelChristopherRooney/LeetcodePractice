#include <string>

class Solution {
public:
	std::string getRle(const std::string &s) {
		int i = 0;
		std::string rleBuffer;
		rleBuffer.reserve(30)
		while(i < s.length()) {
			const auto c = s[i];
			int count = 1;
			i++;
			while(s[i] == c && i < s.length()) {
				i++;
				count++;
			}
			rleBuffer += std::to_string(count) + c;

		}
		return rleBuffer;
	}
	std::string countAndSay(int n) {
		std::string s = "1";
		for(int i = 1; i < n; i++) {
			s = getRle(s);
		}
		return s;
	}
};

int main() {
	Solution s;
	const auto result = s.countAndSay(4);
	return 0;
}