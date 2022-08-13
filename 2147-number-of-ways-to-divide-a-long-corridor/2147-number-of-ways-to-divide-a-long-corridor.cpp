class Solution
{
    public:
        int mod = 1e9 + 7;
    int solve(int idx, int seats, string &nums, vector<vector < int>> &dp)
    {
        if (idx == nums.size() && seats == 2)
            return 1;
        if (idx == nums.size())
            return 0;
        if (dp[idx][seats] != -1)
            return dp[idx][seats];
        int ans = 0;
        if (seats == 2)
        {
            if (nums[idx] == 'P')
                ans = (solve(idx + 1, seats, nums, dp) % mod + solve(idx + 1, 0, nums, dp) % mod) % mod;
            else
                ans += solve(idx + 1, 1, nums, dp);
        }
        else
        {
            if (nums[idx] == 'S')
                ans += solve(idx + 1, seats + 1, nums, dp);
            else
                ans += solve(idx + 1, seats, nums, dp);
        }
        ans %= mod;
        return dp[idx][seats] = ans;
    }
    int numberOfWays(string nums)
    {
        int n = nums.size();
        vector<vector < int>> dp(n + 1, vector<int> (3, -1));
        return solve(0, 0, nums, dp);
    }
};