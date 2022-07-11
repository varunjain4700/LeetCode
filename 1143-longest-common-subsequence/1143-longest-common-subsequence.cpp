class Solution
{
    public:
        int solve(int idx1, int idx2, string &str1, string &str2, int m, int n, vector<vector < int>> &dp)
        {
            if (idx1 == m || idx2 == n)
                return 0;
            if (dp[idx1][idx2] != -1)
                return dp[idx1][idx2];
            int ans = 0;
            if (str1[idx1] == str2[idx2])
                ans = 1 + solve(idx1 + 1, idx2 + 1, str1, str2, m, n, dp);
            else
                ans = max(solve(idx1, idx2 + 1, str1, str2, m, n, dp), solve(idx1 + 1, idx2, str1, str2, m, n, dp));
            return dp[idx1][idx2] = ans;
        }
    int longestCommonSubsequence(string str1, string str2)
    {
        int m = str1.size(), n = str2.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(0, 0, str1, str2, m, n, dp);
    }
};