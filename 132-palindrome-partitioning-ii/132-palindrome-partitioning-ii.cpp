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
    int solve(int idx, string &str, int n, vector<int> &dp)
    {
        if (idx == n)
            return -1;
        if (dp[idx] != -1)
            return dp[idx];
        int ans = 1e7;
        string s = "";
        for (int i = idx; i < n; i++)
        {
            s += str[i];
            if (check(s))
            {
                int temp = 1 + solve(i + 1, str, n, dp);
                ans = min(ans, temp);
            }
        }
        return dp[idx] = ans;
    }
    int minCut(string str)
    {
        int n = str.size();
        vector<int> dp(n + 1, -1);
        return solve(0, str, n, dp);
    }
};