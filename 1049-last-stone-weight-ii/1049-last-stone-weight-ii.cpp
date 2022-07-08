class Solution
{
    public:
        int lastStoneWeightII(vector<int> &stones)
        {
            int n = stones.size(), sum = 0;
            for (int i = 0; i < n; i++)
                sum += stones[i];
            vector<vector < bool>> dp(n + 1, vector<bool> (sum + 1, 0));
            for (int i = 0; i <= n; i++)
                dp[i][0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    if (stones[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            int min_diff = INT_MAX;
            for (int i = 0; i <= sum / 2; i++)
            {
                if (dp[n][i] == 1)
                    min_diff = min(min_diff, sum - 2 *i);
            }
            return min_diff;
        }
};