#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
		std::vector<std::vector<int>> result;
		if(nums.size() < 4) {
			return result;
		}
		std::sort(nums.begin(), nums.end());
		int n = nums.size();
		for(int a = 0; a < n - 3; a++) {
			auto aNum = static_cast<std::int64_t>(nums[a]);
			for(int b = a + 1; b < n - 2; b++) {
				auto bNum = static_cast<std::int64_t>(nums[b]);
				std::int64_t outerSum = aNum + bNum;
				std::int64_t want = static_cast<std::int64_t>(target) - outerSum;
				int c = b + 1;
				int d = n - 1;
				while(c < d) {
					std::int64_t innerSum = static_cast<std::int64_t>(nums[c]) + static_cast<std::int64_t>(nums[d]);
					if(want == innerSum) {
						result.emplace_back(std::vector{(int)aNum, (int)bNum, nums[c], nums[d]});
						int cTemp = c;
						int dTemp = d;
						while(c < d && nums[c] == nums[cTemp]) {
							c++;
						}
						while(c < d && nums[d] == nums[dTemp]) {
							d--;
						}
					} else if (innerSum < want) {
						c++;
					} else {
						d--;
					}
				}
				// Skip duplicates.
				while(b < n - 2 && nums[b] == nums[b + 1]) {
					b++;
				}
			}
			// Skip duplicates.
			while(a < n - 3 && nums[a] == nums[a + 1]) {
				a++;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	//std::vector<int> input{-2,-1,-1,1,1,2,2};
	//int target = 0;
	std::vector<int> input{1,0,-1,0,-2,2};
	int target = 0;
	const auto result = s.fourSum(input, target);
	return 0;
}