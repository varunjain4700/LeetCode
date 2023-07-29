class Solution
{
    public:
        int solve(int x, int y, int m, int n, vector<vector < int>> &grid, vector< vector< int>> &dp)
        {
            if (x >= m || y >= n)
                return 0;
            if (x == m - 1 && y == n - 1 && grid[x][y] == 0)
                return 1;
            if (dp[x][y] != -1)
                return dp[x][y];
            int ans = 0;
            if (x + 1 < m && grid[x + 1][y] == 0)
                ans += solve(x + 1, y, m, n, grid, dp);
            if (y + 1 < n && grid[x][y + 1] == 0)
                ans += solve(x, y + 1, m, n, grid, dp);
            return dp[x][y] = ans;
        }
    int uniquePathsWithObstacles(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] != 0)
            return 0;
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(0, 0, m, n, grid, dp);
    }
};