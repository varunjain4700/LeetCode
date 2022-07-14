class Solution
{
    public:
        int minInsertions(string s)
        {
            int n = s.size();
            string t;
            for (int i = n - 1; i >= 0; i--)
                t += s[i];
            vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (s[i - 1] == t[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            return n - dp[n][n];
        }
};