// TLE
class Solution {
public:
    int dp[300][10010];

int coinChange(vector<int> coins,int amount,int index)
{
	if (amount == 0) return 1;
	if (index < 0)return 0;
	if (dp[index][amount] != -1) return dp[index][amount];
	int w = 0;
	for (int i = 0; i <= amount; i+=coins[index])
	{
		w += coinChange(coins, amount - i, index - 1);
	}
	return dp[index][amount] = w;
}
int change(int amount, vector<int>& coins) {
	memset(dp, -1, sizeof(dp));
	return coinChange(coins, amount, coins.size() - 1);
}

};
