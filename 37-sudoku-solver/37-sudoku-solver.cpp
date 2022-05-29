class Solution
{
    public:
        bool check(int row, int col, vector<vector < char>> &board, char c)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i][col] == c)
                    return false;
                if (board[row][i] == c)
                    return false;
                if (board[3 *(row / 3) + i / 3][3 *(col / 3) + i % 3] == c)
                    return false;
            }
            return true;
        }
    bool solve(vector<vector < char>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (check(i, j, board, c))
                        {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector < char>> &board)
    {
        solve(board);
    }
};