class Solution
{
    public:
        int solve(int idx, vector<int> &arr, int k, int n, vector<int> &dp)
        {
            if (idx == n)
                return 0;
            if (dp[idx] != -1)
                return dp[idx];
            int ans = 0, maxm = 0;
            for (int i = idx; i < min(n, idx + k); i++)
            {
                maxm = max(maxm, arr[i]);
                ans = max(ans, maxm *(i - idx + 1) + solve(i + 1, arr, k, n, dp));
            }
            return dp[idx] = ans;
        }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(0, arr, k, n, dp);
    }
};