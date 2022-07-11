class Solution
{
    public:
        bool solve(int i, int j, string &s1, string &s2, vector<vector < int>> &dp)
        {
            if (i < 0 && j < 0)
                return true;
            if (j < 0)
                return false;
            if (i < 0)
            {
                for (int k = j; k >= 0; k--)
                {
                    if (s2[k] != '*')
                        return false;
                }
                return true;
            }
            if (dp[i][j] != -1)
                return dp[i][j];
            bool ans = false;
            if (s1[i] == s2[j] || s2[j] == '?' || s2[j] == '*')
                ans = solve(i - 1, j - 1, s1, s2, dp);
            if (s2[j] == '*')
            {
               	// if (s2[j] == '?' || s2[j] == '*')
               	//     ans = solve(i - 1, j - 1, s1, s2, dp);

                ans |= (solve(i - 1, j, s1, s2, dp) | solve(i, j - 1, s1, s2, dp));
            }
            return dp[i][j] = ans;
        }
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(m - 1, n - 1, s, p, dp);
    }
};