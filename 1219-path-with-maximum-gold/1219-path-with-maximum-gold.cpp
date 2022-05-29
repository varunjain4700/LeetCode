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
    bool vis[16][16];
    void solve(int x, int y, vector<vector < int>> &grid, int m, int n, int sum, int &res)
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && !vis[xx][yy] && grid[xx][yy] != 0)
            {
                vis[xx][yy] = 1;
                sum += grid[xx][yy];
                res = max(res, sum);
                solve(xx, yy, grid, m, n, sum, res);
                vis[xx][yy] = 0;
                sum -= grid[xx][yy];
            }
        }
    }
    int getMaximumGold(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                memset(vis, 0, sizeof(vis));
                vis[i][j] = 1;
                int res = grid[i][j];
                if (grid[i][j] != 0)
                    solve(i, j, grid, m, n, grid[i][j], res);
                ans = max(ans, res);
            }
        }
        return ans;
    }
};