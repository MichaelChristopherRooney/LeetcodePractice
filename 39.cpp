#include <array>
#include <vector>
#include <unordered_set>

class Solution {
public:
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
		std::unordered_set<std::string> alreadySeen;
		std::ranges::sort(candidates);
		std::vector<std::vector<int>> result;
		std::vector<int> currentSet{};
		for(int i = 0; i < candidates.size(); i++) {
			recurse(candidates, target, i, 0, result, currentSet, alreadySeen);
		}
		return result;
	}

private:
	void recurse(
			const std::vector<int>& candidates,
			int target,
			int index,
			int curSum,
			std::vector<std::vector<int>> &result,
			std::vector<int> &currentSet,
			std::unordered_set<std::string> &alreadySeen) {
		curSum += candidates[index];
		// Before recursing, check if we'll exceed the target. If we do, there's
		// no point continuing. This works as we've sorted the candidates already.
		if(curSum > target) {
			return;
		}
		currentSet.emplace_back(candidates[index]);
		// Same for if we reach the target.
		if(curSum == target) {
			result.emplace_back(currentSet);
			currentSet.pop_back();
			return;
		}
		for(int i = index; i < candidates.size(); i++) {
			recurse(candidates, target, i, curSum, result, currentSet, alreadySeen);
		}
		currentSet.pop_back();
	}
};
int main() {
	std::vector<int> candidates{2,3,6,7};
	Solution s;
	const auto result = s.combinationSum(candidates, 7);
	return 0;
}