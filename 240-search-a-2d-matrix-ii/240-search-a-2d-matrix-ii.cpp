class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &mat, int target)
        {
            int m = mat.size(), n = mat[0].size();
            int i = 0, j = n - 1;
            while (i < m && j >= 0)
            {
                if (target > mat[i][j])
                    i++;
                else if (target < mat[i][j])
                    j--;
                else
                    return true;
            }
            return false;
        }
};