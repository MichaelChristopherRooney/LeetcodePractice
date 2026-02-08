#include <limits>

class Solution {
public:
	int reverse(int x) {
		constexpr int maxBeforeMul = std::numeric_limits<int>::max() / 10;
		constexpr int minBeforeMul = std::numeric_limits<int>::min() / 10;
		const auto copy = x;
		int result = 0;

		while(true) {
			const auto div10 = x / 10;
			const auto mul10 = div10 * 10;
			const auto digit = x - mul10;
			// TODO: overflow check.
			if(copy >= 0 && result > maxBeforeMul ) {
				return 0;
			}
			if(copy < 0 && result < minBeforeMul) {
				return 0;
			}
			result *= 10;
			if(copy >= 0 && result > std::numeric_limits<int>::max() - digit) {
				return 0;
			}
			if(copy < 0 && result < std::numeric_limits<int>::min() - digit) {
				return 0;
			}
			result += digit;
			x = div10;
			if(x == 0) {
				break;
			}
		}
		return result;

	}
};
