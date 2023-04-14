class Solution
{
    public:
        int solve(int idx1, int idx2, string &s, string &t, vector<vector < int>> &dp)
        {
            if (idx1 < 0 || idx2 < 0)
                return 0;
            if (dp[idx1][idx2] != -1)
                return dp[idx1][idx2];
            int ans = 0;
            if (s[idx1] == t[idx2])
                ans = 1 + solve(idx1 - 1, idx2 - 1, s, t, dp);
            else
                ans = max(solve(idx1 - 1, idx2, s, t, dp), solve(idx1, idx2 - 1, s, t, dp));
            return dp[idx1][idx2] = ans;
        }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector < int>> dp(n, vector<int> (n, -1));
        return solve(n - 1, n - 1, s, t, dp);
    }
};