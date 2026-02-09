#include <vector>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int i = 0;
		int j = height.size() - 1;
		int best = 0;
		while(i != j) {
			int hi = height[i];
			int hj = height[j];
			int dist = j - i;
			const auto h = std::min(hi, hj);
			const auto size = dist * h;
			if(size > best) {
				best = size;
			}
			if(hi < hj) {
				i++;
			} else {
				j--;
			}
		}
		return best;
	}
};

int main() {
	std::vector<int> heights{1,8,6,2,5,4,8,3,7};
	Solution s;
	const auto result = s.maxArea(heights);
	return 0;
}