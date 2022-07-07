class Solution
{
    public:
        int mod = 1e9 + 7;
    vector<vector < int>> dp;
    vector<bool> vis;
    int solve(int idx, int prev, string& s)
    {
        if (idx == s.size())
            return 1;
        if (dp[idx][prev] != -1)
            return dp[idx][prev];
        int ans = 0;
        if (s[idx] == 'D')
        {
            for (int i = prev - 1; i >= 0; i--)
            {
                
                if (!vis[i])
                {
                    vis[i] = 1;
                    ans = ans % mod + solve(idx + 1, i, s) % mod;
                    vis[i] = 0;
                }
            }
        }
        else
        {
            for (int i = prev + 1; i <= s.size(); i++)
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    ans = ans % mod + solve(idx + 1, i, s) % mod;
                    vis[i] = 0;
                }
            }
        }
        return dp[idx][prev] = ans%mod;
    }
    int numPermsDISequence(string s)
    {
        int n = s.size(), ans = 0;
        vis.resize(n + 1, 0);
        dp.resize(n + 1, vector<int> (n + 2, -1));
        for (int i = 0; i <= n; i++)
        {
            vis[i] = 1;
            ans = ans % mod + solve(0, i, s) % mod;
            vis[i] = 0;
        }
        return ans%mod;
    }
};