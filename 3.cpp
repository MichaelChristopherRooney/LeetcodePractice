#include <array>
#include <string>

class Solution {
public:
	int lengthOfLongestSubstring(const std::string &s) {
		int longest = 0;
		std::array<bool, 256> alreadySeen{false};
		int left = 0;
		int right = 0;
		while(right < s.length()) {
			while(right < s.length() && !alreadySeen[s[right]]) {
				alreadySeen[s[right]] = true;
				right++;
			}
			int len = right - left;
			if(len > longest) {
				longest = len;
			}
			alreadySeen[s[left]] = false;
			left++;
		}
		return longest;
	}
};

int main() {
	Solution s;
	const auto result = s.lengthOfLongestSubstring("abcabcbb");
	return 0;
}