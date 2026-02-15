#include <string>
#include <vector>

class Solution {
public:
	std::vector<int> findAnagrams(const std::string &s, const std::string &p) {
		std::vector<int> result;
		int sLen = s.length();
		if(p.length() > sLen) {
			return result;
		}
		// The spec says the characters are lowercase English letters.
		std::array<int, 26> required{0};
		std::array<int, 26> current{0};
		for(const auto c : p) {
			required[c - 'a']++;
		}
		// Create the initial window.
		for(int i = 0; i < p.size(); i++) {
			const auto c = s[i];
			current[c - 'a']++;
		}
		int matches = 0;
		for(int i = 0; i < 26; i++) {
			if(required[i] == current[i]) {
				matches++;
			}
		}
		if(matches == 26) {
			result.emplace_back(0);
		}
		for(int i = p.size(); i < s.length(); i++) {
			const char left = s[i - p.size()] - 'a';
			const char right = s[i] - 'a';
			if(required[right] == current[right]) {
				matches--;
			}
			current[right]++;
			if(required[right] == current[right]) {
				matches++;
			}
			if(required[left] == current[left]) {
				matches--;
			}
			current[left]--;
			if(required[left] == current[left]) {
				matches++;
			}
			if(matches == 26) {
				result.push_back(i - p.size() + 1);
			}


		}
		return result;

	}
};

int main() {
	Solution s;
	const auto result = s.findAnagrams("cbaebabacd", "abc");
	return 0;
}