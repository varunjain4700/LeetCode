class Solution
{
    public:

        int maxProductPath(vector<vector < int>> &grid)
        {
            int m = grid.size(), n = grid[0].size();
            long long mod = 1e9 + 7;
            vector<vector<vector< long long>>> dp(m + 1, vector<vector < long long>> (n + 1, vector < long long > (2, 1)));
            dp[0][0][0] = dp[0][0][1] = grid[0][0];
            for (int i = 1; i < n; i++)
            {
                dp[0][i][0] = dp[0][i][1] = grid[0][i] *dp[0][i - 1][0];
            }
            for (int i = 1; i < m; i++)
                dp[i][0][0] = dp[i][0][1] = grid[i][0] *dp[i - 1][0][0];
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (i - 1 >= 0)
                    {
                        dp[i][j][0] = min(grid[i][j] *dp[i - 1][j][0], grid[i][j] *dp[i - 1][j][1]);
                        dp[i][j][1] = max(grid[i][j] *dp[i - 1][j][0], grid[i][j] *dp[i - 1][j][1]);
                    }
                    if (j - 1 >= 0)
                    {
                        dp[i][j][0] = min({ dp[i][j][0],
                            grid[i][j] *dp[i][j - 1][0],
                            grid[i][j] *dp[i][j - 1][1] });
                        dp[i][j][1] = max({ dp[i][j][1],
                            grid[i][j] *dp[i][j - 1][0],
                            grid[i][j] *dp[i][j - 1][1] });
                    }
                }
            }
           	// for (int i = 0; i < m; i++)
           	// {
           	//     for (int j = 0; j < n; j++)
           	//     {
           	//         cout << dp[i][j][1] << " ";
           	//     }
           	//     cout << endl;
           	// }
            if (dp[m - 1][n - 1][1] < 0)
                return -1;
            return dp[m - 1][n - 1][1] % mod;
        }
};