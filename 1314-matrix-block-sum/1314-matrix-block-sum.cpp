class Solution
{
    public:
       	//Using the concept of range sum query-2d
        vector<vector < int>> matrixBlockSum(vector<vector < int>> &mat, int k)
        {
            int n = mat.size(), m = mat[0].size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mat[i - 1][j - 1] - dp[i - 1][j - 1];
                }
            }
            vector<vector < int>> ans(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int r1 = max(0, i - k);
                    int c1 = max(0, j - k);
                    int r2 = min(n - 1, i + k);
                    int c2 = min(m - 1, j + k);
                    ans[i][j] = dp[r2 + 1][c2 + 1] - dp[r2 + 1][c1] - dp[r1][c2 + 1] + dp[r1][c1];
                }
            }
            return ans;
        }
};