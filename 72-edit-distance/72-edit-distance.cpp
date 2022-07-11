class Solution
{
    public:
        int solve(int idx1, int idx2, string &word1, string &word2, vector<vector < int>> &dp)
        {
            if (idx1 < 0 && idx2 < 0)
                return 0;
            if (idx1 < 0 || idx2 < 0)
                return max(idx1, idx2) + 1;
            if (dp[idx1][idx2] != -1)
                return dp[idx1][idx2];
            int ans = 0;
            if (word1[idx1] == word2[idx2])
                ans = solve(idx1 - 1, idx2 - 1, word1, word2, dp);
            else
            {
                ans = min({ solve(idx1 - 1, idx2, word1, word2, dp),
                    solve(idx1, idx2 - 1, word1, word2, dp),
                    solve(idx1 - 1, idx2 - 1, word1, word2, dp) }) + 1;
            }
            return dp[idx1][idx2] = ans;
        }
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(m - 1, n - 1, word1, word2, dp);
    }
};