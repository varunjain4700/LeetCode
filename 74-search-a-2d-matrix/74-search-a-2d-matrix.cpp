class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &mat, int target)
        {
            int n = mat.size(), m = mat[0].size();
            for (int i = 0; i < n; i++)
            {
                if (target >= mat[i][0] && target <= mat[i][m - 1])
                {
                    int low = 0, high = m - 1, mid;
                    while (low <= high)
                    {
                        mid = (low + high) / 2;
                        if (target == mat[i][mid])
                            return true;
                        if (target < mat[i][mid])
                            high = mid - 1;
                        else
                            low = mid + 1;
                    }
                }
            }
            return false;
        }
};