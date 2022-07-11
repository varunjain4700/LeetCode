class Solution
{
    public:
       	// int solve(int i, int j, string &s1, string &s2, vector<vector < int>> &dp)
       	// {
       	//     if (i < 0 && j >= 0)
       	//         return 0;
       	//     if (j < 0)
       	//         return 1;
       	//     if (dp[i][j] != -1)
       	//         return dp[i][j];
       	//     int ans = 0;
       	//     if (s1[i] == s2[j])
       	//         ans = solve(i - 1, j - 1, s1, s2,dp) + solve(i - 1, j, s1, s2,dp);
       	//     else
       	//     {
       	//         ans += solve(i - 1, j, s1, s2,dp);
       	//     }
       	//     return dp[i][j] = ans;
       	// }
        int numDistinct(string s, string t)
        {
            int m = s.size(), n = t.size();
            vector<vector < double>> dp(m + 1, vector<double> (n + 1, 0));
           	//long long gives runtime error don't know why
           	// return solve(m - 1, n - 1, s, t, dp);
            for (int i = 0; i <= m; i++)
                dp[i][0] = 1;
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (s[i - 1] == t[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return (int) dp[m][n];
        }
};