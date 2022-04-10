class NumMatrix
{
    public:
       	//If asked to answer each query in O(n),then it can be done easily using prefix sums(traversing all the rows one by one)
       	// To do it in O(1),need to use a different approach-To understand it see the last approach in solution section
        vector<vector < int>> dp;
    NumMatrix(vector<vector < int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        dp.resize(n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */