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
    void dfs(int x, int y, int fillColor, vector<vector < int>> &grid, int rows, int cols, int originalColor)
    {
        grid[x][y] = fillColor;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < rows && yy >= 0 && yy < cols && grid[xx][yy] == originalColor)
            {
                dfs(xx, yy, fillColor, grid, rows, cols, originalColor);
            }
        }
    }
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;
        dfs(sr, sc, color, image, image.size(), image[0].size(), image[sr][sc]);
        return image;
    }
};