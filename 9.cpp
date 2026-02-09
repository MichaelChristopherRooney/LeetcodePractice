#include <cmath>

class Solution {
public:
	bool isPalindrome(const int x) {
		if(x < 0) {
			return false;
		}
		if(x < 10) {
			return true;
		}
		int numDigits = 0;
		// We need to check if the first digit is a zero. If it is, then it
		// can't be a palindrome.
		int temp = x / 10;
		if (x == temp * 10) {
			return false;
		}
		// Count number of digits.
		auto copyForCount = x;
		while(true) {
			auto div10 = copyForCount / 10;
			numDigits++;
			if(div10 == 0) {
				break;
			}
			copyForCount = div10;
		}
		// At this point there's at least two digits, and there is no trailing zero.
		//int valForTrailing = x;
		//int lastValForLeading = 0;
		for(int i = 0; i < numDigits / 2; i++) {
			// Get trailing digit. Say i = 1 and x = 1234. We want to get 3 here.
			// Factor 1 is 10 ^ i, which is 10, and factor 2 is 10 ^ i + 1, which
			// is 100. We do the following:
			// 1234 / 100 = 123 (factor 2)
			// 123 * 100 = 1230 (factor 2)
			// 1234 - 1230 = 34
			// 34 / 10 = 3 (factor 1)
			const int trailFactor1 = static_cast<int>(std::pow(10, i));
			const int trailFactor2 = trailFactor1 * 10;
			const int trailTemp1 = x / trailFactor2;
			const int trailTemp2 = trailTemp1 * trailFactor2;
			const int trailTemp3 = x - trailTemp2;
			const int trail = trailTemp3 / trailFactor1;

			// Get leading digit. Say i = 1 and x = 1234. We want to get 2 here.
			// Factor 1 is 10 ^ numDigits - i - 1, which is 100, and factor 2 is
			// 1- ^ numDigits - i, which is 1000. We do the following:
			// 1234 / 100 = 12
			// 1234 / 1000 = 1
			// 1 * 10 = 10
			// 12 - 10 = 2
			const int leadFactor = static_cast<int>(std::pow(10, numDigits - i - 1));
			const auto leadTemp1 = x / leadFactor; // Gives 12 as per the above example
			// Don't directly compute the second factor, as it may overflow.
			// Instead use the first factor, and then divide by 10 again.
			const auto leadTemp2 = (x / leadFactor) / 10; // Gives 1 as per the above example
			const auto leadTemp3 = leadTemp2 * 10; // Gives 10 as per the above example
			const auto lead = leadTemp1 - leadTemp3; // Gives 2 as per the above example

			if(lead != trail) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	const auto result = s.isPalindrome(2222222);
	return 0;
}