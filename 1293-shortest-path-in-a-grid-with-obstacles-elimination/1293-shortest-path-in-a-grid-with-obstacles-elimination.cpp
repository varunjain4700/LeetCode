class Solution
{
    public:
        int shortestPath(vector<vector < int>> &grid, int k)
        {
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
            int m = grid.size(), n = grid[0].size();
            queue<pair<pair<int, int>, int>> q;
            q.push({
		{ 0,
                    0 },
                0 });
            bool vis[45][45][1650];
            int dis[45][45][1650];
            memset(vis, 0, sizeof(vis));
            memset(dis, 0, sizeof(dis));
            vis[0][0][0] = 1;
            while (!q.empty())
            {
                pair<pair<int, int>, int> p = q.front();
                q.pop();
                int x = p.first.first, y = p.first.second, obs = p.second;
                for (int i = 0; i < 4; i++)
                {
                    int xx = x + dx[i], yy = y + dy[i];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n)
                    {
                        if (!vis[xx][yy][obs] && grid[xx][yy] == 0)
                        {
                            vis[xx][yy][obs] = 1;
                            dis[xx][yy][obs] = dis[x][y][obs] + 1;
                            q.push({
		{
                                    xx,
                                    yy
                                },
                                obs });
                        }
                        else
                        {
                            if (!vis[xx][yy][obs + 1] && obs < k)
                            {
                                vis[xx][yy][obs + 1] = 1;
                                dis[xx][yy][obs + 1] = dis[x][y][obs] + 1;
                                q.push({
		{
                                        xx,
                                        yy
                                    },
                                    obs + 1 });
                            }
                        }
                    }
                }
            }
           	// for(int i=0;i < m;i++)
           	// {
           	//     for(int j=0;j < n;j++)
           	//         cout<<dis[i][j][1]<<" ";
           	//     cout<<endl;
           	// }
            int ans = INT_MAX;
            for (int i = 0; i <= k; i++)
            {
                if (vis[m - 1][n - 1][i])
                    ans = min(ans, dis[m - 1][n - 1][i]);
            }
            if (ans == INT_MAX)
                return -1;
            return ans;
        }
};