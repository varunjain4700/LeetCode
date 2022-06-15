class Solution
{
    public:
        int minPathCost(vector<vector < int>> &grid, vector< vector< int>> &cost)
        {
            int m = grid.size(), n = grid[0].size();
            vector<vector < int>> dp(m, vector<int> (n, INT_MAX));
            for (int i = 0; i < n; i++)
                dp[0][i] = grid[0][i];
            for (int i = 1; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][k] + cost[grid[i - 1][k]][j]);
                    }
                   	// cout<<dp[i][j]<<" ";
                }
               	// cout << endl;
            }
            int ans = INT_MAX;
            for (int i = 0; i < n; i++)
                ans = min(ans, dp[m - 1][i]);
            return ans;
        }
};