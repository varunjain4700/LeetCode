class Solution
{
    public:
        vector<vector < int>> generateMatrix(int n)
        {
            vector<vector < int>> res(n, vector<int> (n, 0));
            int top_row = 0, right_col = n - 1, bottom_row = n - 1, left_col = 0;
            int cnt = 0;
            while (top_row <= bottom_row && left_col <= right_col)
            {
                for (int i = left_col; i <= right_col; i++)
                    res[top_row][i] = ++cnt;
                top_row++;
                for (int i = top_row; i <= bottom_row; i++)
                    res[i][right_col] = ++cnt;
                right_col--;
                for (int i = right_col; i >= left_col; i--)
                    res[bottom_row][i] = ++cnt;
                bottom_row--;
                for (int i = bottom_row; i >= top_row; i--)
                    res[i][left_col] = ++cnt;
                left_col++;
            }
            return res;
        }
};