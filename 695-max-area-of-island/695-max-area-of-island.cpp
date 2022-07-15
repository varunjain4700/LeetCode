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
    void dfs(int x, int y, vector<vector < int>> &grid, int m, int n, int &cnt)
    {
        grid[x][y] = 2;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == 1)
                dfs(xx, yy, grid, m, n, cnt);
        }
    }
    int maxAreaOfIsland(vector<vector < int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int cnt = 0;
                    dfs(i, j, grid, m, n, cnt);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};