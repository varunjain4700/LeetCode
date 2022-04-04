class Solution
{
    public:
        long long dp[201][201];
    long long solve(int idx, int k, vector<int> &nums, int n)
    {
        if (idx == n)
            return 0;
        if (k < 0)
            return INT_MAX;
        if (dp[idx][k] != -1)
            return dp[idx][k];
        long long ans = INT_MAX;
        int maxm = 0, total = 0;
        for (int i = idx; i < n; i++)
        {
            maxm = max(maxm, nums[i]);
            total += nums[i];
            int waste = maxm *(i - idx + 1) - total;
            ans = min(ans, solve(i + 1, k - 1, nums, n) + waste);
        }
        return dp[idx][k] = ans;
    }
    int minSpaceWastedKResizing(vector<int> &nums, int k)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, k, nums, n);
    }
};