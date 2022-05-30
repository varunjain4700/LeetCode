class Solution
{
    public:
        bool check(string & str)
        {
            int n = str.size();
            for (int i = 0; i < n / 2; i++)
            {
                if (str[i] != str[n - i - 1])
                    return false;
            }
            return true;
        }
    int solve(int idx, string &s, vector<int> &dp)
    {
        if (idx == s.size())
            return -1;
        if (dp[idx] != -1)
            return dp[idx];
        int ans = 1e5;
        string str = "";
        for (int i = idx; i < s.size(); i++)
        {
            str += s[i];
            if (check(str))
            {
                ans = min(ans, 1 + solve(i + 1, s, dp));
            }
        }
        return dp[idx] = ans;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, dp);
    }
};