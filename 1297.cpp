#include <array>
#include <string>
#include <unordered_map>

class Solution {
public:
	int maxFreq(const std::string &s, const int maxLetters, const int minSize, const int maxSize) {
		std::unordered_map<std::string, int> occurrences;
		std::array<char, 26> charCounts{0};
		int uniqueCharCount = 0;
		for(int i = 0; i < minSize; i++) {
			// Track the character which was just added.
			if(++charCounts[s[i] - 'a'] == 1) {
				// We're adding a new unique character.
				uniqueCharCount++;
			}
		}
		int best = 0;
		for(int i = 0; i < s.length() - minSize + 1; i++) {
			if(uniqueCharCount <= maxLetters) {
				std::string substring{s.begin() + i, s.begin() + i + minSize};
				if(!occurrences.contains(substring)) {
					occurrences[substring] = 0;
				}
				int count = ++occurrences[substring];
				if(count > best) {
					best = count;
				}
			}
			// Remove the character we're about to slide past.
			if(--charCounts[s.at(i) - 'a'] == 0) {
				// We removed a unique character.
				uniqueCharCount--;
			}
			if(i < s.length() - minSize) {
				// Track the character which is about to be added.
				if(++charCounts[s.at(i + minSize) - 'a'] == 1) {
					// We're adding a new unique character.
					uniqueCharCount++;
				}
			}
		}
		return best;
	}
};

int main() {
	Solution s;
	s.maxFreq("abcde", 2, 3, 3);
}