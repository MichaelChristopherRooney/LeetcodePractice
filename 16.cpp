#include <vector>

class Solution {
public:
	int threeSumClosest(std::vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		int lowestDiff = std::numeric_limits<int>::max();
		int bestSum = 0;
		int n = nums.size();
		for(int i = 0; i < n - 2; i++) {
			// Skip over duplicates.
			if(i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int j = i + 1;
			int k = n - 1;
			while(j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if(sum == target) {
					// Problem states there is exactly one solution, so if we
					// get an exact match then we are done.
					return sum;
				}
				int diff = std::abs(sum - target);
				if(diff < lowestDiff) {
					bestSum = sum;
					lowestDiff = diff;
				}
				if(sum > target) {
					k--;
				} else {
					j++;
				}
			}
		}
		return bestSum;

	}
};

int main() {
	Solution s;
	std::vector<int> nums{0,3,97,102,200};
	const auto result = s.threeSumClosest(nums, 300);
	return 0;
}