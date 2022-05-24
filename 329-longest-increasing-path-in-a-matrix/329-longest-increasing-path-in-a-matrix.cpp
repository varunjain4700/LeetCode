class Solution
{
    public:
        int dx[4] = { -1,
            0,
            0,
            1
        };
    int dy[4] = { 0,
        -1,
        1,
        0
    };
    int solve(int x, int y, int n, int m, vector<vector < int>> &mat, vector< vector< int>> &dp)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        int ans = 1;
        for (int k = 0; k < 4; k++)
        {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && mat[xx][yy] > mat[x][y])
            {
                ans = max(ans, 1 + solve(x + dx[k], y + dy[k], n, m, mat, dp));
            }
        }
        return dp[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector < int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int ans = 1;
        vector<vector < int>> dp(n, vector<int> (m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp = solve(i, j, n, m, mat, dp);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};