class Solution
{
    public:
        int cal(string & str)
        {
            int n = str.size(), cnt = 0;
            for (int i = 0; i < n / 2; i++)
            {
                if (str[i] != str[n - i - 1])
                    cnt++;
            }
            return cnt;
        }
    int solve(int idx, int k, string &s, vector<vector < int>> &dp)
    {
        if (k == 0)
        {
            if (idx == s.size())
                return 0;
            else
                return 1e5;
        }
        if (idx == s.size())
            return 1e5;
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int ans = 1e5;
        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            str += s[i];
            ans = min(ans, cal(str) + solve(i + 1, k - 1, s, dp));
        }
        return dp[idx][k] = ans;
    }
    int palindromePartition(string s, int k)
    {
        int n = s.size();
        vector<vector < int>> dp(n + 1, vector<int> (k + 1, -1));
        return solve(0, k, s, dp);
    }
};