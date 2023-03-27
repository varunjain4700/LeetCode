class Solution
{
    public:
        int solve(vector<vector < int>> &grid, int row, int col, vector< vector< int>> &dp)
        {
            if (row < 0 || col < 0)
                return 0;
            if (dp[row][col] != -1)
                return dp[row][col];
            int ans = 0;
            if (row == 0)
                ans = grid[row][col] + solve(grid, row, col - 1, dp);
            else if (col == 0)
                ans = grid[row][col] + solve(grid, row - 1, col, dp);
            else
                ans = grid[row][col] + min(solve(grid, row, col - 1, dp), solve(grid, row - 1, col, dp));
            return dp[row][col] = ans;
        }
    int minPathSum(vector<vector < int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        vector<vector < int>> dp(row, vector<int> (col, -1));
        return solve(grid, row - 1, col - 1, dp);
    }
};