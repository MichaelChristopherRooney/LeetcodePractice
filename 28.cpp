#include <string>

class Solution {
public:
	int strStr(std::string haystack, std::string needle) {
		if(needle.length() > haystack.length()) {
			return -1;
		}
		for(int i = 0; i < haystack.length() - needle.length() + 1; i++) {
			bool match = true;
			for(int j = 0; j < needle.length(); j++) {
				if(haystack[i + j] != needle[j]) {
					match = false;
					break;
				}
			}
			if(match) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution s;
	const auto r = s.strStr("sabutsad", "sad");
	return 0;

}