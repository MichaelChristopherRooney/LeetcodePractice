#include <string>
#include <vector>

class Solution {
public:
	std::vector<int> findAnagrams(const std::string &s, const std::string &p) {
		std::vector<int> result;
		if(p.length() > s.length()) {
			return result;
		}
		// The spec says the characters are lowercase English letters.
		std::array<int, 26> required{0};
		std::array<int, 26> current{0};
		for(const auto c : p) {
			required[c - 'a']++;
		}
		int left = 0;
		int right = 0;
		while(right < s.length()) {
			// Move right until we reach the required length.
			while(right - left < p.length()) {
				const auto c = s[right];
				current[c - 'a']++;
				right++;
			}
			bool match = true;
			for(const auto c : p) {
				if(required[c - 'a'] != current[c - 'a']) {
					match = false;
					break;
				}
			}
			if(match) {
				result.emplace_back(left);
			}
			// Pop the leftmost element.
			const auto c = s[left];
			current[c - 'a']--;
			left++;
		}

		return result;

	}
};

int main() {
	Solution s;
	const auto result = s.findAnagrams("cbaebabacd", "abc");
	return 0;
}