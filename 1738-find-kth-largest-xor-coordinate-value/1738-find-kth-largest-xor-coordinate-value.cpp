class Solution
{
    public:
        int kthLargestValue(vector<vector < int>> &mat, int k)
        {
            int n = mat.size(), m = mat[0].size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
            priority_queue<int, vector < int>, greater < int>> pq;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ mat[i - 1][j - 1] ^ dp[i - 1][j - 1];
                    pq.push(dp[i][j]);
                    if (pq.size() > k)
                        pq.pop();
                }
            }
            return pq.top();
        }
};