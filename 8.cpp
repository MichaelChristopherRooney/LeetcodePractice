#include <string>

constexpr int maxBeforeMul = std::numeric_limits<int>::max() / 10;
constexpr int minBeforeMul = std::numeric_limits<int>::min() / 10;

class Solution {
public:
	int myAtoi(const std::string &s) {
		int result = 0;
		int sign = 1;
		int readIndex = 0;
		// Skip over whitespace.
		while(readIndex < s.length() && s[readIndex] == ' ') {
			readIndex++;
		}
		// If it was all whitespace then just exit.
		if(readIndex == s.length()) {
			return result;
		}
		// Read sign if set
		if(s[readIndex] == '-') {
			sign = -1;
			readIndex++;
		} else if(s[readIndex] == '+') {
			readIndex++;
		}
		bool pastLeadingZeros = false;
		// Read until end or non-digit character.
		for(; readIndex < s.length(); readIndex++) {
			const auto c = s[readIndex];
			if(c < '0' || c > '9') {
				break;
			}
			if(!pastLeadingZeros && c == '0') {
				continue;
			}
			if(!pastLeadingZeros) {
				pastLeadingZeros = true;
			}
			if(sign == 1 && result > maxBeforeMul) {
				return std::numeric_limits<int>::max();
			}
			if(sign == -1 && result < minBeforeMul) {
				return std::numeric_limits<int>::min();
			}
			result *= 10;
			const int v = c - '0';
			if(sign == 1 && std::numeric_limits<int>::max() - v < result) {
				return std::numeric_limits<int>::max();
			}
			if(sign == -1 && std::numeric_limits<int>::min() + v > result) {
				return std::numeric_limits<int>::min();
			}
			if(sign == 1) {
				result += v;
			} else {
				result -= v;
			}
			if(result == -214748364) {
				int a = 0;
			}
		}
		return result;
	}
};
