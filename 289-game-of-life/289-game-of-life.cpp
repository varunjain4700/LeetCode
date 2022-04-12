class Solution
{
    public:
        void gameOfLife(vector<vector < int>> &board)
        {
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
                1,
                -1,
                1,
                -1,
                1,
                0,
                -1
            };
            vector<vector < int>> grid = board;
            int m = board.size(), n = board[0].size();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int dead = 0, live = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        int xx = i + dx[k], yy = j + dy[k];
                        if (xx >= 0 && xx < m && yy >= 0 && yy < n)
                        {
                            if (grid[xx][yy] == 0)
                                dead++;
                            else
                                live++;
                        }
                    }
                    if (board[i][j] == 1 && live < 2)
                    {
                        board[i][j] = 0;
                        continue;
                    }
                    if (board[i][j] == 1 && (live == 2 || live == 3))
                        continue;
                    if (board[i][j] == 1 && live > 3)
                    {
                        board[i][j] = 0;
                        continue;
                    }
                    if (board[i][j] == 0 && live == 3)
                        board[i][j] = 1;
                }
            }
        }
};