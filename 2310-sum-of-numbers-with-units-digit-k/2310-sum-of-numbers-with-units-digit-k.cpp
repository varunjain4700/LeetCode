class Solution
{
    public:
       	//(Coin change problem)Minimum number of coins variation?
        int solve(int idx, int k, vector<int> &nums, vector<vector< int>> &dp)
        {
            if (k == 0)
                return 0;
            if (idx == nums.size())
                return 1e7;
            if (dp[idx][k] != -1)
                return dp[idx][k];
            int ans = 1e7;
            ans = solve(idx + 1, k, nums, dp);
            if (nums[idx] <= k)
            {
                ans = min(ans, 1 + solve(idx, k - nums[idx], nums, dp));
            }
            return dp[idx][k] = ans;
        }
    int minimumNumbers(int num, int k)
    {
        if (num == 0)
            return 0;
        vector<int> nums;
        int i = k;
        if (i == 0)
            i += 10;
        while (i <= num)
        {
            nums.push_back(i);
            i += 10;
        }
        vector<vector < int>> dp(nums.size() + 1, vector<int> (num + 1, -1));
        int ans = solve(0, num, nums, dp);
        if (ans == 1e7)
            return -1;
        return ans;
    }
};