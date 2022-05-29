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
    int solve(int x, int y, vector<vector < int>> &grid, int m, int n)
    {
        int res = 0;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && !vis[xx][yy] && grid[xx][yy] != 0)
            {
                res = max(res, grid[xx][yy] + solve(xx, yy, grid, m, n));
            }
        }
        vis[x][y] = 0;
        return res;
    }
    int getMaximumGold(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
               	// memset(vis, 0, sizeof(vis));
                if (grid[i][j] != 0)
                    ans = max(ans, grid[i][j] + solve(i, j, grid, m, n));
            }
        }
        return ans;
    }
};