#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
		std::vector<std::vector<int>> result;
		std::vector<int> currentSet;
		std::ranges::sort(candidates);
		recurse(candidates, target, 0, 0, result, currentSet);
		return result;
	}

	void recurse(
			const std::vector<int>& candidates,
			const int target,
			const int index,
			int curSum,
			std::vector<std::vector<int>> &result,
			std::vector<int> &currentSet) {
		if(curSum > target) {
			return;
		}
		if(curSum == target) {
			result.emplace_back(currentSet);
		}
		for(int i = index; i < candidates.size(); i++) {
			if(i > index && candidates[i] == candidates[i - 1]) {
				continue;
			}
			currentSet.emplace_back(candidates[i]);
			recurse(candidates, target, i + 1, curSum + candidates[i], result, currentSet);
			currentSet.pop_back();
		}
	}
};

int main() {
	std::vector<int> candidates{2,5,2,1,2};
	Solution s;
	const auto result = s.combinationSum2(candidates, 5);
	return 0;
}