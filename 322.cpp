#include <vector>

class Solution {
public:
	int coinChange(std::vector<int>& coins, int amount) {
		if(amount == 0) {
			return 0;
		}
		int max = amount + 1;
		std::vector<int> dp(max, max);
		dp[0] = 0;
		for(int i = 1; i <= amount; i++) {
			for(const auto coin : coins) {
				if(i - coin >= 0 && dp[i - coin] <= amount) {
					dp[i] = std::min(dp[i], dp[i - coin] + 1);
				}
			}
		}
		if(dp[amount] == max) {
			return - 1;
		}
		return dp[amount];
	}
};

int main() {
	std::vector<int> coins{1, 2, 5};
	Solution s;
	const auto result = s.coinChange(coins, 11);
	return 0;
}