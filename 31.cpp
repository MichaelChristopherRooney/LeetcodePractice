#include <vector>

class Solution {
public:
	void nextPermutation(std::vector<int>& nums) {
		if(nums.size() == 1) {
			return;
		}
		int leftSwapIndex = nums.size() - 1;
		for(int i = nums.size() - 1; i > 0; i--) {
			leftSwapIndex--;
			if(nums[i - 1] < nums[i]) {
				break;
			}
		}
		// Find the smallest number after the left swap index that is greater
		// that the left swap value.
		int rightSwapIndex = 0;
		for(int i = nums.size() - 1; i > leftSwapIndex; i--) {
			if(nums[i] > nums[leftSwapIndex]) {
				rightSwapIndex = i;
				break;
			}
		}
		// If rightSwapIndex is 0, then we already have the largest possible
		// value.
		if(rightSwapIndex > 0) {
			// Swap the two values.
			// For example:
			// {1, 2, 5, 4, 3}
			// Swap 2 and 3 to get
			// { 1, 3, 5, 4, 2}
			int temp = nums[leftSwapIndex];
			nums[leftSwapIndex] = nums[rightSwapIndex];
			nums[rightSwapIndex] = temp;
		}
		// Now reverse everything after the left swap index.
		// Continuing from the above example, we would end up with:
		// { 1, 3, 2, 4, 5}
		int destIndex = nums.size() - 1;
		int offset = rightSwapIndex == 0 ? 0 : leftSwapIndex + 1;
		for(int i = 0; i < nums.size() - 1 - offset; i++) {
			int sourceIndex = i + offset;
			if(sourceIndex >= destIndex) {
				break;
			}
			int temp = nums[sourceIndex];
			nums[sourceIndex] = nums[destIndex];
			nums[destIndex] = temp;
			destIndex--;
		}
	}
};

int main() {
	//std::vector<int> nums{1, 3, 4, 2};
	std::vector<int> nums{1,3,2};
	Solution s;
	s.nextPermutation(nums);
	return 0;
}