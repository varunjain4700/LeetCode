class Solution
{
    public:
       	//[1,2,3] Transpose [1,4,7] Invert rows [7,4,1]
       	//[4,5,6]----------->[2,5,8]------------->[8,5,2]
       	//[7,8,9]           [3,6,9]             [9,6,3]
        void rotate(vector<vector < int>> &mat)
        {
            int n = mat.size();
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= i; j--)
                {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n / 2; j++)
                {
                    swap(mat[i][j], mat[i][n - j - 1]);
                }
            }
        }
};