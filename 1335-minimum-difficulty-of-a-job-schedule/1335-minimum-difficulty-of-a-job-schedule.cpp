class Solution
{
    public:
        int solve(int idx, int d, vector<int> &jobs, int n, vector<vector< int>> &dp)
        {
            if (idx == n && d == 0)
                return 0;
            if (idx == n || d == 0)
                return 1e7;
            if (dp[idx][d] != -1)
                return dp[idx][d];
            int ans = 1e7, maxm = 0;
            for (int i = idx; i < n; i++)
            {
                maxm = max(maxm, jobs[i]);
                ans = min(ans, maxm + solve(i + 1, d - 1, jobs, n, dp));
            }
            return dp[idx][d] = ans;
        }
    int minDifficulty(vector<int> &jobs, int d)
    {
        int n = jobs.size();
        vector<vector < int>> dp(n + 1, vector<int> (d + 1, -1));
        int ans = solve(0, d, jobs, n, dp);
        if (ans == 1e7)
            return -1;
        return ans;
    }
};