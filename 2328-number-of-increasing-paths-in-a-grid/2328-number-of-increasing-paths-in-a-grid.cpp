class Solution
{
    long long mod=1e9+7;
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
    long long solve(int x, int y, vector<vector < int>> &grid, int n, int m, vector< vector< long long>> &dp)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        long long ans = 0;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] > grid[x][y])
            {
                long long temp = 1 + solve(xx, yy, grid, n, m, dp);
                ans += temp;
                ans%=mod;
            }
        }
        return dp[x][y] = ans;
    }
    int countPaths(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector < long long>> dp(m, vector < long long > (n, -1));
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long temp = solve(i, j, grid, m, n, dp);
               	//cout<<temp<<endl;
                ans += temp;
                ans %= mod;
            }
        }
        return (ans + n *m) % mod;
    }
};