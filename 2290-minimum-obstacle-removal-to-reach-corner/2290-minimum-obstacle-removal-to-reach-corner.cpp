class Solution
{
    public:
        int minimumObstacles(vector<vector < int>> &grid)
        {
            int m = grid.size(), n = grid[0].size();
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
            //vector<vector < bool>> vis(m, vector<bool> (n, 0));
            vector<vector < int>> dis(m, vector<int> (n, 1e7));
            queue<pair<int, int>> q;
            q.push({ 0,
                0 });
            dis[0][0] = 0;
            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for (int i = 0; i < 4; i++)
                {
                    int xx = x + dx[i], yy = y + dy[i];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n)
                    {
                        if (grid[xx][yy] == 1)
                        {
                            if (dis[xx][yy] > dis[x][y] + 1)
                            {
                                dis[xx][yy] = dis[x][y] + 1;
                                q.push({ xx,
                                    yy });
                            }
                        }
                        else
                        {
                            if ( dis[xx][yy] > dis[x][y])
                            {
                                dis[xx][yy] = dis[x][y];
                                //vis[xx][yy] = 1;
                                q.push({ xx,
                                    yy });
                            }
                        }
                    }
                }
            }
           	// for (int i = 0; i < m; i++)
           	// {
           	//     for (int j = 0; j < n; j++)
           	//     {
           	//         cout << dis[i][j] << " ";
           	//     }
           	//     cout << endl;
           	// }
            return dis[m - 1][n - 1];
        }
};