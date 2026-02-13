#include <vector>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int inner = 1;
		for (int outer = 1; outer < nums.size(); outer++) {
			if (nums[outer] != nums[inner - 1]) {
				nums[inner] = nums[outer];
				inner++;
			}
		}

		return inner;
	}
};

int main() {
	std::vector<int> nums{0,1,2};
	Solution s;
	int k = s.removeDuplicates(nums);
	return 0;
}