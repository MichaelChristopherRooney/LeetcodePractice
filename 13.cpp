#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> result;
		for(int i = 0; i < nums.size() - 2; i++) {
			// As we've sorted, we can skip over duplicate values easily, as
			// they'll appear together.
			if(i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int j = i + 1;
			int k = nums.size() - 1;
			while(j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				// If the sum is < 0, we need a bigger number so we increment j.
				// If the sum is > 0, we need a smaller number so we decrement k.
				// < 0 so we increment
				if(sum == 0) {
					result.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
					j++;
					k--;
					// Skip over duplicates indexed by j.
					while(j < k && nums[j] == nums[j - 1]) {
						j++;
					}
				} else if(sum < 0) {
					j++;
				} else {
					k--;
				}
			}

		}

		return result;
	}
};

int main() {
	const std::vector<int> nums{-1,0,1,2,-1,-4};
	Solution s;
	const auto result = s.threeSum(nums);
	return 0;
}