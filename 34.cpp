#include <vector>

class Solution {
public:
	std::vector<int> searchRange(std::vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int lowerBound = -1;
		// Get lower bound.
		while(left <= right) {
			int mid = (right - left) / 2 + left;
			if(nums[mid] < target) {
				left = mid + 1;
			} else if(nums[mid] > target) {
				right = mid - 1;
			} else {
				// nums[mid] is the target, but it may not be the first instance.
				// We now need to keep going until we find the first instance.
				if(left == mid || nums[mid - 1] < nums[mid]) {
					lowerBound = mid;
					break;
				}
				right = mid - 1;
			}
		}
		if(lowerBound == -1) {
			return std::vector<int>{-1, -1};
		}
		// Get upper bound.
		left = lowerBound;
		right = nums.size() - 1;
		int upperBound = -1;
		while(left <= right) {
			int mid = (right - left) / 2 + left;
			if(nums[mid] < target) {
				left = mid + 1;
			} else if(nums[mid] > target) {
				right = mid - 1;
			} else {
				// nums[mid] is the target, but it may not be the last instance.
				// We now need to keep going until we find the last instance.
				if(right == mid || nums[mid] < nums[mid + 1]) {
					upperBound = mid;
					break;
				}
				left = mid + 1;
			}
		}
		if(upperBound == -1) {
			return std::vector<int>{-1, -1};
		}
		return std::vector<int>{lowerBound, upperBound};
	}
};

int main() {
	std::vector<int> nums{1,2,3,3,3,3,4,5,9};
	Solution s;
	s.searchRange(nums, 3);
	return 0;
}