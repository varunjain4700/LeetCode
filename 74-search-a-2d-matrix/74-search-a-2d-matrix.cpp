class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &mat, int target)
        {
            int n = mat.size(), m = mat[0].size();
            int low = 0, high = m *n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int num = mat[mid / m][mid % m];	//(mid/m) gives the row and mid%m gives the column
                if (num == target)
                    return true;
                if (num > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return false;
        }
};