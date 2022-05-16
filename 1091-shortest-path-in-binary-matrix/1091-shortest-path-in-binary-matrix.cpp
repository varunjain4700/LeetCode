class Solution
{
    public:
        int shortestPathBinaryMatrix(vector<vector < int>> &grid)
        {
            int n = grid.size();
            if (n == 1 && grid[0][0] == 0)
                return 1;
            int dx[8] = { -1,
                -1,
                -1,
                0,
                0,
                1,
                1,
                1
            };
            int dy[8] = { 0,
                -1,
                1,
                1,
                -1,
                0,
                -1,
                1
            };
            vector<vector < bool>> vis(n, vector<bool> (n, 0));
            queue<pair<int, int>> q;
            if (grid[0][0] != 0)
                return -1;
            q.push({ 0,
                0 });
            vis[0][0] = 1;
            int ans = 1;
            while (!q.empty())
            {
                int sz = q.size();
                ans++;
                while (sz--)
                {
                    pair<int, int> p = q.front();
                    int x = p.first, y = p.second;
                    q.pop();
                    for (int i = 0; i < 8; i++)
                    {
                        int xx = x + dx[i], yy = y + dy[i];
                        if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 0 && !vis[xx][yy])
                        {
                            if (xx == n - 1 && yy == n - 1)
                                return ans;
                            vis[xx][yy] = 1;
                            q.push({ xx,
                                yy });
                        }
                    }
                }
            }
            return -1;
        }
};