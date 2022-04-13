class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &mat)
        {
            vector<int> res;
            int top_row = 0, right_col = mat[0].size() - 1, bottom_row = mat.size() - 1, left_col = 0;
            int cnt = 0;
            while (top_row <= bottom_row && left_col <= right_col)
            {
                if (cnt == 0)
                {
                    for (int i = left_col; i <= right_col; i++)
                        res.push_back(mat[top_row][i]);
                    top_row++;
                }
                else if (cnt == 1)
                {
                    for (int i = top_row; i <= bottom_row; i++)
                        res.push_back(mat[i][right_col]);
                    right_col--;
                }
                else if (cnt == 2)
                {
                    for (int i = right_col; i >= left_col; i--)
                        res.push_back(mat[bottom_row][i]);
                    bottom_row--;
                }
                else
                {
                    for (int i = bottom_row; i >= top_row; i--)
                        res.push_back(mat[i][left_col]);
                    left_col++;
                }
                cnt++;
                cnt %= 4;
            }
            return res;
        }
};