#include <vector>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		if(nums.size() == 1) {
			if(nums[0] == val) {
				return 0;
			}
			return 1;
		}
		int resultSize = nums.size();
		int swapIndex = nums.size() - 1;
		int i = 0;
		while(i <= swapIndex) {
			if(nums[i] != val) {
				i++;
				continue;
			}
			nums[i] = nums[swapIndex];
			swapIndex--;
			resultSize--;
		}
		return resultSize;
	}
};

int main() {
	std::vector<int> nums{1, 1};
	Solution s;
	int k = s.removeElement(nums, 1);
	return 0;
}