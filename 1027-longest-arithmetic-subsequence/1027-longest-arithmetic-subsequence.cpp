class Solution
{
    public:
        int longestArithSeqLength(vector<int> &nums)
        {
            int n = nums.size();
            int ans = 0;
            vector<vector < int>> dp(n + 1, vector<int> (1005, 1));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    int comm_diff = nums[j] - nums[i] + 500;
                    dp[i][comm_diff] = max(dp[i][comm_diff], dp[j][comm_diff] + 1);
                    ans = max(ans, dp[i][comm_diff]);
                }
            }
            return ans;
        }
};