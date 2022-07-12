class Solution
{
    public:
       	//OMG,this question is too dangerous.
       	//Convert this 4d dp into 3d dp if you have some strength left...
        int dp[51][51][51][51];
    int solve(int i1, int i2, int j1, int j2, vector<vector < int>> &grid, int n)
    {
        if (j1 >= n || j2 >= n || i1 >= n || i2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e7;
        if (i1 == n - 1 && j1 == n - 1)
            return grid[i1][j1];
        if (i2 == n - 1 && j2 == n - 1)
            return grid[i2][j2];
        if (dp[i1][i2][j1][j2] != -1)
            return dp[i1][i2][j1][j2];
        int ans = -1e7, temp = 0;
        if (i1 == i2 && j1 == j2)
            temp = grid[i1][j1];
        else
            temp = grid[i1][j1] + grid[i2][j2];
        ans = max(ans, temp + solve(i1 + 1, i2 + 1, j1, j2, grid, n));
        ans = max(ans, temp + solve(i1 + 1, i2, j1, j2 + 1, grid, n));
        ans = max(ans, temp + solve(i1, i2 + 1, j1 + 1, j2, grid, n));
        ans = max(ans, temp + solve(i1, i2, j1 + 1, j2 + 1, grid, n));
        return dp[i1][i2][j1][j2] = ans;
    }
    int cherryPickup(vector<vector < int>> &grid)
    {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, solve(0, 0, 0, 0, grid, n));
    }
};