class Solution
{
    public:
        bool solve(int i, int j, int m, int n, string& s1, string& s2, string& s3,vector<vector<int>>&dp)
        {
            if (i == m && j == n)
                return true;
            if(dp[i][j]!=-1)
                return dp[i][j];
            if ((i < m && s1[i] == s3[i + j]) && (j < n && s2[j] == s3[i + j]))
            {
                return dp[i][j]=solve(i + 1, j, m, n, s1, s2, s3,dp) || solve(i, j + 1, m, n, s1, s2, s3,dp);
            }
            else if (i < m && s1[i] == s3[i + j])
                return dp[i][j]=solve(i + 1, j, m, n, s1, s2, s3,dp);
            else if (j < n && s2[j] == s3[i + j])
                return dp[i][j]=solve(i, j + 1, m, n, s1, s2, s3,dp);
            return dp[i][j]=false;
        }
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();
        if (s3.size() != m + n)
            return false;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0, 0, m, n, s1, s2, s3,dp);
    }
};