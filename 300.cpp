#include <vector>

class Solution {
public:
	int lengthOfLIS(std::vector<int>& nums) {
		std::vector dp(nums.size(), 1);
		for(int i = 0; i < nums.size(); i++) {
			int bestLenToHere = 1;
			for(int j = 0; j < i; j++) {
				if(nums[j] >= nums[i]) {
					continue;
				}
				bestLenToHere = std::max(bestLenToHere, dp[j] + 1);
			}
			dp[i] = bestLenToHere;
		}
		int bestLen = 1;
		for(const auto v : dp) {
			bestLen = std::max(bestLen, v);
		}
		return bestLen;
	}
};

int main() {
	std::vector<int> nums{10,9,2,5,3,7,101,18};
	Solution s;
	const auto result = s.lengthOfLIS(nums);
	return 0;
}
