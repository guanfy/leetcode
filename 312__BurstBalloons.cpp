#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
int maxCoins(int[] arr) {
if (arr == null || arr.length == 0) {
return 0;
}
int size = arr.length;
int[] all = new int[size + 2];
all[0] = 1;
all[size + 1] = 1;
for (int i = 0; i < size; i++) {
all[i + 1] = arr[i];
}
int[][] dp = new int[size] [size];
for (int i = size - 1; i >= 0; i--) {
dp[i][i] = all[i] * all[i + 1] * all[i + 2];
for (int j = i + 1; j < size; j++) {
int coins = 0;
for (int k = i; k <= j; k++) {
coins = all[i] * all[k + 1] * all[j + 2];
coins += k != i ? dp[i][k - 1] : 0;
coins += k != j ? dp[k + 1][j] : 0;
dp[i][j] = Math.max(dp[i][j], coins);
}
}
}
return dp[0][size - 1];
}
*/
int maxCoins(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int n = nums.size();
	vector<int>coins(n + 2,0);
	coins[0] = 1;
	coins[n + 1] = 1;
	for (int i = 1; i <= n; i++)
	{
		coins[i] = nums[i - 1];
	}

	vector<vector<int> > dp(n, vector<int>(n,0));
	for (int i = n - 1; i >= 0; i--)
	{
		dp[i][i] = coins[i] * coins[i + 1] * coins[i + 2];
		for (int j = i + 1; j < n; j++)
		{
			int coin = 0;
			for (int k = i; k <= j; k++)
			{
				coin = coins[k] * coins[k + 1] * coins[k + 2];
				coin += k != i ? dp[i][k - 1] : 0;
				coin += k != j ? dp[k + 1][j] : 0;
				dp[i][j] = max(dp[i][j], coin);
			}
		}
	}
	return dp[0][n - 1];
}