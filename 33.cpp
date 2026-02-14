#include <vector>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while(left <= right) {
			const int mid = ((right - left) / 2) + left;
			if(nums[mid] == target) {
				return mid;
			}
			// At least one half is sorted, and at most one half is unsorted.
			// Find the sorted half, and then check if the value lies inside.
			// If it does, move towards the sorted half. Else move towards the
			// unsorted half.
			bool leftSorted = nums[left] <= nums[mid];
			bool inLeft = false;
			if(leftSorted) {
				inLeft = nums[left] <= target && target <= nums[mid];
			} else {
				bool inRight = nums[mid] <= target && target <= nums[right];
				inLeft = !inRight;
			}
			if(inLeft) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}

		}
		return -1;
	}
};

int main() {
	std::vector<int> nums{2,3,4,5,1};
	Solution s;
	s.search(nums, 1);
	return 0;
}