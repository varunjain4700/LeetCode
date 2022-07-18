class Solution
{
    public:
        int solve(int i, int j, vector<vector < int>> &grid, int n, vector< vector< int>> &dp)
        {
            if (i == n)
                return 0;
            if (j < 0 || j >= n)
                return 1e7;
            if (dp[i][j] != -1)
                return dp[i][j];
            int ans = 1e7;
            ans = min(ans, grid[i][j] + solve(i + 1, j, grid, n, dp));
            ans = min(ans, grid[i][j] + solve(i + 1, j - 1, grid, n, dp));
            ans = min(ans, grid[i][j] + solve(i + 1, j + 1, grid, n, dp));
            return dp[i][j] = ans;
        }
    int minFallingPathSum(vector<vector < int>> &mat)
    {
        int n = mat.size(), ans = 1e7;
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, solve(0, i, mat, n, dp));
        }
        return ans;
    }
};