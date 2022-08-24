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
    map<int, int> comp_size;
    void dfs1(int x, int y, vector<vector < int>> &grid, int color)
    {
        int n = grid.size();
        grid[x][y] = color;
        comp_size[color]++;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 1)
                dfs1(xx, yy, grid, color);
        }
    }
    int largestIsland(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int ans = 0, color = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs1(i, j, grid, ++color);
                    ans = max(ans, comp_size[color]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> colors;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0)
                            colors.insert(grid[x][y]);
                    }
                    int temp = 0;
                    for (auto it: colors)
                        temp += comp_size[it];
                    ans = max(ans, temp + 1);
                }
            }
        }
        return ans;
    }
};