class Solution
{
    public:
        int findTargetSumWays(vector<int> &nums, int target)
        {
            int n = nums.size(), sum = 0;
            for (int i = 0; i < n; i++)
                sum += nums[i];
            vector<vector < int>> dp(n + 1, vector<int> (sum + 1, 0));
            for (int i = 0; i <= n; i++)
                dp[i][0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    if (nums[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            int cnt = 0;
            for (int i = 0; i <= sum; i++)
            {
                if (dp[n][i] >= 1)
                {
                    int diff = sum - 2 * i;
                    if (diff == target)
                        cnt += dp[n][i];
                }
            }
            return cnt;
        }
};