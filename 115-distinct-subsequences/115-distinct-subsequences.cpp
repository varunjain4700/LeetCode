class Solution
{
    public:
        int solve(int i, int j, string &s1, string &s2, vector<vector < int>> &dp)
        {
            if (i < 0 && j >= 0)
                return 0;
            if (j < 0)
                return 1;
            if (dp[i][j] != -1)
                return dp[i][j];
            int ans = 0;
            if (s1[i] == s2[j])
                ans = solve(i - 1, j - 1, s1, s2,dp) + solve(i - 1, j, s1, s2,dp);
            else
            {
                ans += solve(i - 1, j, s1, s2,dp);
            }
            return dp[i][j] = ans;
        }
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(m - 1, n - 1, s, t, dp);
    }
};