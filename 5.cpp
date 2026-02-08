#include <string>
#include <unordered_map>

class Solution {
public:
	std::string longestPalindrome(const std::string &s) {
		// Single letter strings are also palindromes, so let's just use the first
		// letter as a default result.
		std::string best = std::string{s[0]};
		for(int i = 0; i < s.length() - 1; i++) {
			// For each character, treat it as the center of a palindrome and
			// expand from there while it is still a palindrome. The palinedrome
			// may have an odd or even number of characters. For the odd case,
			// we need to start centered on the same character, while for the
			// even case we need to start centered on two adjacent characters.
			const auto oddMatch = expandFromCenter(s, i, i);
			if(oddMatch.length() > best.length()) {
				best = oddMatch;
			}
			const auto evenMatch = expandFromCenter(s, i, i + 1);
			if(evenMatch.length() > best.length()) {
				best = evenMatch;
			}
		}
		return best;
	}

private:
	std::string expandFromCenter(const std::string &s, int start, int end) {
		while(start >= 0 && end < s.length() && s[start] == s[end]) {
			start--;
			end++;
		}
		return s.substr(start + 1, end - start - 1);
	}
};
