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
    void solve(int x, int y, int end_x, int end_y, vector<vector < int>> &grid, int n, int m, vector< vector< bool>> vis, int cnt, int total, int &ans)
    {
        if (x == end_x && y == end_y)
        {
            if (cnt == total)
                ans++;
            return;
        }
       	// cout<<x<<" "<<y<<endl;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && grid[xx][yy] != -1)
            {
                vis[xx][yy] = 1;
                cnt++;
                solve(xx, yy, end_x, end_y, grid, n, m, vis, cnt, total, ans);
                vis[xx][yy] = 0;
                cnt--;
            }
        }
    }
    int uniquePathsIII(vector<vector < int>> &grid)
    {
        int start_x, start_y, end_x, end_y, total = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                }
                else if (grid[i][j] == 2)
                {
                    end_x = i;
                    end_y = j;
                }
                else if (grid[i][j] == -1)
                    total++;
            }
        }
        total = n *m - total;
        vector<vector < bool>> vis(n + 1, vector<bool> (m + 1, 0));
        vis[start_x][start_y] = 1;
        int ans = 0;
        solve(start_x, start_y, end_x, end_y, grid, n, m, vis, 1, total, ans);
        return ans;
    }
};