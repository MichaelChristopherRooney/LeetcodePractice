#include <vector>

class Solution {
public:
	void nextPermutation(std::vector<int>& nums) {
		if(nums.size() == 1) {
			return;
		}
		int pivot = nums.size() - 1;
		for(int i = nums.size() - 1; i > 0; i--) {
			if(nums[i - 1] < nums[i]) {
				break;
			}
			pivot--;
		}
		bool pivotSwapped = false;
		int firstSwapIndex = 0;
		// If pivot is 0, then the largest value is already in index 0. In this
		// case we skip the pivot swap
		if(pivot != 0) {
			// First of all try find the smallest number after the pivot that
			// is greater t number before the pivot.
			int smallest = 0;
			bool matchFound = false;
			for(int i = pivot; i < nums.size(); i++) {
				int v = nums[i];
				if(v > nums[pivot - 1] && (!matchFound || smallest > v)) {
					matchFound = true;
					smallest = v;
					firstSwapIndex = i;
				}
			}
			// Take the lowest number on the right side that is greater than the
			// number after the pivot and put it after the pivot.
			// For example:
			// {1, 2, 5, 4, 3}
			// Swap 2 and 3 to get
			// { 1, 3, 5, 4, 2}
			int temp = nums[pivot - 1];
			nums[pivot - 1] = nums[firstSwapIndex];
			nums[firstSwapIndex] = temp;
		}
		// Now reverse everything after the swap index.
		// Continuing from the above example, we would end up with:
		// { 1, 3, 2, 4, 5}
		for(int i = 0; i < nums.size() - 1 - pivot; i++) {
			int sourceIndex = i + pivot;
			int destIndex = nums.size() - 1 - i;
			if(sourceIndex >=  destIndex) {
				break;
			}
			int temp = nums[sourceIndex];
			nums[sourceIndex] = nums[destIndex];
			nums[destIndex] = temp;
		}
	}
};

int main() {
	//std::vector<int> nums{1, 3, 4, 2};
	std::vector<int> nums{2,1,2,2,2,2,2,1};
	Solution s;
	s.nextPermutation(nums);
	return 0;
}