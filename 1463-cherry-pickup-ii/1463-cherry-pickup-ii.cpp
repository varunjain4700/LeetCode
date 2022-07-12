class Solution
{
    public:
       	//since both robots will remain at the same row at any moment so we don't need to maintain separate row index for each one.
        int dy[3] = { -1,
            0,
            1
        };
    int solve(int i, int j1, int j2, vector<vector < int>> &grid, int m, int n, vector< vector< vector< int>>> &dp)
    {
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return -1e7;
        if (i == m - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int ans = -1e7;
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j1 == j2)
                    ans = max(ans, grid[i][j1] + solve(i + 1, j1 + dy[k], j2 + dy[j], grid, m, n, dp));
                else
                    ans = max(ans, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + dy[k], j2 + dy[j], grid, m, n, dp));
            }
        }
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector< int>>> dp(m + 1, vector<vector < int>> (n + 1, vector<int> (n + 1, -1)));
        return solve(0, 0, n - 1, grid, m, n, dp);
    }
};