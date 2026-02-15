#include <vector>

class Solution {
public:
	int numSubarrayProductLessThanK(const std::vector<int>& nums, const int k) {
		int left = 0;
		int right = 0;
		int count = 0;
		int product = 1;
		while(right < nums.size()) {
			product *= nums[right];
			while(product >= k && left <= right) {
				product /= nums[left];
				left++;
			}
			count += (right - left) + 1;
			right++;
		}
		return count;
	}
};

int main() {
	std::vector<int> nums{10,5,2,6};
	int k = 100;
	Solution s;
	int result = s.numSubarrayProductLessThanK(nums, k);
	return 0;
}