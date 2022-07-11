class Solution
{
    public:
        // int solve(int idx1, int idx2, string &str1, string &str2, int m, int n, vector<vector < int>> &dp)
        // {
        //     if (idx1 == m || idx2 == n)
        //         return 0;
        //     if (dp[idx1][idx2] != -1)
        //         return dp[idx1][idx2];
        //     int ans = 0;
        //     if (str1[idx1] == str2[idx2])
        //         ans = 1 + solve(idx1 + 1, idx2 + 1, str1, str2, m, n, dp);
        //     else
        //         ans = max(solve(idx1, idx2 + 1, str1, str2, m, n, dp), solve(idx1 + 1, idx2, str1, str2, m, n, dp));
        //     return dp[idx1][idx2] = ans;
        // }
    int longestCommonSubsequence(string str1, string str2)
    {
        int m = str1.size(), n = str2.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));
       	// return solve(0, 0, str1, str2, m, n, dp);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};