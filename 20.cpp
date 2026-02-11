#include <string>
#include <vector>

class Solution {
public:
	bool isValid(const std::string &s) {
		std::vector<char> lookingFor;
		for(const char c : s) {
			if(c == '(') {
				lookingFor.emplace_back(')');
				continue;
			}
			if(c == '[') {
				lookingFor.emplace_back(']');
				continue;
			}
			if(c == '{') {
				lookingFor.emplace_back('}');
				continue;
			}
			if(lookingFor.empty() || lookingFor.back() != c) {
				return false;
			}
			lookingFor.pop_back();
		}
		return lookingFor.empty();
	}
};

int main() {
	Solution s;
	const auto result = s.isValid("[");
	return 0;
}