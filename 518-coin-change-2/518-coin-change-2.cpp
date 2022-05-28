class Solution
{
    public:
        int solve(int idx, int amount, vector<int> &coins, int n, vector<vector< int>> &dp)
        {
            if (amount == 0)
            {
                return 1;
            }
            if (idx == n)
                return 0;
            if (dp[idx][amount] != -1)
                return dp[idx][amount];
            int ans = 0;
            if (coins[idx] <= amount)
            {
                ans = solve(idx, amount - coins[idx], coins, n, dp) + solve(idx + 1, amount, coins, n, dp);
            }
            else
                ans = solve(idx + 1, amount, coins, n, dp);
            return dp[idx][amount] = ans;
        }
    // int iterative(vector<int> &coins, int amount, int n)
    // {
    //     vector<vector < int>> dp(n+1, vector<int> (amount + 1, 0));
    //     for (int i = 0; i <= n; i++)
    //         dp[i][0] = 1;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= amount; j++)
    //         {
    //             if (coins[i - 1] <= j)
    //                 dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
    //             else
    //                 dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    //     return dp[n][amount];
    // }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, -1));
       	return solve(0, amount, coins, n, dp);
        //return iterative(coins, amount, n);
    }
};