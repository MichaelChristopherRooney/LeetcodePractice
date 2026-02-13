#include <vector>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if(nums.size() == 1) {
			return 1;
		}
		std::vector<int> deduped;
		for(int i = 0; i < nums.size(); i++) {
			int val = nums[i];
			while(i < nums.size() - 1 && nums[i + 1] == val) {
				i++;
			}
			deduped.emplace_back(val);
		}
		nums = deduped;
		return deduped.size();
	}
};

int main() {
	std::vector<int> nums{1,1};
	Solution s;
	int k = s.removeDuplicates(nums);
	return 0;
}