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
    void dfs(int x, int y, vector<vector < int>> &grid, vector< vector< bool>> &vis, int m, int n)
    {
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && !vis[xx][yy] && grid[xx][yy] >= grid[x][y])
                dfs(xx, yy, grid, vis, m, n);
        }
    }
    vector<vector < int>> pacificAtlantic(vector<vector < int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector < bool>> vis1(m, vector<bool> (n, 0)), vis2(m, vector<bool> (n, 0));
        for (int i = 0; i < m; i++)
        {
            if (!vis1[i][0])	//first column
                dfs(i, 0, heights, vis1, m, n);
            if (!vis2[i][n - 1])	//last column
                dfs(i, n - 1, heights, vis2, m, n);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis1[0][i])	//first row
                dfs(0, i, heights, vis1, m, n);
            if (!vis2[m - 1][i])	//last row
                dfs(m - 1, i, heights, vis2, m, n);
        }
        vector<vector < int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis1[i][j] && vis2[i][j])
                    res.push_back({ i,
                        j });
            }
        }
        return res;
    }
};