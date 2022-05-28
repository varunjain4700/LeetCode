class Solution
{
    public:
        int solve(int idx, int target, vector<int> &nums, int n, vector<vector< int>> &dp)
        {
            if (target == 0)
            {
                return 1;
            }
            if (idx == n)
                return 0;
            if (dp[idx][target] != -1)
                return dp[idx][target];
            int ans = 0;
            if (nums[idx] <= target)
            {
                ans = solve(0, target - nums[idx], nums, n, dp) + solve(idx + 1, target, nums, n, dp);
            }
            else
                ans = solve(idx + 1, target, nums, n, dp);
            return dp[idx][target] = ans;
        }
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector < int>> dp(n + 1, vector<int> (target + 1, -1));
        return solve(0, target, nums, n, dp);
    }
};